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
include src/expr/CMakeFiles/expr.dir/depend.make

# Include the progress variables for this target.
include src/expr/CMakeFiles/expr.dir/progress.make

# Include the compile flags for this target's objects.
include src/expr/CMakeFiles/expr.dir/flags.make

src/expr/CMakeFiles/expr.dir/expr.c.o: src/expr/CMakeFiles/expr.dir/flags.make
src/expr/CMakeFiles/expr.dir/expr.c.o: ../src/expr/expr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/expr/CMakeFiles/expr.dir/expr.c.o"
	cd /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/src/expr && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/expr.dir/expr.c.o -c /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/src/expr/expr.c

src/expr/CMakeFiles/expr.dir/expr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/expr.dir/expr.c.i"
	cd /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/src/expr && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/src/expr/expr.c > CMakeFiles/expr.dir/expr.c.i

src/expr/CMakeFiles/expr.dir/expr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/expr.dir/expr.c.s"
	cd /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/src/expr && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/src/expr/expr.c -o CMakeFiles/expr.dir/expr.c.s

# Object files for target expr
expr_OBJECTS = \
"CMakeFiles/expr.dir/expr.c.o"

# External object files for target expr
expr_EXTERNAL_OBJECTS =

src/expr/expr: src/expr/CMakeFiles/expr.dir/expr.c.o
src/expr/expr: src/expr/CMakeFiles/expr.dir/build.make
src/expr/expr: compat/libcompat.a
src/expr/expr: src/expr/CMakeFiles/expr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable expr"
	cd /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/src/expr && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/expr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/expr/CMakeFiles/expr.dir/build: src/expr/expr

.PHONY : src/expr/CMakeFiles/expr.dir/build

src/expr/CMakeFiles/expr.dir/clean:
	cd /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/src/expr && $(CMAKE_COMMAND) -P CMakeFiles/expr.dir/cmake_clean.cmake
.PHONY : src/expr/CMakeFiles/expr.dir/clean

src/expr/CMakeFiles/expr.dir/depend:
	cd /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/src/expr /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/src/expr /mnt/c/Users/DiegoMagdaleno/Documents/Projects/BSDCoreUtils/cmake-build-debug/src/expr/CMakeFiles/expr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/expr/CMakeFiles/expr.dir/depend
