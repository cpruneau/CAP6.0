# Install script for directory: /Users/aa7526/Documents/GitHub/CAP7.0/src

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

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/Base/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/Math/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/Xml/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/ParticleDb/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/Particles/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/Therminator/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/SubSample/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/CAPPythia/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/Global/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/Spherocity/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/ParticleSingle/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/ParticlePair/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/ParticlePair3D/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/NuDyn/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/PtPt/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/Performance/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/Jets/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/BasicEventGen/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/Plotting/cmake_install.cmake")
  include("/Users/aa7526/Documents/GitHub/CAP7.0/wsu/Exec/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
  file(WRITE "/Users/aa7526/Documents/GitHub/CAP7.0/wsu/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
