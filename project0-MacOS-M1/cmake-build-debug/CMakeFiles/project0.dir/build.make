# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/clint/Desktop/CS2201/project0-MacOS-M1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/clint/Desktop/CS2201/project0-MacOS-M1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project0.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project0.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project0.dir/flags.make

CMakeFiles/project0.dir/DNAtest.cpp.o: CMakeFiles/project0.dir/flags.make
CMakeFiles/project0.dir/DNAtest.cpp.o: /Users/clint/Desktop/CS2201/project0-MacOS-M1/DNAtest.cpp
CMakeFiles/project0.dir/DNAtest.cpp.o: CMakeFiles/project0.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clint/Desktop/CS2201/project0-MacOS-M1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project0.dir/DNAtest.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project0.dir/DNAtest.cpp.o -MF CMakeFiles/project0.dir/DNAtest.cpp.o.d -o CMakeFiles/project0.dir/DNAtest.cpp.o -c /Users/clint/Desktop/CS2201/project0-MacOS-M1/DNAtest.cpp

CMakeFiles/project0.dir/DNAtest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project0.dir/DNAtest.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clint/Desktop/CS2201/project0-MacOS-M1/DNAtest.cpp > CMakeFiles/project0.dir/DNAtest.cpp.i

CMakeFiles/project0.dir/DNAtest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project0.dir/DNAtest.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clint/Desktop/CS2201/project0-MacOS-M1/DNAtest.cpp -o CMakeFiles/project0.dir/DNAtest.cpp.s

# Object files for target project0
project0_OBJECTS = \
"CMakeFiles/project0.dir/DNAtest.cpp.o"

# External object files for target project0
project0_EXTERNAL_OBJECTS = \
"/Users/clint/Desktop/CS2201/project0-MacOS-M1/DNA_Strand.cpp.o"

project0: CMakeFiles/project0.dir/DNAtest.cpp.o
project0: /Users/clint/Desktop/CS2201/project0-MacOS-M1/DNA_Strand.cpp.o
project0: CMakeFiles/project0.dir/build.make
project0: CMakeFiles/project0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/clint/Desktop/CS2201/project0-MacOS-M1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable project0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project0.dir/build: project0
.PHONY : CMakeFiles/project0.dir/build

CMakeFiles/project0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project0.dir/clean

CMakeFiles/project0.dir/depend:
	cd /Users/clint/Desktop/CS2201/project0-MacOS-M1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/clint/Desktop/CS2201/project0-MacOS-M1 /Users/clint/Desktop/CS2201/project0-MacOS-M1 /Users/clint/Desktop/CS2201/project0-MacOS-M1/cmake-build-debug /Users/clint/Desktop/CS2201/project0-MacOS-M1/cmake-build-debug /Users/clint/Desktop/CS2201/project0-MacOS-M1/cmake-build-debug/CMakeFiles/project0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project0.dir/depend
