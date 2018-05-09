# Install script for directory: /home/adrian/Projects/CPlusPlus17/src/new

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

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/1/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/2/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/3/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/4/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/5/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/6/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/7/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/8/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/9/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/10/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/11/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/13/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/14/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/15/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/16/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/17/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/18/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/19/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/20/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/21/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/22/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/23/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/24/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/25/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/26/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/27/cmake_install.cmake")
  include("/home/adrian/Projects/CPlusPlus17/build/src/new/28/cmake_install.cmake")

endif()

