# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/CLionWorking.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CLionWorking.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CLionWorking.dir/flags.make

CMakeFiles/CLionWorking.dir/main.c.o: CMakeFiles/CLionWorking.dir/flags.make
CMakeFiles/CLionWorking.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CLionWorking.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CLionWorking.dir/main.c.o   -c "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking/main.c"

CMakeFiles/CLionWorking.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CLionWorking.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking/main.c" > CMakeFiles/CLionWorking.dir/main.c.i

CMakeFiles/CLionWorking.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CLionWorking.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking/main.c" -o CMakeFiles/CLionWorking.dir/main.c.s

CMakeFiles/CLionWorking.dir/s9q1.c.o: CMakeFiles/CLionWorking.dir/flags.make
CMakeFiles/CLionWorking.dir/s9q1.c.o: ../s9q1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/CLionWorking.dir/s9q1.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CLionWorking.dir/s9q1.c.o   -c "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking/s9q1.c"

CMakeFiles/CLionWorking.dir/s9q1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CLionWorking.dir/s9q1.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking/s9q1.c" > CMakeFiles/CLionWorking.dir/s9q1.c.i

CMakeFiles/CLionWorking.dir/s9q1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CLionWorking.dir/s9q1.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking/s9q1.c" -o CMakeFiles/CLionWorking.dir/s9q1.c.s

# Object files for target CLionWorking
CLionWorking_OBJECTS = \
"CMakeFiles/CLionWorking.dir/main.c.o" \
"CMakeFiles/CLionWorking.dir/s9q1.c.o"

# External object files for target CLionWorking
CLionWorking_EXTERNAL_OBJECTS =

CLionWorking: CMakeFiles/CLionWorking.dir/main.c.o
CLionWorking: CMakeFiles/CLionWorking.dir/s9q1.c.o
CLionWorking: CMakeFiles/CLionWorking.dir/build.make
CLionWorking: CMakeFiles/CLionWorking.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable CLionWorking"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CLionWorking.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CLionWorking.dir/build: CLionWorking

.PHONY : CMakeFiles/CLionWorking.dir/build

CMakeFiles/CLionWorking.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CLionWorking.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CLionWorking.dir/clean

CMakeFiles/CLionWorking.dir/depend:
	cd "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking" "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking" "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking/cmake-build-debug" "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking/cmake-build-debug" "/Users/rubenvanbreda/OneDrive/UCD/Computer Programming 2/Labs/CLionWorking/cmake-build-debug/CMakeFiles/CLionWorking.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CLionWorking.dir/depend

