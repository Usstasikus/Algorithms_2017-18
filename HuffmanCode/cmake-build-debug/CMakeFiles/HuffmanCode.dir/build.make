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
CMAKE_SOURCE_DIR = /Users/StasDon/CLionProjects/Algorithms/HuffmanCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/StasDon/CLionProjects/Algorithms/HuffmanCode/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HuffmanCode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HuffmanCode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HuffmanCode.dir/flags.make

CMakeFiles/HuffmanCode.dir/main.cpp.o: CMakeFiles/HuffmanCode.dir/flags.make
CMakeFiles/HuffmanCode.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/StasDon/CLionProjects/Algorithms/HuffmanCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HuffmanCode.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HuffmanCode.dir/main.cpp.o -c /Users/StasDon/CLionProjects/Algorithms/HuffmanCode/main.cpp

CMakeFiles/HuffmanCode.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HuffmanCode.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/StasDon/CLionProjects/Algorithms/HuffmanCode/main.cpp > CMakeFiles/HuffmanCode.dir/main.cpp.i

CMakeFiles/HuffmanCode.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HuffmanCode.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/StasDon/CLionProjects/Algorithms/HuffmanCode/main.cpp -o CMakeFiles/HuffmanCode.dir/main.cpp.s

CMakeFiles/HuffmanCode.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/HuffmanCode.dir/main.cpp.o.requires

CMakeFiles/HuffmanCode.dir/main.cpp.o.provides: CMakeFiles/HuffmanCode.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/HuffmanCode.dir/build.make CMakeFiles/HuffmanCode.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/HuffmanCode.dir/main.cpp.o.provides

CMakeFiles/HuffmanCode.dir/main.cpp.o.provides.build: CMakeFiles/HuffmanCode.dir/main.cpp.o


# Object files for target HuffmanCode
HuffmanCode_OBJECTS = \
"CMakeFiles/HuffmanCode.dir/main.cpp.o"

# External object files for target HuffmanCode
HuffmanCode_EXTERNAL_OBJECTS =

HuffmanCode: CMakeFiles/HuffmanCode.dir/main.cpp.o
HuffmanCode: CMakeFiles/HuffmanCode.dir/build.make
HuffmanCode: CMakeFiles/HuffmanCode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/StasDon/CLionProjects/Algorithms/HuffmanCode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable HuffmanCode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HuffmanCode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HuffmanCode.dir/build: HuffmanCode

.PHONY : CMakeFiles/HuffmanCode.dir/build

CMakeFiles/HuffmanCode.dir/requires: CMakeFiles/HuffmanCode.dir/main.cpp.o.requires

.PHONY : CMakeFiles/HuffmanCode.dir/requires

CMakeFiles/HuffmanCode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HuffmanCode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HuffmanCode.dir/clean

CMakeFiles/HuffmanCode.dir/depend:
	cd /Users/StasDon/CLionProjects/Algorithms/HuffmanCode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/StasDon/CLionProjects/Algorithms/HuffmanCode /Users/StasDon/CLionProjects/Algorithms/HuffmanCode /Users/StasDon/CLionProjects/Algorithms/HuffmanCode/cmake-build-debug /Users/StasDon/CLionProjects/Algorithms/HuffmanCode/cmake-build-debug /Users/StasDon/CLionProjects/Algorithms/HuffmanCode/cmake-build-debug/CMakeFiles/HuffmanCode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HuffmanCode.dir/depend
