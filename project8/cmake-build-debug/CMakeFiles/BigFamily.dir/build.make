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
CMAKE_SOURCE_DIR = /Users/clint/Desktop/CS2201/project8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/clint/Desktop/CS2201/project8/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BigFamily.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BigFamily.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BigFamily.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BigFamily.dir/flags.make

CMakeFiles/BigFamily.dir/AnimalCount.cpp.o: CMakeFiles/BigFamily.dir/flags.make
CMakeFiles/BigFamily.dir/AnimalCount.cpp.o: /Users/clint/Desktop/CS2201/project8/AnimalCount.cpp
CMakeFiles/BigFamily.dir/AnimalCount.cpp.o: CMakeFiles/BigFamily.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clint/Desktop/CS2201/project8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BigFamily.dir/AnimalCount.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BigFamily.dir/AnimalCount.cpp.o -MF CMakeFiles/BigFamily.dir/AnimalCount.cpp.o.d -o CMakeFiles/BigFamily.dir/AnimalCount.cpp.o -c /Users/clint/Desktop/CS2201/project8/AnimalCount.cpp

CMakeFiles/BigFamily.dir/AnimalCount.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BigFamily.dir/AnimalCount.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clint/Desktop/CS2201/project8/AnimalCount.cpp > CMakeFiles/BigFamily.dir/AnimalCount.cpp.i

CMakeFiles/BigFamily.dir/AnimalCount.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BigFamily.dir/AnimalCount.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clint/Desktop/CS2201/project8/AnimalCount.cpp -o CMakeFiles/BigFamily.dir/AnimalCount.cpp.s

# Object files for target BigFamily
BigFamily_OBJECTS = \
"CMakeFiles/BigFamily.dir/AnimalCount.cpp.o"

# External object files for target BigFamily
BigFamily_EXTERNAL_OBJECTS =

/Users/clint/Desktop/CS2201/project8/BigFamily: CMakeFiles/BigFamily.dir/AnimalCount.cpp.o
/Users/clint/Desktop/CS2201/project8/BigFamily: CMakeFiles/BigFamily.dir/build.make
/Users/clint/Desktop/CS2201/project8/BigFamily: CMakeFiles/BigFamily.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/clint/Desktop/CS2201/project8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /Users/clint/Desktop/CS2201/project8/BigFamily"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BigFamily.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BigFamily.dir/build: /Users/clint/Desktop/CS2201/project8/BigFamily
.PHONY : CMakeFiles/BigFamily.dir/build

CMakeFiles/BigFamily.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BigFamily.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BigFamily.dir/clean

CMakeFiles/BigFamily.dir/depend:
	cd /Users/clint/Desktop/CS2201/project8/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/clint/Desktop/CS2201/project8 /Users/clint/Desktop/CS2201/project8 /Users/clint/Desktop/CS2201/project8/cmake-build-debug /Users/clint/Desktop/CS2201/project8/cmake-build-debug /Users/clint/Desktop/CS2201/project8/cmake-build-debug/CMakeFiles/BigFamily.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BigFamily.dir/depend
