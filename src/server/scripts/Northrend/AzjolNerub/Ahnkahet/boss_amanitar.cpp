/*
 * This file is part of the FirelandsCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Affero General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "ahnkahet.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_BASH                                    = 57094, // Victim
    SPELL_ENTANGLING_ROOTS                        = 57095, // Random Victim 100Y
    SPELL_MINI                                    = 57055, // Self
    SPELL_VENOM_BOLT_VOLLEY                       = 57088, // Random Victim 100Y
    SPELL_HEALTHY_MUSHROOM_POTENT_FUNGUS          = 56648, // Killer 3Y
    SPELL_POISONOUS_MUSHROOM_POISON_CLOUD         = 57061, // Self - Duration 8 Sec
    SPELL_POISONOUS_MUSHROOM_VISUAL_AREA          = 61566, // Self
    SPELL_POISONOUS_MUSHROOM_VISUAL_AURA          = 56741, // Self
    SPELL_PUTRID_MUSHROOM                         = 31690, // To make the mushrooms visible
    SPELL_POWER_MUSHROOM_VISUAL_AURA              = 56740,
};

enum Creatures
{
    NPC_TRIGGER                                     = 19656
};

enum Events
{
    EVENT_SPAWN = 1,
    EVENT_MINI,
    EVENT_ROOT,
    EVENT_BASH,
    EVENT_BOLT,
    EVENT_AURA
};

class boss_amanitar : public CreatureScript
{
    public:
        boss_amanitar() : CreatureScript("boss_amanitar") { }

        struct boss_amanitarAI : public BossAI
        {
            boss_amanitarAI(Creature* creature) : BossAI(creature, DATA_AMANITAR) { }

            void Reset() override
            {
                _Reset();
                me->SetMeleeDamageSchool(SPELL_SCHOOL_NATURE);
                me->ApplySpellImmune(0, IMMUNITY_SCHOOL, SPELL_SCHOOL_MASK_NATURE, true);
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);

                events.ScheduleEvent(EVENT_ROOT, urand(5, 9) * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_BASH, urand(10, 14) * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_BOLT, urand(15, 20) * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_MINI, urand(12, 18) * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SPAWN, 5  * IN_MILLISECONDS);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_MINI);
            }

            void SpawnAdds()
            {
                uint8 u = 0;

                for (uint8 i = 0; i < 30; ++i)
                {
                    Position pos = me->GetRandomNearPosition(30.0f);
                    me->UpdateGroundPositionZ(pos.m_positionX, pos.m_positionY, pos.m_positionZ);

                    if (Creature* trigger = me->SummonCreature(NPC_TRIGGER, pos))
                    {
                        Creature* temp1 = trigger->FindNearestCreature(NPC_HEALTHY_MUSHROOM, 4.0f, true);
                        Creature* temp2 = trigger->FindNearestCreature(NPC_POISONOUS_MUSHROOM, 4.0f, true);
                        if (temp1 || temp2)
                        {
                            trigger->DisappearAndDie();
                        }
                        else
                        {
                            u = 1 - u;
                            trigger->DisappearAndDie();
                            me->SummonCreature(u > 0 ? NPC_POISONOUS_MUSHROOM : NPC_HEALTHY_MUSHROOM, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 60 * IN_MILLISECONDS);
                        }
                    }
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SPAWN:
                            SpawnAdds();
                            events.ScheduleEvent(EVENT_SPAWN, 20 * IN_MILLISECONDS);
                            break;
                        case EVENT_MINI:
                            DoCast(SPELL_MINI);
                            events.ScheduleEvent(EVENT_MINI, urand(25, 30) * IN_MILLISECONDS);
                            break;
                        case EVENT_ROOT:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_ENTANGLING_ROOTS, true);
                            events.ScheduleEvent(EVENT_ROOT, urand(10, 15) * IN_MILLISECONDS);
                            break;
                        case EVENT_BASH:
                            DoCastVictim(SPELL_BASH);
                            events.ScheduleEvent(EVENT_BASH, urand(7, 12) * IN_MILLISECONDS);
                            break;
                        case EVENT_BOLT:
                            DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true), SPELL_VENOM_BOLT_VOLLEY, true);
                            events.ScheduleEvent(EVENT_BOLT, urand(18, 22) * IN_MILLISECONDS);
                            break;
                        default:
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAhnKahetAI<boss_amanitarAI>(creature);
        }
};

class npc_amanitar_mushrooms : public CreatureScript
{
public:
    npc_amanitar_mushrooms() : CreatureScript("npc_amanitar_mushrooms") { }

    struct npc_amanitar_mushroomsAI : public ScriptedAI
    {
        npc_amanitar_mushroomsAI(Creature* creature) : ScriptedAI(creature) { }

        EventMap events;

        void Reset() override
        {
            events.Reset();
            events.ScheduleEvent(EVENT_AURA, 1 * IN_MILLISECONDS);

            me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
            DoCast(SPELL_PUTRID_MUSHROOM);

            if (me->GetEntry() == NPC_POISONOUS_MUSHROOM)
                DoCast(SPELL_POISONOUS_MUSHROOM_VISUAL_AURA);
            else
                DoCast(SPELL_POWER_MUSHROOM_VISUAL_AURA);
        }

        void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
        {
            if (damage >= me->GetHealth() && me->GetEntry() == NPC_HEALTHY_MUSHROOM)
                DoCast(me, SPELL_HEALTHY_MUSHROOM_POTENT_FUNGUS, true);
        }

        void JustEngagedWith(Unit* /*who*/) override { }
        void AttackStart(Unit* /*victim*/) override { }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_AURA:
                        if (me->GetEntry() == NPC_POISONOUS_MUSHROOM)
                        {
                            DoCast(me, SPELL_POISONOUS_MUSHROOM_VISUAL_AREA, true);
                            DoCast(me, SPELL_POISONOUS_MUSHROOM_POISON_CLOUD);
                        }
                        events.ScheduleEvent(EVENT_AURA, 7 * IN_MILLISECONDS);
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetAhnKahetAI<npc_amanitar_mushroomsAI>(creature);
    }
};

void AddSC_boss_amanitar()
{
    new boss_amanitar();
    new npc_amanitar_mushrooms();
}
