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
CMAKE_SOURCE_DIR = /Users/clint/Desktop/CS2201/project7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/clint/Desktop/CS2201/project7/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/project7.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/project7.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/project7.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/project7.dir/flags.make

CMakeFiles/project7.dir/Main.cpp.o: CMakeFiles/project7.dir/flags.make
CMakeFiles/project7.dir/Main.cpp.o: /Users/clint/Desktop/CS2201/project7/Main.cpp
CMakeFiles/project7.dir/Main.cpp.o: CMakeFiles/project7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clint/Desktop/CS2201/project7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/project7.dir/Main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project7.dir/Main.cpp.o -MF CMakeFiles/project7.dir/Main.cpp.o.d -o CMakeFiles/project7.dir/Main.cpp.o -c /Users/clint/Desktop/CS2201/project7/Main.cpp

CMakeFiles/project7.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project7.dir/Main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clint/Desktop/CS2201/project7/Main.cpp > CMakeFiles/project7.dir/Main.cpp.i

CMakeFiles/project7.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project7.dir/Main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clint/Desktop/CS2201/project7/Main.cpp -o CMakeFiles/project7.dir/Main.cpp.s

CMakeFiles/project7.dir/Maze.cpp.o: CMakeFiles/project7.dir/flags.make
CMakeFiles/project7.dir/Maze.cpp.o: /Users/clint/Desktop/CS2201/project7/Maze.cpp
CMakeFiles/project7.dir/Maze.cpp.o: CMakeFiles/project7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clint/Desktop/CS2201/project7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/project7.dir/Maze.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project7.dir/Maze.cpp.o -MF CMakeFiles/project7.dir/Maze.cpp.o.d -o CMakeFiles/project7.dir/Maze.cpp.o -c /Users/clint/Desktop/CS2201/project7/Maze.cpp

CMakeFiles/project7.dir/Maze.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project7.dir/Maze.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clint/Desktop/CS2201/project7/Maze.cpp > CMakeFiles/project7.dir/Maze.cpp.i

CMakeFiles/project7.dir/Maze.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project7.dir/Maze.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clint/Desktop/CS2201/project7/Maze.cpp -o CMakeFiles/project7.dir/Maze.cpp.s

CMakeFiles/project7.dir/MazeSolver.cpp.o: CMakeFiles/project7.dir/flags.make
CMakeFiles/project7.dir/MazeSolver.cpp.o: /Users/clint/Desktop/CS2201/project7/MazeSolver.cpp
CMakeFiles/project7.dir/MazeSolver.cpp.o: CMakeFiles/project7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clint/Desktop/CS2201/project7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/project7.dir/MazeSolver.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project7.dir/MazeSolver.cpp.o -MF CMakeFiles/project7.dir/MazeSolver.cpp.o.d -o CMakeFiles/project7.dir/MazeSolver.cpp.o -c /Users/clint/Desktop/CS2201/project7/MazeSolver.cpp

CMakeFiles/project7.dir/MazeSolver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project7.dir/MazeSolver.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clint/Desktop/CS2201/project7/MazeSolver.cpp > CMakeFiles/project7.dir/MazeSolver.cpp.i

CMakeFiles/project7.dir/MazeSolver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project7.dir/MazeSolver.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clint/Desktop/CS2201/project7/MazeSolver.cpp -o CMakeFiles/project7.dir/MazeSolver.cpp.s

CMakeFiles/project7.dir/Point.cpp.o: CMakeFiles/project7.dir/flags.make
CMakeFiles/project7.dir/Point.cpp.o: /Users/clint/Desktop/CS2201/project7/Point.cpp
CMakeFiles/project7.dir/Point.cpp.o: CMakeFiles/project7.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/clint/Desktop/CS2201/project7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/project7.dir/Point.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/project7.dir/Point.cpp.o -MF CMakeFiles/project7.dir/Point.cpp.o.d -o CMakeFiles/project7.dir/Point.cpp.o -c /Users/clint/Desktop/CS2201/project7/Point.cpp

CMakeFiles/project7.dir/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/project7.dir/Point.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/clint/Desktop/CS2201/project7/Point.cpp > CMakeFiles/project7.dir/Point.cpp.i

CMakeFiles/project7.dir/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/project7.dir/Point.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/clint/Desktop/CS2201/project7/Point.cpp -o CMakeFiles/project7.dir/Point.cpp.s

# Object files for target project7
project7_OBJECTS = \
"CMakeFiles/project7.dir/Main.cpp.o" \
"CMakeFiles/project7.dir/Maze.cpp.o" \
"CMakeFiles/project7.dir/MazeSolver.cpp.o" \
"CMakeFiles/project7.dir/Point.cpp.o"

# External object files for target project7
project7_EXTERNAL_OBJECTS =

/Users/clint/Desktop/CS2201/project7/project7: CMakeFiles/project7.dir/Main.cpp.o
/Users/clint/Desktop/CS2201/project7/project7: CMakeFiles/project7.dir/Maze.cpp.o
/Users/clint/Desktop/CS2201/project7/project7: CMakeFiles/project7.dir/MazeSolver.cpp.o
/Users/clint/Desktop/CS2201/project7/project7: CMakeFiles/project7.dir/Point.cpp.o
/Users/clint/Desktop/CS2201/project7/project7: CMakeFiles/project7.dir/build.make
/Users/clint/Desktop/CS2201/project7/project7: CMakeFiles/project7.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/clint/Desktop/CS2201/project7/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable /Users/clint/Desktop/CS2201/project7/project7"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/project7.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/project7.dir/build: /Users/clint/Desktop/CS2201/project7/project7
.PHONY : CMakeFiles/project7.dir/build

CMakeFiles/project7.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/project7.dir/cmake_clean.cmake
.PHONY : CMakeFiles/project7.dir/clean

CMakeFiles/project7.dir/depend:
	cd /Users/clint/Desktop/CS2201/project7/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/clint/Desktop/CS2201/project7 /Users/clint/Desktop/CS2201/project7 /Users/clint/Desktop/CS2201/project7/cmake-build-debug /Users/clint/Desktop/CS2201/project7/cmake-build-debug /Users/clint/Desktop/CS2201/project7/cmake-build-debug/CMakeFiles/project7.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/project7.dir/depend
