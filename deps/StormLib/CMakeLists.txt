set(SRC_FILES
    src/adpcm/adpcm.cpp
    src/adpcm/adpcm.cpp
    src/huffman/huff.cpp
    src/jenkins/lookup3.c
    src/lzma/C/LzFind.c
    src/lzma/C/LzmaDec.c
    src/lzma/C/LzmaEnc.c
    src/pklib/explode.c
    src/pklib/implode.c
    src/sparse/sparse.cpp
    src/FileStream.cpp
    src/SBaseCommon.cpp
    src/SBaseFileTable.cpp
    src/SCompression.cpp
    src/SFileAddFile.cpp
    src/SFileAttributes.cpp
    src/SFileCompactArchive.cpp
    src/SFileCreateArchive.cpp
    src/SFileExtractFile.cpp
    src/SFileFindFile.cpp
    src/SFileListFile.cpp
    src/SFileOpenArchive.cpp
    src/SFileOpenFileEx.cpp
    src/SFilePatchArchives.cpp
    src/SFileReadFile.cpp
    src/SFileVerify.cpp
)

set(TOMCRYPT_FILES
    src/libtomcrypt/src/hashes/hash_memory.c
    src/libtomcrypt/src/hashes/md5.c
    src/libtomcrypt/src/hashes/sha1.c
    src/libtomcrypt/src/math/ltm_desc.c
    src/libtomcrypt/src/math/multi.c
    src/libtomcrypt/src/math/rand_prime.c
    src/libtomcrypt/src/misc/base64_decode.c
    src/libtomcrypt/src/misc/crypt_argchk.c
    src/libtomcrypt/src/misc/crypt_find_hash.c
    src/libtomcrypt/src/misc/crypt_find_prng.c
    src/libtomcrypt/src/misc/crypt_hash_descriptor.c
    src/libtomcrypt/src/misc/crypt_hash_is_valid.c
    src/libtomcrypt/src/misc/crypt_libc.c
    src/libtomcrypt/src/misc/crypt_ltc_mp_descriptor.c
    src/libtomcrypt/src/misc/crypt_prng_descriptor.c
    src/libtomcrypt/src/misc/crypt_prng_is_valid.c
    src/libtomcrypt/src/misc/crypt_register_hash.c
    src/libtomcrypt/src/misc/crypt_register_prng.c
    src/libtomcrypt/src/misc/zeromem.c
    src/libtomcrypt/src/pk/asn1/der_decode_bit_string.c
    src/libtomcrypt/src/pk/asn1/der_decode_boolean.c
    src/libtomcrypt/src/pk/asn1/der_decode_choice.c
    src/libtomcrypt/src/pk/asn1/der_decode_ia5_string.c
    src/libtomcrypt/src/pk/asn1/der_decode_integer.c
    src/libtomcrypt/src/pk/asn1/der_decode_object_identifier.c
    src/libtomcrypt/src/pk/asn1/der_decode_octet_string.c
    src/libtomcrypt/src/pk/asn1/der_decode_printable_string.c
    src/libtomcrypt/src/pk/asn1/der_decode_sequence_ex.c
    src/libtomcrypt/src/pk/asn1/der_decode_sequence_flexi.c
    src/libtomcrypt/src/pk/asn1/der_decode_sequence_multi.c
    src/libtomcrypt/src/pk/asn1/der_decode_short_integer.c
    src/libtomcrypt/src/pk/asn1/der_decode_utctime.c
    src/libtomcrypt/src/pk/asn1/der_decode_utf8_string.c
    src/libtomcrypt/src/pk/asn1/der_length_bit_string.c
    src/libtomcrypt/src/pk/asn1/der_length_boolean.c
    src/libtomcrypt/src/pk/asn1/der_length_ia5_string.c
    src/libtomcrypt/src/pk/asn1/der_length_integer.c
    src/libtomcrypt/src/pk/asn1/der_length_object_identifier.c
    src/libtomcrypt/src/pk/asn1/der_length_octet_string.c
    src/libtomcrypt/src/pk/asn1/der_length_printable_string.c
    src/libtomcrypt/src/pk/asn1/der_length_sequence.c
    src/libtomcrypt/src/pk/asn1/der_length_utctime.c
    src/libtomcrypt/src/pk/asn1/der_sequence_free.c
    src/libtomcrypt/src/pk/asn1/der_length_utf8_string.c
    src/libtomcrypt/src/pk/asn1/der_length_short_integer.c
    src/libtomcrypt/src/pk/ecc/ltc_ecc_map.c
    src/libtomcrypt/src/pk/ecc/ltc_ecc_mul2add.c
    src/libtomcrypt/src/pk/ecc/ltc_ecc_mulmod.c
    src/libtomcrypt/src/pk/ecc/ltc_ecc_points.c
    src/libtomcrypt/src/pk/ecc/ltc_ecc_projective_add_point.c
    src/libtomcrypt/src/pk/ecc/ltc_ecc_projective_dbl_point.c
    src/libtomcrypt/src/pk/pkcs1/pkcs_1_mgf1.c
    src/libtomcrypt/src/pk/pkcs1/pkcs_1_oaep_decode.c
    src/libtomcrypt/src/pk/pkcs1/pkcs_1_pss_decode.c
    src/libtomcrypt/src/pk/pkcs1/pkcs_1_v1_5_decode.c
    src/libtomcrypt/src/pk/rsa/rsa_exptmod.c
    src/libtomcrypt/src/pk/rsa/rsa_free.c
    src/libtomcrypt/src/pk/rsa/rsa_import.c
    src/libtomcrypt/src/pk/rsa/rsa_make_key.c
    src/libtomcrypt/src/pk/rsa/rsa_verify_hash.c
    src/libtomcrypt/src/pk/rsa/rsa_verify_simple.c
)

