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
CMAKE_SOURCE_DIR = /Users/clint/Desktop/CS2201/project4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/clint/Desktop/CS2201/project4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project4.dir/flags.make

CMakeFiles/project4.dir/lab04-driver.cpp.o: CMakeFiles/project4.dir/flags.make
CMakeFiles/project4.dir/lab04-driver.cpp.o: /Users/clint/Desktop/CS2201/project4/lab04-driver.cpp
CMakeFiles/project4.dir/lab04-driver.cpp.o: CMakeFiles/project4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clint/Desktop/CS2201/project4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project4.dir/lab04-driver.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project4.dir/lab04-driver.cpp.o -MF CMakeFiles/project4.dir/lab04-driver.cpp.o.d -o CMakeFiles/project4.dir/lab04-driver.cpp.o -c /Users/clint/Desktop/CS2201/project4/lab04-driver.cpp

CMakeFiles/project4.dir/lab04-driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project4.dir/lab04-driver.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clint/Desktop/CS2201/project4/lab04-driver.cpp > CMakeFiles/project4.dir/lab04-driver.cpp.i

CMakeFiles/project4.dir/lab04-driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project4.dir/lab04-driver.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clint/Desktop/CS2201/project4/lab04-driver.cpp -o CMakeFiles/project4.dir/lab04-driver.cpp.s

CMakeFiles/project4.dir/lab04.cpp.o: CMakeFiles/project4.dir/flags.make
CMakeFiles/project4.dir/lab04.cpp.o: /Users/clint/Desktop/CS2201/project4/lab04.cpp
CMakeFiles/project4.dir/lab04.cpp.o: CMakeFiles/project4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clint/Desktop/CS2201/project4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project4.dir/lab04.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project4.dir/lab04.cpp.o -MF CMakeFiles/project4.dir/lab04.cpp.o.d -o CMakeFiles/project4.dir/lab04.cpp.o -c /Users/clint/Desktop/CS2201/project4/lab04.cpp

CMakeFiles/project4.dir/lab04.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project4.dir/lab04.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clint/Desktop/CS2201/project4/lab04.cpp > CMakeFiles/project4.dir/lab04.cpp.i

CMakeFiles/project4.dir/lab04.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project4.dir/lab04.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clint/Desktop/CS2201/project4/lab04.cpp -o CMakeFiles/project4.dir/lab04.cpp.s

# Object files for target project4
project4_OBJECTS = \
"CMakeFiles/project4.dir/lab04-driver.cpp.o" \
"CMakeFiles/project4.dir/lab04.cpp.o"

# External object files for target project4
project4_EXTERNAL_OBJECTS =

project4: CMakeFiles/project4.dir/lab04-driver.cpp.o
project4: CMakeFiles/project4.dir/lab04.cpp.o
project4: CMakeFiles/project4.dir/build.make
project4: CMakeFiles/project4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/clint/Desktop/CS2201/project4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable project4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project4.dir/build: project4
.PHONY : CMakeFiles/project4.dir/build

CMakeFiles/project4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project4.dir/clean

CMakeFiles/project4.dir/depend:
	cd /Users/clint/Desktop/CS2201/project4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/clint/Desktop/CS2201/project4 /Users/clint/Desktop/CS2201/project4 /Users/clint/Desktop/CS2201/project4/cmake-build-debug /Users/clint/Desktop/CS2201/project4/cmake-build-debug /Users/clint/Desktop/CS2201/project4/cmake-build-debug/CMakeFiles/project4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project4.dir/depend
