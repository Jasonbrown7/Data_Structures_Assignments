# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jasonbrown/Desktop/PA03_JasonBrown

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jasonbrown/Desktop/PA03_JasonBrown

# Include any dependencies generated for this target.
include CMakeFiles/alg.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/alg.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/alg.dir/flags.make

CMakeFiles/alg.dir/src/sortingAlgos.cpp.o: CMakeFiles/alg.dir/flags.make
CMakeFiles/alg.dir/src/sortingAlgos.cpp.o: src/sortingAlgos.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jasonbrown/Desktop/PA03_JasonBrown/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/alg.dir/src/sortingAlgos.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/alg.dir/src/sortingAlgos.cpp.o -c /Users/jasonbrown/Desktop/PA03_JasonBrown/src/sortingAlgos.cpp

CMakeFiles/alg.dir/src/sortingAlgos.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/alg.dir/src/sortingAlgos.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jasonbrown/Desktop/PA03_JasonBrown/src/sortingAlgos.cpp > CMakeFiles/alg.dir/src/sortingAlgos.cpp.i

CMakeFiles/alg.dir/src/sortingAlgos.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/alg.dir/src/sortingAlgos.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jasonbrown/Desktop/PA03_JasonBrown/src/sortingAlgos.cpp -o CMakeFiles/alg.dir/src/sortingAlgos.cpp.s

# Object files for target alg
alg_OBJECTS = \
"CMakeFiles/alg.dir/src/sortingAlgos.cpp.o"

# External object files for target alg
alg_EXTERNAL_OBJECTS =

alg: CMakeFiles/alg.dir/src/sortingAlgos.cpp.o
alg: CMakeFiles/alg.dir/build.make
alg: CMakeFiles/alg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jasonbrown/Desktop/PA03_JasonBrown/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable alg"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/alg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/alg.dir/build: alg

.PHONY : CMakeFiles/alg.dir/build

CMakeFiles/alg.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/alg.dir/cmake_clean.cmake
.PHONY : CMakeFiles/alg.dir/clean

CMakeFiles/alg.dir/depend:
	cd /Users/jasonbrown/Desktop/PA03_JasonBrown && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jasonbrown/Desktop/PA03_JasonBrown /Users/jasonbrown/Desktop/PA03_JasonBrown /Users/jasonbrown/Desktop/PA03_JasonBrown /Users/jasonbrown/Desktop/PA03_JasonBrown /Users/jasonbrown/Desktop/PA03_JasonBrown/CMakeFiles/alg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/alg.dir/depend

