################################################################################################
#
# CMakeLists.txt for CAP package. Version 6.1
#
# Creates  libraries with dictionary
#
################################################################################################

if(APPLE)
    cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
    set (CMAKE_OSX_DEPLOYMENT_TARGET "15.0" CACHE STRING "Minimum OS X deployment version" FORCE)
    project(CAP VERSION 1.0 DESCRIPTION "Correlation Analysis Package" LANGUAGES CXX)
#    set (CMAKE_OSX_ARCHITECTURES "x86_64;arm64" CACHE STRING "Architectures" FORCE)
#    set (CMAKE_XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET[arch=arm64] "11.0" CACHE STRING "arm 64 minimum deployment target" FORCE)
else()
 cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
 cmake_policy(SET CMP0048 NEW)
 project(CAP DESCRIPTION "Correlation Analysis Package" LANGUAGES CXX)
endif()

################################################################################################
# Project CAP
################################################################################################
set(CMAKE_CXX_STANDARD 14)
####set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CAP_ROOT_PATH "$ENV{CAP_ROOT_PATH}")

################################################################################################
# You need to tell CMake where to find the ROOT installation. This can be done in a number of ways:
#   - ROOT built with classic configure/make use the provided $ROOTSYS/etc/cmake/FindROOT.cmake
#   - ROOT built with CMake. Add in CMAKE_PREFIX_PATH the installation prefix for ROOT
################################################################################################
list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

################################################################################################
#---Locate the ROOT package and defines a number of variables (e.g. ROOT_INCLUDE_DIRS)
################################################################################################
find_package(ROOT REQUIRED COMPONENTS EG MathCore MathMore RIO Hist Tree Net )
find_library(PYTHIA8_LIB pythia8 PATHS $ENV{PYTHIA8_LIB_PATH})
find_library(FASTJET_LIB fastjet PATHS $ENV{DYLD_LIBRARY_PATH} )

################################################################################################
# Define useful ROOT functions and macros (e.g. ROOT_GENERATE_DICTIONARY)
################################################################################################
include(${ROOT_USE_FILE})
include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS} "Base" "Math" "Xml" "ParticleDb" "Particles"  "SubSample"  "CAPPythia"  "Global" "Jets" "Spherocity" "ParticleSingle" "ParticlePair" "ParticlePair3D" "NuDyn" "PtPt"  "Plotting" "Therminator"  "Performance" "Exec" "BasicEventGen" "$ENV{ROOTSYS}/include"
"$ENV{FASTJET_INCLUDE_PATH}" "$ENV{PYTHIA8_INCLUDE_PATH}" "$ENV{PYTHIA8_INCLUDE_PATH}/Pythia8/" )
add_definitions(${ROOT_CXX_FLAGS})
add_compile_options(-Wall -Wextra -pedantic)
add_library(EG SHARED IMPORTED)
add_library(PYTHIA8_LIB SHARED IMPORTED)
set_target_properties(PYTHIA8_LIB PROPERTIES IMPORTED_LOCATION ${PYTHIA8_LIB})
add_library(FASTJET_LIB SHARED IMPORTED)
set_target_properties(FASTJET_LIB PROPERTIES IMPORTED_LOCATION ${FASTJET_LIB})

add_subdirectory(Base)
add_subdirectory(Math)
add_subdirectory(Xml)
add_subdirectory(ParticleDb)
add_subdirectory(Particles)
add_subdirectory(Therminator)
add_subdirectory(SubSample)
add_subdirectory(CAPPythia)
add_subdirectory(Global)
add_subdirectory(Spherocity)
add_subdirectory(ParticleSingle)
add_subdirectory(ParticlePair)
add_subdirectory(ParticlePair3D)
add_subdirectory(NuDyn)
add_subdirectory(PtPt)
add_subdirectory(Performance)
add_subdirectory(Jets)
add_subdirectory(BasicEventGen)
#add_subdirectory(ThermalGas)
#add_subdirectory(CollGeom)
#add_subdirectory(Epos)
#add_subdirectory(Urqmd)
#add_subdirectory(Ampt)
#add_subdirectory(Hijing)
#add_subdirectory(Herwig)
#add_subdirectory(Blastwave)
#add_subdirectory(Identity)
add_subdirectory(Plotting)
add_subdirectory(Exec)
