# This file is part of the FirelandsCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

cmake_minimum_required(VERSION 3.18)

# add this options before PROJECT keyword
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# Set projectname (must be done AFTER setting configurationtypes)
project(FirelandsCore VERSION 1.0.0)

# CMake policies (can not be handled elsewhere)
cmake_policy(SET CMP0005 NEW)
if (CMAKE_VERSION VERSION_LESS "3.16.0")
  cmake_policy(SET CMP0043 OLD) # Disable 'Ignore COMPILE_DEFINITIONS_<Config> properties'
else()
  cmake_policy(SET CMP0043 NEW) # Cotire isn't used so set to NEW
endif()
cmake_policy(SET CMP0054 NEW) # Only interpret if() arguments as variables or keywords when unquoted - prevents intepreting if (SOME_STRING_VARIABLE MATCHES "MSVC") as if (SOME_STRING_VARIABLE MATCHES "1")

if(POLICY CMP0074)
  cmake_policy(SET CMP0074 NEW) # find_package() uses <PackageName>_ROOT variables
endif()

# Set RPATH-handing (CMake parameters)
set(CMAKE_SKIP_BUILD_RPATH 0)
set(CMAKE_BUILD_WITH_INSTALL_RPATH 0)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH 1)

# set macro-directory
list(APPEND CMAKE_MODULE_PATH
  "${CMAKE_SOURCE_DIR}/cmake/macros")

include(cmake/utils.cmake)

if (CMAKE_VERSION VERSION_LESS "3.16.0")
  list(APPEND CMAKE_MODULE_PATH
          "${CMAKE_SOURCE_DIR}/deps/cotire/CMake")
endif()

# build in Release-mode by default if not explicitly set
if(CMAKE_GENERATOR STREQUAL "Ninja Multi-Config")
  set(CMAKE_DEFAULT_BUILD_TYPE "RelWithDebInfo" CACHE INTERNAL "")
endif()

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

#Add Utils For Cmake

include(CheckCXXSourceRuns)
include(CheckIncludeFiles)
include(ConfigureScripts)
include(ConfigureModules)

# set default buildoptions and print them
include(cmake/options.cmake)

# turn off PCH totally if enabled (hidden setting, mainly for devs)
if( NOPCH )
  set(USE_COREPCH 0)
  set(USE_SCRIPTPCH 0)
endif()

include(ConfigureBaseTargets)
include(CheckPlatform)

include(GroupSources)
include(AutoCollect)
include(ConfigInstall)

find_package(PCHSupport)
find_package(MySQL)

if(NOT WITHOUT_GIT)
  find_package(Git 1.7)
endif()

# Find revision ID and hash of the sourcetree
include(cmake/genrev.cmake)

# print out the results before continuing
include(cmake/showoptions.cmake)

# add modules and dependencies
FC_SUBDIRLIST(sub_DIRS  "${CMAKE_SOURCE_DIR}/mods" FALSE FALSE)
FOREACH(subdir ${sub_DIRS})

    get_filename_component(MODULENAME ${subdir} NAME)

    if (";${DISABLED_FC_MODULES};" MATCHES ";${MODULENAME};")
        continue()
    endif()

    STRING(REPLACE "${CMAKE_SOURCE_DIR}/" "" subdir_rel ${subdir})
    if(EXISTS "${subdir}/CMakeLists.txt")
        add_subdirectory("${subdir_rel}")
    endif()
ENDFOREACH()
FC_RUN_HOOK("AFTER_LOAD_CONF")


# add dependencies
add_subdirectory(deps)

# add core sources
add_subdirectory(src)

if(SERVERS)
  # add custom mods
  add_subdirectory(mods)
endif()

include(CTest)
if(BUILD_TESTING)
  list(APPEND CMAKE_MODULE_PATH
    "${Catch2_SOURCE_DIR}/contrib")
  include(Catch)

  add_subdirectory(tests)
endif()
