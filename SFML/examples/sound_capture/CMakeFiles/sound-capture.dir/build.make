# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\phamt\scoop\apps\cmake\3.26.1\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\phamt\scoop\apps\cmake\3.26.1\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\SFML-2.5.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\SFML-2.5.1\SFML-build

# Include any dependencies generated for this target.
include examples/sound_capture/CMakeFiles/sound-capture.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/sound_capture/CMakeFiles/sound-capture.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/sound_capture/CMakeFiles/sound-capture.dir/progress.make

# Include the compile flags for this target's objects.
include examples/sound_capture/CMakeFiles/sound-capture.dir/flags.make

examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj: examples/sound_capture/CMakeFiles/sound-capture.dir/flags.make
examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj: examples/sound_capture/CMakeFiles/sound-capture.dir/includes_CXX.rsp
examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj: D:/SFML-2.5.1/examples/sound_capture/SoundCapture.cpp
examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj: examples/sound_capture/CMakeFiles/sound-capture.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\SFML-2.5.1\SFML-build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj"
	cd /d D:\SFML-2.5.1\SFML-build\examples\sound_capture && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj -MF CMakeFiles\sound-capture.dir\SoundCapture.cpp.obj.d -o CMakeFiles\sound-capture.dir\SoundCapture.cpp.obj -c D:\SFML-2.5.1\examples\sound_capture\SoundCapture.cpp

examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sound-capture.dir/SoundCapture.cpp.i"
	cd /d D:\SFML-2.5.1\SFML-build\examples\sound_capture && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\SFML-2.5.1\examples\sound_capture\SoundCapture.cpp > CMakeFiles\sound-capture.dir\SoundCapture.cpp.i

examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sound-capture.dir/SoundCapture.cpp.s"
	cd /d D:\SFML-2.5.1\SFML-build\examples\sound_capture && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\SFML-2.5.1\examples\sound_capture\SoundCapture.cpp -o CMakeFiles\sound-capture.dir\SoundCapture.cpp.s

# Object files for target sound-capture
sound__capture_OBJECTS = \
"CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj"

# External object files for target sound-capture
sound__capture_EXTERNAL_OBJECTS =

examples/sound_capture/sound-capture.exe: examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj
examples/sound_capture/sound-capture.exe: examples/sound_capture/CMakeFiles/sound-capture.dir/build.make
examples/sound_capture/sound-capture.exe: lib/libsfml-audio.a
examples/sound_capture/sound-capture.exe: lib/libsfml-system.a
examples/sound_capture/sound-capture.exe: examples/sound_capture/CMakeFiles/sound-capture.dir/linkLibs.rsp
examples/sound_capture/sound-capture.exe: examples/sound_capture/CMakeFiles/sound-capture.dir/objects1.rsp
examples/sound_capture/sound-capture.exe: examples/sound_capture/CMakeFiles/sound-capture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\SFML-2.5.1\SFML-build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sound-capture.exe"
	cd /d D:\SFML-2.5.1\SFML-build\examples\sound_capture && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sound-capture.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/sound_capture/CMakeFiles/sound-capture.dir/build: examples/sound_capture/sound-capture.exe
.PHONY : examples/sound_capture/CMakeFiles/sound-capture.dir/build

examples/sound_capture/CMakeFiles/sound-capture.dir/clean:
	cd /d D:\SFML-2.5.1\SFML-build\examples\sound_capture && $(CMAKE_COMMAND) -P CMakeFiles\sound-capture.dir\cmake_clean.cmake
.PHONY : examples/sound_capture/CMakeFiles/sound-capture.dir/clean

examples/sound_capture/CMakeFiles/sound-capture.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\SFML-2.5.1 D:\SFML-2.5.1\examples\sound_capture D:\SFML-2.5.1\SFML-build D:\SFML-2.5.1\SFML-build\examples\sound_capture D:\SFML-2.5.1\SFML-build\examples\sound_capture\CMakeFiles\sound-capture.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : examples/sound_capture/CMakeFiles/sound-capture.dir/depend

