# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\repos\asio_wrapper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\repos\asio_wrapper\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/asio_wrapper_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/asio_wrapper_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/asio_wrapper_main.dir/flags.make

CMakeFiles/asio_wrapper_main.dir/main.cpp.obj: CMakeFiles/asio_wrapper_main.dir/flags.make
CMakeFiles/asio_wrapper_main.dir/main.cpp.obj: CMakeFiles/asio_wrapper_main.dir/includes_CXX.rsp
CMakeFiles/asio_wrapper_main.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\repos\asio_wrapper\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/asio_wrapper_main.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\asio_wrapper_main.dir\main.cpp.obj -c C:\repos\asio_wrapper\main.cpp

CMakeFiles/asio_wrapper_main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asio_wrapper_main.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\repos\asio_wrapper\main.cpp > CMakeFiles\asio_wrapper_main.dir\main.cpp.i

CMakeFiles/asio_wrapper_main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asio_wrapper_main.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\repos\asio_wrapper\main.cpp -o CMakeFiles\asio_wrapper_main.dir\main.cpp.s

# Object files for target asio_wrapper_main
asio_wrapper_main_OBJECTS = \
"CMakeFiles/asio_wrapper_main.dir/main.cpp.obj"

# External object files for target asio_wrapper_main
asio_wrapper_main_EXTERNAL_OBJECTS =

asio_wrapper_main.exe: CMakeFiles/asio_wrapper_main.dir/main.cpp.obj
asio_wrapper_main.exe: CMakeFiles/asio_wrapper_main.dir/build.make
asio_wrapper_main.exe: src/libasio_wrapper.a
asio_wrapper_main.exe: CMakeFiles/asio_wrapper_main.dir/linklibs.rsp
asio_wrapper_main.exe: CMakeFiles/asio_wrapper_main.dir/objects1.rsp
asio_wrapper_main.exe: CMakeFiles/asio_wrapper_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\repos\asio_wrapper\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable asio_wrapper_main.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\asio_wrapper_main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/asio_wrapper_main.dir/build: asio_wrapper_main.exe

.PHONY : CMakeFiles/asio_wrapper_main.dir/build

CMakeFiles/asio_wrapper_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\asio_wrapper_main.dir\cmake_clean.cmake
.PHONY : CMakeFiles/asio_wrapper_main.dir/clean

CMakeFiles/asio_wrapper_main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\repos\asio_wrapper C:\repos\asio_wrapper C:\repos\asio_wrapper\cmake-build-debug C:\repos\asio_wrapper\cmake-build-debug C:\repos\asio_wrapper\cmake-build-debug\CMakeFiles\asio_wrapper_main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/asio_wrapper_main.dir/depend

