# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ludovicarainero/pandemic_SIRD

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ludovicarainero/pandemic_SIRD/build

# Include any dependencies generated for this target.
include CMakeFiles/agent.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/agent.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/agent.dir/flags.make

CMakeFiles/agent.dir/AGENT/main_pandemic.cpp.o: CMakeFiles/agent.dir/flags.make
CMakeFiles/agent.dir/AGENT/main_pandemic.cpp.o: ../AGENT/main_pandemic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ludovicarainero/pandemic_SIRD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/agent.dir/AGENT/main_pandemic.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/agent.dir/AGENT/main_pandemic.cpp.o -c /home/ludovicarainero/pandemic_SIRD/AGENT/main_pandemic.cpp

CMakeFiles/agent.dir/AGENT/main_pandemic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/agent.dir/AGENT/main_pandemic.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ludovicarainero/pandemic_SIRD/AGENT/main_pandemic.cpp > CMakeFiles/agent.dir/AGENT/main_pandemic.cpp.i

CMakeFiles/agent.dir/AGENT/main_pandemic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/agent.dir/AGENT/main_pandemic.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ludovicarainero/pandemic_SIRD/AGENT/main_pandemic.cpp -o CMakeFiles/agent.dir/AGENT/main_pandemic.cpp.s

CMakeFiles/agent.dir/AGENT/pandemic.cpp.o: CMakeFiles/agent.dir/flags.make
CMakeFiles/agent.dir/AGENT/pandemic.cpp.o: ../AGENT/pandemic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ludovicarainero/pandemic_SIRD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/agent.dir/AGENT/pandemic.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/agent.dir/AGENT/pandemic.cpp.o -c /home/ludovicarainero/pandemic_SIRD/AGENT/pandemic.cpp

CMakeFiles/agent.dir/AGENT/pandemic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/agent.dir/AGENT/pandemic.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ludovicarainero/pandemic_SIRD/AGENT/pandemic.cpp > CMakeFiles/agent.dir/AGENT/pandemic.cpp.i

CMakeFiles/agent.dir/AGENT/pandemic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/agent.dir/AGENT/pandemic.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ludovicarainero/pandemic_SIRD/AGENT/pandemic.cpp -o CMakeFiles/agent.dir/AGENT/pandemic.cpp.s

CMakeFiles/agent.dir/AGENT/parameters.cpp.o: CMakeFiles/agent.dir/flags.make
CMakeFiles/agent.dir/AGENT/parameters.cpp.o: ../AGENT/parameters.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ludovicarainero/pandemic_SIRD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/agent.dir/AGENT/parameters.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/agent.dir/AGENT/parameters.cpp.o -c /home/ludovicarainero/pandemic_SIRD/AGENT/parameters.cpp

CMakeFiles/agent.dir/AGENT/parameters.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/agent.dir/AGENT/parameters.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ludovicarainero/pandemic_SIRD/AGENT/parameters.cpp > CMakeFiles/agent.dir/AGENT/parameters.cpp.i

CMakeFiles/agent.dir/AGENT/parameters.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/agent.dir/AGENT/parameters.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ludovicarainero/pandemic_SIRD/AGENT/parameters.cpp -o CMakeFiles/agent.dir/AGENT/parameters.cpp.s

# Object files for target agent
agent_OBJECTS = \
"CMakeFiles/agent.dir/AGENT/main_pandemic.cpp.o" \
"CMakeFiles/agent.dir/AGENT/pandemic.cpp.o" \
"CMakeFiles/agent.dir/AGENT/parameters.cpp.o"

# External object files for target agent
agent_EXTERNAL_OBJECTS =

agent: CMakeFiles/agent.dir/AGENT/main_pandemic.cpp.o
agent: CMakeFiles/agent.dir/AGENT/pandemic.cpp.o
agent: CMakeFiles/agent.dir/AGENT/parameters.cpp.o
agent: CMakeFiles/agent.dir/build.make
agent: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
agent: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
agent: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
agent: CMakeFiles/agent.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ludovicarainero/pandemic_SIRD/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable agent"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/agent.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/agent.dir/build: agent

.PHONY : CMakeFiles/agent.dir/build

CMakeFiles/agent.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/agent.dir/cmake_clean.cmake
.PHONY : CMakeFiles/agent.dir/clean

CMakeFiles/agent.dir/depend:
	cd /home/ludovicarainero/pandemic_SIRD/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ludovicarainero/pandemic_SIRD /home/ludovicarainero/pandemic_SIRD /home/ludovicarainero/pandemic_SIRD/build /home/ludovicarainero/pandemic_SIRD/build /home/ludovicarainero/pandemic_SIRD/build/CMakeFiles/agent.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/agent.dir/depend

