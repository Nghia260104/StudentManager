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
include examples/shader/CMakeFiles/shader.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/shader/CMakeFiles/shader.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/shader/CMakeFiles/shader.dir/progress.make

# Include the compile flags for this target's objects.
include examples/shader/CMakeFiles/shader.dir/flags.make

examples/shader/CMakeFiles/shader.dir/Shader.cpp.obj: examples/shader/CMakeFiles/shader.dir/flags.make
examples/shader/CMakeFiles/shader.dir/Shader.cpp.obj: examples/shader/CMakeFiles/shader.dir/includes_CXX.rsp
examples/shader/CMakeFiles/shader.dir/Shader.cpp.obj: D:/SFML-2.5.1/examples/shader/Shader.cpp
examples/shader/CMakeFiles/shader.dir/Shader.cpp.obj: examples/shader/CMakeFiles/shader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\SFML-2.5.1\SFML-build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/shader/CMakeFiles/shader.dir/Shader.cpp.obj"
	cd /d D:\SFML-2.5.1\SFML-build\examples\shader && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/shader/CMakeFiles/shader.dir/Shader.cpp.obj -MF CMakeFiles\shader.dir\Shader.cpp.obj.d -o CMakeFiles\shader.dir\Shader.cpp.obj -c D:\SFML-2.5.1\examples\shader\Shader.cpp

examples/shader/CMakeFiles/shader.dir/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shader.dir/Shader.cpp.i"
	cd /d D:\SFML-2.5.1\SFML-build\examples\shader && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\SFML-2.5.1\examples\shader\Shader.cpp > CMakeFiles\shader.dir\Shader.cpp.i

examples/shader/CMakeFiles/shader.dir/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shader.dir/Shader.cpp.s"
	cd /d D:\SFML-2.5.1\SFML-build\examples\shader && C:\msys64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\SFML-2.5.1\examples\shader\Shader.cpp -o CMakeFiles\shader.dir\Shader.cpp.s

# Object files for target shader
shader_OBJECTS = \
"CMakeFiles/shader.dir/Shader.cpp.obj"

# External object files for target shader
shader_EXTERNAL_OBJECTS =

examples/shader/shader.exe: examples/shader/CMakeFiles/shader.dir/Shader.cpp.obj
examples/shader/shader.exe: examples/shader/CMakeFiles/shader.dir/build.make
examples/shader/shader.exe: lib/libsfml-main.a
examples/shader/shader.exe: lib/libsfml-graphics.a
examples/shader/shader.exe: lib/libsfml-window.a
examples/shader/shader.exe: lib/libsfml-system.a
examples/shader/shader.exe: examples/shader/CMakeFiles/shader.dir/linkLibs.rsp
examples/shader/shader.exe: examples/shader/CMakeFiles/shader.dir/objects1.rsp
examples/shader/shader.exe: examples/shader/CMakeFiles/shader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\SFML-2.5.1\SFML-build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable shader.exe"
	cd /d D:\SFML-2.5.1\SFML-build\examples\shader && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\shader.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/shader/CMakeFiles/shader.dir/build: examples/shader/shader.exe
.PHONY : examples/shader/CMakeFiles/shader.dir/build

examples/shader/CMakeFiles/shader.dir/clean:
	cd /d D:\SFML-2.5.1\SFML-build\examples\shader && $(CMAKE_COMMAND) -P CMakeFiles\shader.dir\cmake_clean.cmake
.PHONY : examples/shader/CMakeFiles/shader.dir/clean

examples/shader/CMakeFiles/shader.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\SFML-2.5.1 D:\SFML-2.5.1\examples\shader D:\SFML-2.5.1\SFML-build D:\SFML-2.5.1\SFML-build\examples\shader D:\SFML-2.5.1\SFML-build\examples\shader\CMakeFiles\shader.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : examples/shader/CMakeFiles/shader.dir/depend

