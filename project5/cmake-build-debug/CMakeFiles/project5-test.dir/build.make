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
CMAKE_SOURCE_DIR = /Users/clint/Desktop/CS2201/project5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/clint/Desktop/CS2201/project5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project5-test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project5-test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project5-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project5-test.dir/flags.make

CMakeFiles/project5-test.dir/DblStack.cpp.o: CMakeFiles/project5-test.dir/flags.make
CMakeFiles/project5-test.dir/DblStack.cpp.o: /Users/clint/Desktop/CS2201/project5/DblStack.cpp
CMakeFiles/project5-test.dir/DblStack.cpp.o: CMakeFiles/project5-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clint/Desktop/CS2201/project5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project5-test.dir/DblStack.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project5-test.dir/DblStack.cpp.o -MF CMakeFiles/project5-test.dir/DblStack.cpp.o.d -o CMakeFiles/project5-test.dir/DblStack.cpp.o -c /Users/clint/Desktop/CS2201/project5/DblStack.cpp

CMakeFiles/project5-test.dir/DblStack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project5-test.dir/DblStack.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clint/Desktop/CS2201/project5/DblStack.cpp > CMakeFiles/project5-test.dir/DblStack.cpp.i

CMakeFiles/project5-test.dir/DblStack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project5-test.dir/DblStack.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clint/Desktop/CS2201/project5/DblStack.cpp -o CMakeFiles/project5-test.dir/DblStack.cpp.s

CMakeFiles/project5-test.dir/DblStackTest.cpp.o: CMakeFiles/project5-test.dir/flags.make
CMakeFiles/project5-test.dir/DblStackTest.cpp.o: /Users/clint/Desktop/CS2201/project5/DblStackTest.cpp
CMakeFiles/project5-test.dir/DblStackTest.cpp.o: CMakeFiles/project5-test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clint/Desktop/CS2201/project5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project5-test.dir/DblStackTest.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project5-test.dir/DblStackTest.cpp.o -MF CMakeFiles/project5-test.dir/DblStackTest.cpp.o.d -o CMakeFiles/project5-test.dir/DblStackTest.cpp.o -c /Users/clint/Desktop/CS2201/project5/DblStackTest.cpp

CMakeFiles/project5-test.dir/DblStackTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project5-test.dir/DblStackTest.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clint/Desktop/CS2201/project5/DblStackTest.cpp > CMakeFiles/project5-test.dir/DblStackTest.cpp.i

CMakeFiles/project5-test.dir/DblStackTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project5-test.dir/DblStackTest.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clint/Desktop/CS2201/project5/DblStackTest.cpp -o CMakeFiles/project5-test.dir/DblStackTest.cpp.s

# Object files for target project5-test
project5__test_OBJECTS = \
"CMakeFiles/project5-test.dir/DblStack.cpp.o" \
"CMakeFiles/project5-test.dir/DblStackTest.cpp.o"

# External object files for target project5-test
project5__test_EXTERNAL_OBJECTS =

/Users/clint/Desktop/CS2201/project5/project5-test: CMakeFiles/project5-test.dir/DblStack.cpp.o
/Users/clint/Desktop/CS2201/project5/project5-test: CMakeFiles/project5-test.dir/DblStackTest.cpp.o
/Users/clint/Desktop/CS2201/project5/project5-test: CMakeFiles/project5-test.dir/build.make
/Users/clint/Desktop/CS2201/project5/project5-test: CMakeFiles/project5-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/clint/Desktop/CS2201/project5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable /Users/clint/Desktop/CS2201/project5/project5-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project5-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project5-test.dir/build: /Users/clint/Desktop/CS2201/project5/project5-test
.PHONY : CMakeFiles/project5-test.dir/build

CMakeFiles/project5-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project5-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project5-test.dir/clean

CMakeFiles/project5-test.dir/depend:
	cd /Users/clint/Desktop/CS2201/project5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/clint/Desktop/CS2201/project5 /Users/clint/Desktop/CS2201/project5 /Users/clint/Desktop/CS2201/project5/cmake-build-debug /Users/clint/Desktop/CS2201/project5/cmake-build-debug /Users/clint/Desktop/CS2201/project5/cmake-build-debug/CMakeFiles/project5-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project5-test.dir/depend

