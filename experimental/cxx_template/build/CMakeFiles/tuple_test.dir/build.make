# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Cmake\bin\cmake.exe

# The command to remove a file.
RM = D:\Cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\work\.subrepos\common\experimental\cxx_template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\work\.subrepos\common\experimental\cxx_template\build

# Include any dependencies generated for this target.
include CMakeFiles/tuple_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tuple_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tuple_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tuple_test.dir/flags.make

CMakeFiles/tuple_test.dir/tuple_test.cc.obj: CMakeFiles/tuple_test.dir/flags.make
CMakeFiles/tuple_test.dir/tuple_test.cc.obj: D:/work/.subrepos/common/experimental/cxx_template/tuple_test.cc
CMakeFiles/tuple_test.dir/tuple_test.cc.obj: CMakeFiles/tuple_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\work\.subrepos\common\experimental\cxx_template\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tuple_test.dir/tuple_test.cc.obj"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tuple_test.dir/tuple_test.cc.obj -MF CMakeFiles\tuple_test.dir\tuple_test.cc.obj.d -o CMakeFiles\tuple_test.dir\tuple_test.cc.obj -c D:\work\.subrepos\common\experimental\cxx_template\tuple_test.cc

CMakeFiles/tuple_test.dir/tuple_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tuple_test.dir/tuple_test.cc.i"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\work\.subrepos\common\experimental\cxx_template\tuple_test.cc > CMakeFiles\tuple_test.dir\tuple_test.cc.i

CMakeFiles/tuple_test.dir/tuple_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tuple_test.dir/tuple_test.cc.s"
	D:\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\work\.subrepos\common\experimental\cxx_template\tuple_test.cc -o CMakeFiles\tuple_test.dir\tuple_test.cc.s

# Object files for target tuple_test
tuple_test_OBJECTS = \
"CMakeFiles/tuple_test.dir/tuple_test.cc.obj"

# External object files for target tuple_test
tuple_test_EXTERNAL_OBJECTS =

tuple_test.exe: CMakeFiles/tuple_test.dir/tuple_test.cc.obj
tuple_test.exe: CMakeFiles/tuple_test.dir/build.make
tuple_test.exe: CMakeFiles/tuple_test.dir/linkLibs.rsp
tuple_test.exe: CMakeFiles/tuple_test.dir/objects1.rsp
tuple_test.exe: CMakeFiles/tuple_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\work\.subrepos\common\experimental\cxx_template\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tuple_test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tuple_test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tuple_test.dir/build: tuple_test.exe
.PHONY : CMakeFiles/tuple_test.dir/build

CMakeFiles/tuple_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tuple_test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tuple_test.dir/clean

CMakeFiles/tuple_test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\work\.subrepos\common\experimental\cxx_template D:\work\.subrepos\common\experimental\cxx_template D:\work\.subrepos\common\experimental\cxx_template\build D:\work\.subrepos\common\experimental\cxx_template\build D:\work\.subrepos\common\experimental\cxx_template\build\CMakeFiles\tuple_test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tuple_test.dir/depend

