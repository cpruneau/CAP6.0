# Install script for directory: /Users/aa7526/Documents/GitHub/CAP6.0/src/Exec

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/aa7526/Documents/GitHub/CAP6.0/lib/libExec.rootmap;/Users/aa7526/Documents/GitHub/CAP6.0/lib/libExec_rdict.pcm")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/Users/aa7526/Documents/GitHub/CAP6.0/lib" TYPE FILE FILES
    "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/Exec/libExec.rootmap"
    "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/Exec/libExec_rdict.pcm"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/Users/aa7526/Documents/GitHub/CAP6.0/lib/libExec.dylib")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/Users/aa7526/Documents/GitHub/CAP6.0/lib" TYPE SHARED_LIBRARY FILES "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/Exec/libExec.dylib")
  if(EXISTS "$ENV{DESTDIR}/Users/aa7526/Documents/GitHub/CAP6.0/lib/libExec.dylib" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/Users/aa7526/Documents/GitHub/CAP6.0/lib/libExec.dylib")
    execute_process(COMMAND /usr/bin/install_name_tool
      -delete_rpath "/Users/aa7526/opt/root_install/lib"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/Global"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/Spherocity"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/ParticlePair3D"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/Jets"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/NuDyn"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/PtPt"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/Performance"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/SubSample"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/CAPPythia"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/Therminator"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/ParticlePair"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/ParticleSingle"
      -delete_rpath "/Users/aa7526/opt/Pythia/pythia8307/lib"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/Particles"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/ParticleDb"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/Xml"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/Math"
      -delete_rpath "/Users/aa7526/Documents/GitHub/CAP6.0/homeBuild/Base"
      "$ENV{DESTDIR}/Users/aa7526/Documents/GitHub/CAP6.0/lib/libExec.dylib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/strip" -x "$ENV{DESTDIR}/Users/aa7526/Documents/GitHub/CAP6.0/lib/libExec.dylib")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

