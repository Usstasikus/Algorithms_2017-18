# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/StasDon/CLionProjects/Algorithms/EncodingProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/StasDon/CLionProjects/Algorithms/EncodingProject/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/EncodingProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EncodingProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EncodingProject.dir/flags.make

CMakeFiles/EncodingProject.dir/main.cpp.o: CMakeFiles/EncodingProject.dir/flags.make
CMakeFiles/EncodingProject.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/StasDon/CLionProjects/Algorithms/EncodingProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EncodingProject.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EncodingProject.dir/main.cpp.o -c /Users/StasDon/CLionProjects/Algorithms/EncodingProject/main.cpp

CMakeFiles/EncodingProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EncodingProject.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/StasDon/CLionProjects/Algorithms/EncodingProject/main.cpp > CMakeFiles/EncodingProject.dir/main.cpp.i

CMakeFiles/EncodingProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EncodingProject.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/StasDon/CLionProjects/Algorithms/EncodingProject/main.cpp -o CMakeFiles/EncodingProject.dir/main.cpp.s

CMakeFiles/EncodingProject.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/EncodingProject.dir/main.cpp.o.requires

CMakeFiles/EncodingProject.dir/main.cpp.o.provides: CMakeFiles/EncodingProject.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/EncodingProject.dir/build.make CMakeFiles/EncodingProject.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/EncodingProject.dir/main.cpp.o.provides

CMakeFiles/EncodingProject.dir/main.cpp.o.provides.build: CMakeFiles/EncodingProject.dir/main.cpp.o


CMakeFiles/EncodingProject.dir/huffman.cpp.o: CMakeFiles/EncodingProject.dir/flags.make
CMakeFiles/EncodingProject.dir/huffman.cpp.o: ../huffman.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/StasDon/CLionProjects/Algorithms/EncodingProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/EncodingProject.dir/huffman.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EncodingProject.dir/huffman.cpp.o -c /Users/StasDon/CLionProjects/Algorithms/EncodingProject/huffman.cpp

CMakeFiles/EncodingProject.dir/huffman.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EncodingProject.dir/huffman.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/StasDon/CLionProjects/Algorithms/EncodingProject/huffman.cpp > CMakeFiles/EncodingProject.dir/huffman.cpp.i

CMakeFiles/EncodingProject.dir/huffman.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EncodingProject.dir/huffman.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/StasDon/CLionProjects/Algorithms/EncodingProject/huffman.cpp -o CMakeFiles/EncodingProject.dir/huffman.cpp.s

CMakeFiles/EncodingProject.dir/huffman.cpp.o.requires:

.PHONY : CMakeFiles/EncodingProject.dir/huffman.cpp.o.requires

CMakeFiles/EncodingProject.dir/huffman.cpp.o.provides: CMakeFiles/EncodingProject.dir/huffman.cpp.o.requires
	$(MAKE) -f CMakeFiles/EncodingProject.dir/build.make CMakeFiles/EncodingProject.dir/huffman.cpp.o.provides.build
.PHONY : CMakeFiles/EncodingProject.dir/huffman.cpp.o.provides

CMakeFiles/EncodingProject.dir/huffman.cpp.o.provides.build: CMakeFiles/EncodingProject.dir/huffman.cpp.o


# Object files for target EncodingProject
EncodingProject_OBJECTS = \
"CMakeFiles/EncodingProject.dir/main.cpp.o" \
"CMakeFiles/EncodingProject.dir/huffman.cpp.o"

# External object files for target EncodingProject
EncodingProject_EXTERNAL_OBJECTS =

EncodingProject: CMakeFiles/EncodingProject.dir/main.cpp.o
EncodingProject: CMakeFiles/EncodingProject.dir/huffman.cpp.o
EncodingProject: CMakeFiles/EncodingProject.dir/build.make
EncodingProject: CMakeFiles/EncodingProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/StasDon/CLionProjects/Algorithms/EncodingProject/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable EncodingProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EncodingProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EncodingProject.dir/build: EncodingProject

.PHONY : CMakeFiles/EncodingProject.dir/build

CMakeFiles/EncodingProject.dir/requires: CMakeFiles/EncodingProject.dir/main.cpp.o.requires
CMakeFiles/EncodingProject.dir/requires: CMakeFiles/EncodingProject.dir/huffman.cpp.o.requires

.PHONY : CMakeFiles/EncodingProject.dir/requires

CMakeFiles/EncodingProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EncodingProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EncodingProject.dir/clean

CMakeFiles/EncodingProject.dir/depend:
	cd /Users/StasDon/CLionProjects/Algorithms/EncodingProject/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/StasDon/CLionProjects/Algorithms/EncodingProject /Users/StasDon/CLionProjects/Algorithms/EncodingProject /Users/StasDon/CLionProjects/Algorithms/EncodingProject/cmake-build-debug /Users/StasDon/CLionProjects/Algorithms/EncodingProject/cmake-build-debug /Users/StasDon/CLionProjects/Algorithms/EncodingProject/cmake-build-debug/CMakeFiles/EncodingProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EncodingProject.dir/depend

