# Install script for directory: D:/SFML-2.5.1/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "D:/SFML-2.5.1/SFML-build")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
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
  set(CMAKE_OBJDUMP "C:/msys64/mingw64/bin/objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/SFML-2.5.1/SFML-build/examples/ftp/cmake_install.cmake")
  include("D:/SFML-2.5.1/SFML-build/examples/sockets/cmake_install.cmake")
  include("D:/SFML-2.5.1/SFML-build/examples/voip/cmake_install.cmake")
  include("D:/SFML-2.5.1/SFML-build/examples/sound/cmake_install.cmake")
  include("D:/SFML-2.5.1/SFML-build/examples/sound_capture/cmake_install.cmake")
  include("D:/SFML-2.5.1/SFML-build/examples/window/cmake_install.cmake")
  include("D:/SFML-2.5.1/SFML-build/examples/joystick/cmake_install.cmake")
  include("D:/SFML-2.5.1/SFML-build/examples/opengl/cmake_install.cmake")
  include("D:/SFML-2.5.1/SFML-build/examples/shader/cmake_install.cmake")
  include("D:/SFML-2.5.1/SFML-build/examples/island/cmake_install.cmake")
  include("D:/SFML-2.5.1/SFML-build/examples/win32/cmake_install.cmake")
  include("D:/SFML-2.5.1/SFML-build/examples/pong/cmake_install.cmake")

endif()

