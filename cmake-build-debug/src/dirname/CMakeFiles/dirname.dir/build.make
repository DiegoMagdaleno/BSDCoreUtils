# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug

# Include any dependencies generated for this target.
include src/dirname/CMakeFiles/dirname.dir/depend.make

# Include the progress variables for this target.
include src/dirname/CMakeFiles/dirname.dir/progress.make

# Include the compile flags for this target's objects.
include src/dirname/CMakeFiles/dirname.dir/flags.make

src/dirname/CMakeFiles/dirname.dir/dirname.c.o: src/dirname/CMakeFiles/dirname.dir/flags.make
src/dirname/CMakeFiles/dirname.dir/dirname.c.o: ../src/dirname/dirname.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/dirname/CMakeFiles/dirname.dir/dirname.c.o"
	cd /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/src/dirname && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dirname.dir/dirname.c.o -c /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/src/dirname/dirname.c

src/dirname/CMakeFiles/dirname.dir/dirname.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dirname.dir/dirname.c.i"
	cd /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/src/dirname && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/src/dirname/dirname.c > CMakeFiles/dirname.dir/dirname.c.i

src/dirname/CMakeFiles/dirname.dir/dirname.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dirname.dir/dirname.c.s"
	cd /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/src/dirname && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/src/dirname/dirname.c -o CMakeFiles/dirname.dir/dirname.c.s

# Object files for target dirname
dirname_OBJECTS = \
"CMakeFiles/dirname.dir/dirname.c.o"

# External object files for target dirname
dirname_EXTERNAL_OBJECTS =

src/dirname/dirname: src/dirname/CMakeFiles/dirname.dir/dirname.c.o
src/dirname/dirname: src/dirname/CMakeFiles/dirname.dir/build.make
src/dirname/dirname: src/dirname/CMakeFiles/dirname.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable dirname"
	cd /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/src/dirname && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dirname.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/dirname/CMakeFiles/dirname.dir/build: src/dirname/dirname

.PHONY : src/dirname/CMakeFiles/dirname.dir/build

src/dirname/CMakeFiles/dirname.dir/clean:
	cd /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/src/dirname && $(CMAKE_COMMAND) -P CMakeFiles/dirname.dir/cmake_clean.cmake
.PHONY : src/dirname/CMakeFiles/dirname.dir/clean

src/dirname/CMakeFiles/dirname.dir/depend:
	cd /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/src/dirname /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/src/dirname /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/src/dirname/CMakeFiles/dirname.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/dirname/CMakeFiles/dirname.dir/depend
