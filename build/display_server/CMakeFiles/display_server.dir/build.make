# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build

# Include any dependencies generated for this target.
include display_server/CMakeFiles/display_server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include display_server/CMakeFiles/display_server.dir/compiler_depend.make

# Include the progress variables for this target.
include display_server/CMakeFiles/display_server.dir/progress.make

# Include the compile flags for this target's objects.
include display_server/CMakeFiles/display_server.dir/flags.make

display_server/CMakeFiles/display_server.dir/src/main.cpp.o: display_server/CMakeFiles/display_server.dir/flags.make
display_server/CMakeFiles/display_server.dir/src/main.cpp.o: ../display_server/src/main.cpp
display_server/CMakeFiles/display_server.dir/src/main.cpp.o: display_server/CMakeFiles/display_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object display_server/CMakeFiles/display_server.dir/src/main.cpp.o"
	cd /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build/display_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT display_server/CMakeFiles/display_server.dir/src/main.cpp.o -MF CMakeFiles/display_server.dir/src/main.cpp.o.d -o CMakeFiles/display_server.dir/src/main.cpp.o -c /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/display_server/src/main.cpp

display_server/CMakeFiles/display_server.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/display_server.dir/src/main.cpp.i"
	cd /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build/display_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/display_server/src/main.cpp > CMakeFiles/display_server.dir/src/main.cpp.i

display_server/CMakeFiles/display_server.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/display_server.dir/src/main.cpp.s"
	cd /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build/display_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/display_server/src/main.cpp -o CMakeFiles/display_server.dir/src/main.cpp.s

display_server/CMakeFiles/display_server.dir/src/handler.cpp.o: display_server/CMakeFiles/display_server.dir/flags.make
display_server/CMakeFiles/display_server.dir/src/handler.cpp.o: ../display_server/src/handler.cpp
display_server/CMakeFiles/display_server.dir/src/handler.cpp.o: display_server/CMakeFiles/display_server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object display_server/CMakeFiles/display_server.dir/src/handler.cpp.o"
	cd /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build/display_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT display_server/CMakeFiles/display_server.dir/src/handler.cpp.o -MF CMakeFiles/display_server.dir/src/handler.cpp.o.d -o CMakeFiles/display_server.dir/src/handler.cpp.o -c /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/display_server/src/handler.cpp

display_server/CMakeFiles/display_server.dir/src/handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/display_server.dir/src/handler.cpp.i"
	cd /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build/display_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/display_server/src/handler.cpp > CMakeFiles/display_server.dir/src/handler.cpp.i

display_server/CMakeFiles/display_server.dir/src/handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/display_server.dir/src/handler.cpp.s"
	cd /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build/display_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/display_server/src/handler.cpp -o CMakeFiles/display_server.dir/src/handler.cpp.s

# Object files for target display_server
display_server_OBJECTS = \
"CMakeFiles/display_server.dir/src/main.cpp.o" \
"CMakeFiles/display_server.dir/src/handler.cpp.o"

# External object files for target display_server
display_server_EXTERNAL_OBJECTS =

display_server/display_server: display_server/CMakeFiles/display_server.dir/src/main.cpp.o
display_server/display_server: display_server/CMakeFiles/display_server.dir/src/handler.cpp.o
display_server/display_server: display_server/CMakeFiles/display_server.dir/build.make
display_server/display_server: server_lib/libserver_lib.a
display_server/display_server: display_server/CMakeFiles/display_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable display_server"
	cd /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build/display_server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/display_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
display_server/CMakeFiles/display_server.dir/build: display_server/display_server
.PHONY : display_server/CMakeFiles/display_server.dir/build

display_server/CMakeFiles/display_server.dir/clean:
	cd /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build/display_server && $(CMAKE_COMMAND) -P CMakeFiles/display_server.dir/cmake_clean.cmake
.PHONY : display_server/CMakeFiles/display_server.dir/clean

display_server/CMakeFiles/display_server.dir/depend:
	cd /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/display_server /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build/display_server /home/denis/КОВАЛЕНКО_ДЕНИС_C++/test_project/build/display_server/CMakeFiles/display_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : display_server/CMakeFiles/display_server.dir/depend