set(TOMMATH_FILES
    src/libtommath/bncore.c
    src/libtommath/bn_fast_mp_invmod.c
    src/libtommath/bn_fast_mp_montgomery_reduce.c
    src/libtommath/bn_fast_s_mp_mul_digs.c
    src/libtommath/bn_fast_s_mp_mul_high_digs.c
    src/libtommath/bn_fast_s_mp_sqr.c
    src/libtommath/bn_mp_2expt.c
    src/libtommath/bn_mp_abs.c
    src/libtommath/bn_mp_add.c
    src/libtommath/bn_mp_addmod.c
    src/libtommath/bn_mp_add_d.c
    src/libtommath/bn_mp_and.c
    src/libtommath/bn_mp_clamp.c
    src/libtommath/bn_mp_clear.c
    src/libtommath/bn_mp_clear_multi.c
    src/libtommath/bn_mp_cmp.c
    src/libtommath/bn_mp_cmp_d.c
    src/libtommath/bn_mp_cmp_mag.c
    src/libtommath/bn_mp_cnt_lsb.c
    src/libtommath/bn_mp_copy.c
    src/libtommath/bn_mp_count_bits.c
    src/libtommath/bn_mp_div.c
    src/libtommath/bn_mp_div_2.c
    src/libtommath/bn_mp_div_2d.c
    src/libtommath/bn_mp_div_3.c
    src/libtommath/bn_mp_div_d.c
    src/libtommath/bn_mp_dr_is_modulus.c
    src/libtommath/bn_mp_dr_reduce.c
    src/libtommath/bn_mp_dr_setup.c
    src/libtommath/bn_mp_exch.c
    src/libtommath/bn_mp_exptmod.c
    src/libtommath/bn_mp_exptmod_fast.c
    src/libtommath/bn_mp_expt_d.c
    src/libtommath/bn_mp_exteuclid.c
    src/libtommath/bn_mp_fread.c
    src/libtommath/bn_mp_fwrite.c
    src/libtommath/bn_mp_gcd.c
    src/libtommath/bn_mp_get_int.c
    src/libtommath/bn_mp_grow.c
    src/libtommath/bn_mp_init.c
    src/libtommath/bn_mp_init_copy.c
    src/libtommath/bn_mp_init_multi.c
    src/libtommath/bn_mp_init_set.c
    src/libtommath/bn_mp_init_set_int.c
    src/libtommath/bn_mp_init_size.c
    src/libtommath/bn_mp_invmod.c
    src/libtommath/bn_mp_invmod_slow.c
    src/libtommath/bn_mp_is_square.c
    src/libtommath/bn_mp_jacobi.c
    src/libtommath/bn_mp_karatsuba_mul.c
    src/libtommath/bn_mp_karatsuba_sqr.c
    src/libtommath/bn_mp_lcm.c
    src/libtommath/bn_mp_lshd.c
    src/libtommath/bn_mp_mod.c
    src/libtommath/bn_mp_mod_2d.c
    src/libtommath/bn_mp_mod_d.c
    src/libtommath/bn_mp_montgomery_calc_normalization.c
    src/libtommath/bn_mp_montgomery_reduce.c
    src/libtommath/bn_mp_montgomery_setup.c
    src/libtommath/bn_mp_mul.c
    src/libtommath/bn_mp_mulmod.c
    src/libtommath/bn_mp_mul_2.c
    src/libtommath/bn_mp_mul_2d.c
    src/libtommath/bn_mp_mul_d.c
    src/libtommath/bn_mp_neg.c
    src/libtommath/bn_mp_n_root.c
    src/libtommath/bn_mp_or.c
    src/libtommath/bn_mp_prime_fermat.c
    src/libtommath/bn_mp_prime_is_divisible.c
    src/libtommath/bn_mp_prime_is_prime.c
    src/libtommath/bn_mp_prime_miller_rabin.c
    src/libtommath/bn_mp_prime_next_prime.c
    src/libtommath/bn_mp_prime_rabin_miller_trials.c
    src/libtommath/bn_mp_prime_random_ex.c
    src/libtommath/bn_mp_radix_size.c
    src/libtommath/bn_mp_radix_smap.c
    src/libtommath/bn_mp_rand.c
    src/libtommath/bn_mp_read_radix.c
    src/libtommath/bn_mp_read_signed_bin.c
    src/libtommath/bn_mp_read_unsigned_bin.c
    src/libtommath/bn_mp_reduce.c
    src/libtommath/bn_mp_reduce_2k.c
    src/libtommath/bn_mp_reduce_2k_l.c
    src/libtommath/bn_mp_reduce_2k_setup.c
    src/libtommath/bn_mp_reduce_2k_setup_l.c
    src/libtommath/bn_mp_reduce_is_2k.c
    src/libtommath/bn_mp_reduce_is_2k_l.c
    src/libtommath/bn_mp_reduce_setup.c
    src/libtommath/bn_mp_rshd.c
    src/libtommath/bn_mp_set.c
    src/libtommath/bn_mp_set_int.c
    src/libtommath/bn_mp_shrink.c
    src/libtommath/bn_mp_signed_bin_size.c
    src/libtommath/bn_mp_sqr.c
    src/libtommath/bn_mp_sqrmod.c
    src/libtommath/bn_mp_sqrt.c
    src/libtommath/bn_mp_sub.c
    src/libtommath/bn_mp_submod.c
    src/libtommath/bn_mp_sub_d.c
    src/libtommath/bn_mp_toom_mul.c
    src/libtommath/bn_mp_toom_sqr.c
    src/libtommath/bn_mp_toradix.c
    src/libtommath/bn_mp_toradix_n.c
    src/libtommath/bn_mp_to_signed_bin.c
    src/libtommath/bn_mp_to_signed_bin_n.c
    src/libtommath/bn_mp_to_unsigned_bin.c
    src/libtommath/bn_mp_to_unsigned_bin_n.c
    src/libtommath/bn_mp_unsigned_bin_size.c
    src/libtommath/bn_mp_xor.c
    src/libtommath/bn_mp_zero.c
    src/libtommath/bn_prime_tab.c
    src/libtommath/bn_reverse.c
    src/libtommath/bn_s_mp_add.c
    src/libtommath/bn_s_mp_exptmod.c
    src/libtommath/bn_s_mp_mul_digs.c
    src/libtommath/bn_s_mp_mul_high_digs.c
    src/libtommath/bn_s_mp_sqr.c
    src/libtommath/bn_s_mp_sub.c
)

