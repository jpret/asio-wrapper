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
include src/CMakeFiles/asio_wrapper.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/asio_wrapper.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/asio_wrapper.dir/flags.make

src/CMakeFiles/asio_wrapper.dir/asio_wrapper.cpp.obj: src/CMakeFiles/asio_wrapper.dir/flags.make
src/CMakeFiles/asio_wrapper.dir/asio_wrapper.cpp.obj: src/CMakeFiles/asio_wrapper.dir/includes_CXX.rsp
src/CMakeFiles/asio_wrapper.dir/asio_wrapper.cpp.obj: ../src/asio_wrapper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\repos\asio_wrapper\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/asio_wrapper.dir/asio_wrapper.cpp.obj"
	cd /d C:\repos\asio_wrapper\cmake-build-debug\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\asio_wrapper.dir\asio_wrapper.cpp.obj -c C:\repos\asio_wrapper\src\asio_wrapper.cpp

src/CMakeFiles/asio_wrapper.dir/asio_wrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/asio_wrapper.dir/asio_wrapper.cpp.i"
	cd /d C:\repos\asio_wrapper\cmake-build-debug\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\repos\asio_wrapper\src\asio_wrapper.cpp > CMakeFiles\asio_wrapper.dir\asio_wrapper.cpp.i

src/CMakeFiles/asio_wrapper.dir/asio_wrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/asio_wrapper.dir/asio_wrapper.cpp.s"
	cd /d C:\repos\asio_wrapper\cmake-build-debug\src && C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\repos\asio_wrapper\src\asio_wrapper.cpp -o CMakeFiles\asio_wrapper.dir\asio_wrapper.cpp.s

# Object files for target asio_wrapper
asio_wrapper_OBJECTS = \
"CMakeFiles/asio_wrapper.dir/asio_wrapper.cpp.obj"

# External object files for target asio_wrapper
asio_wrapper_EXTERNAL_OBJECTS =

src/libasio_wrapper.a: src/CMakeFiles/asio_wrapper.dir/asio_wrapper.cpp.obj
src/libasio_wrapper.a: src/CMakeFiles/asio_wrapper.dir/build.make
src/libasio_wrapper.a: src/CMakeFiles/asio_wrapper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\repos\asio_wrapper\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libasio_wrapper.a"
	cd /d C:\repos\asio_wrapper\cmake-build-debug\src && $(CMAKE_COMMAND) -P CMakeFiles\asio_wrapper.dir\cmake_clean_target.cmake
	cd /d C:\repos\asio_wrapper\cmake-build-debug\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\asio_wrapper.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/asio_wrapper.dir/build: src/libasio_wrapper.a

.PHONY : src/CMakeFiles/asio_wrapper.dir/build

src/CMakeFiles/asio_wrapper.dir/clean:
	cd /d C:\repos\asio_wrapper\cmake-build-debug\src && $(CMAKE_COMMAND) -P CMakeFiles\asio_wrapper.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/asio_wrapper.dir/clean

src/CMakeFiles/asio_wrapper.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\repos\asio_wrapper C:\repos\asio_wrapper\src C:\repos\asio_wrapper\cmake-build-debug C:\repos\asio_wrapper\cmake-build-debug\src C:\repos\asio_wrapper\cmake-build-debug\src\CMakeFiles\asio_wrapper.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/asio_wrapper.dir/depend

