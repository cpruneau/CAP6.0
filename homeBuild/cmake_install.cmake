# Install script for directory: /Users/aa7526/Documents/GitHub/CAP6.1/src

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/Base/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/Math/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/Xml/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/ParticleDb/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/Particles/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/Therminator/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/SubSample/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/CAPPythia/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/Global/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/Spherocity/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/ParticleSingle/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/ParticlePair/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/ParticlePair3D/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/NuDyn/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/PtPt/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/Performance/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/Jets/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/Plotting/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/Exec/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/aa7526/Documents/GitHub/CAP6.1/homeBuild/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