set(TEST_SRC_FILES
    test/Test.cpp
)

add_definitions(-D_7ZIP_ST -DBZ_STRICT_ANSI)
add_definitions(-D__SYS_ZLIB -D__SYS_BZLIB)

if(WIN32)
    if(MSVC)
        add_definitions(-D_7ZIP_ST -DWIN32)
    endif()
    set(SRC_ADDITIONAL_FILES ${TOMCRYPT_FILES} ${TOMMATH_FILES})
    set(LINK_LIBS wininet)
endif()

if(APPLE)
    set(SRC_ADDITIONAL_FILES ${TOMCRYPT_FILES} ${TOMMATH_FILES})
endif()

if (${CMAKE_SYSTEM_NAME} STREQUAL Linux)
    option(WITH_LIBTOMCRYPT "Use system LibTomCrypt library" OFF)
    if(WITH_LIBTOMCRYPT)
        set(LINK_LIBS tomcrypt)
    else()
        set(SRC_ADDITIONAL_FILES ${TOMCRYPT_FILES} ${TOMMATH_FILES})
    endif()
endif()

add_library(storm STATIC ${SRC_FILES} ${SRC_ADDITIONAL_FILES})

set_target_properties(storm PROPERTIES LINKER_LANGUAGE CXX)

if(UNIX)
    set_target_properties(storm PROPERTIES SOVERSION 0)
endif()

# On Win32, build StormLib.dll since we don't want to clash with Storm.dll
if(WIN32)
    set_target_properties(storm PROPERTIES OUTPUT_NAME StormLib)
endif()

target_include_directories(storm
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/deps/zlib
    ${CMAKE_SOURCE_DIR}/deps/bzip2)

target_link_libraries(storm
  PRIVATE
    fc-dependency-interface
  PUBLIC
    zlib
    bzip2
    ${LINK_LIBS})

set_target_properties(storm
  PROPERTIES
    FOLDER
      "deps")
