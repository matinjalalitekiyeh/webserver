# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/matin/Videos/gtest-cmake-example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matin/Videos/gtest-cmake-example/build

# Include any dependencies generated for this target.
include lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/flags.make

lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/flags.make
lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: /home/matin/Videos/gtest-cmake-example/lib/gtest-1.6.0/src/gtest_main.cc
lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/matin/Videos/gtest-cmake-example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd /home/matin/Videos/gtest-cmake-example/build/lib/gtest-1.6.0 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -MF CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.d -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c /home/matin/Videos/gtest-cmake-example/lib/gtest-1.6.0/src/gtest_main.cc

lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /home/matin/Videos/gtest-cmake-example/build/lib/gtest-1.6.0 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/matin/Videos/gtest-cmake-example/lib/gtest-1.6.0/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /home/matin/Videos/gtest-cmake-example/build/lib/gtest-1.6.0 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/matin/Videos/gtest-cmake-example/lib/gtest-1.6.0/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

lib/gtest-1.6.0/libgtest_main.a: lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
lib/gtest-1.6.0/libgtest_main.a: lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/build.make
lib/gtest-1.6.0/libgtest_main.a: lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/matin/Videos/gtest-cmake-example/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libgtest_main.a"
	cd /home/matin/Videos/gtest-cmake-example/build/lib/gtest-1.6.0 && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd /home/matin/Videos/gtest-cmake-example/build/lib/gtest-1.6.0 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/build: lib/gtest-1.6.0/libgtest_main.a
.PHONY : lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/build

lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/clean:
	cd /home/matin/Videos/gtest-cmake-example/build/lib/gtest-1.6.0 && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/clean

lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/depend:
	cd /home/matin/Videos/gtest-cmake-example/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matin/Videos/gtest-cmake-example /home/matin/Videos/gtest-cmake-example/lib/gtest-1.6.0 /home/matin/Videos/gtest-cmake-example/build /home/matin/Videos/gtest-cmake-example/build/lib/gtest-1.6.0 /home/matin/Videos/gtest-cmake-example/build/lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/gtest-1.6.0/CMakeFiles/gtest_main.dir/depend

