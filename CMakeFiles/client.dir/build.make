# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/sebastian/Documents/tp4-grupal-7542-2c2017

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sebastian/Documents/tp4-grupal-7542-2c2017

# Include any dependencies generated for this target.
include CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/src/client/StartWindow.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/client/StartWindow.cpp.o: src/client/StartWindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/Documents/tp4-grupal-7542-2c2017/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client.dir/src/client/StartWindow.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/client/StartWindow.cpp.o -c /home/sebastian/Documents/tp4-grupal-7542-2c2017/src/client/StartWindow.cpp

CMakeFiles/client.dir/src/client/StartWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/client/StartWindow.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/Documents/tp4-grupal-7542-2c2017/src/client/StartWindow.cpp > CMakeFiles/client.dir/src/client/StartWindow.cpp.i

CMakeFiles/client.dir/src/client/StartWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/client/StartWindow.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/Documents/tp4-grupal-7542-2c2017/src/client/StartWindow.cpp -o CMakeFiles/client.dir/src/client/StartWindow.cpp.s

CMakeFiles/client.dir/src/client/StartWindow.cpp.o.requires:

.PHONY : CMakeFiles/client.dir/src/client/StartWindow.cpp.o.requires

CMakeFiles/client.dir/src/client/StartWindow.cpp.o.provides: CMakeFiles/client.dir/src/client/StartWindow.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/StartWindow.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/src/client/StartWindow.cpp.o.provides

CMakeFiles/client.dir/src/client/StartWindow.cpp.o.provides.build: CMakeFiles/client.dir/src/client/StartWindow.cpp.o


CMakeFiles/client.dir/src/client/main.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/client/main.cpp.o: src/client/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/Documents/tp4-grupal-7542-2c2017/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/client.dir/src/client/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/client/main.cpp.o -c /home/sebastian/Documents/tp4-grupal-7542-2c2017/src/client/main.cpp

CMakeFiles/client.dir/src/client/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/client/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/Documents/tp4-grupal-7542-2c2017/src/client/main.cpp > CMakeFiles/client.dir/src/client/main.cpp.i

CMakeFiles/client.dir/src/client/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/client/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/Documents/tp4-grupal-7542-2c2017/src/client/main.cpp -o CMakeFiles/client.dir/src/client/main.cpp.s

CMakeFiles/client.dir/src/client/main.cpp.o.requires:

.PHONY : CMakeFiles/client.dir/src/client/main.cpp.o.requires

CMakeFiles/client.dir/src/client/main.cpp.o.provides: CMakeFiles/client.dir/src/client/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/client/main.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/src/client/main.cpp.o.provides

CMakeFiles/client.dir/src/client/main.cpp.o.provides.build: CMakeFiles/client.dir/src/client/main.cpp.o


CMakeFiles/client.dir/src/common/Thread.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/common/Thread.cpp.o: src/common/Thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/Documents/tp4-grupal-7542-2c2017/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/client.dir/src/common/Thread.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/common/Thread.cpp.o -c /home/sebastian/Documents/tp4-grupal-7542-2c2017/src/common/Thread.cpp

CMakeFiles/client.dir/src/common/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/common/Thread.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/Documents/tp4-grupal-7542-2c2017/src/common/Thread.cpp > CMakeFiles/client.dir/src/common/Thread.cpp.i

CMakeFiles/client.dir/src/common/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/common/Thread.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/Documents/tp4-grupal-7542-2c2017/src/common/Thread.cpp -o CMakeFiles/client.dir/src/common/Thread.cpp.s

CMakeFiles/client.dir/src/common/Thread.cpp.o.requires:

.PHONY : CMakeFiles/client.dir/src/common/Thread.cpp.o.requires

CMakeFiles/client.dir/src/common/Thread.cpp.o.provides: CMakeFiles/client.dir/src/common/Thread.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/common/Thread.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/src/common/Thread.cpp.o.provides

CMakeFiles/client.dir/src/common/Thread.cpp.o.provides.build: CMakeFiles/client.dir/src/common/Thread.cpp.o


CMakeFiles/client.dir/src/common/Socket.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/common/Socket.cpp.o: src/common/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sebastian/Documents/tp4-grupal-7542-2c2017/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/client.dir/src/common/Socket.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/common/Socket.cpp.o -c /home/sebastian/Documents/tp4-grupal-7542-2c2017/src/common/Socket.cpp

CMakeFiles/client.dir/src/common/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/common/Socket.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sebastian/Documents/tp4-grupal-7542-2c2017/src/common/Socket.cpp > CMakeFiles/client.dir/src/common/Socket.cpp.i

CMakeFiles/client.dir/src/common/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/common/Socket.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sebastian/Documents/tp4-grupal-7542-2c2017/src/common/Socket.cpp -o CMakeFiles/client.dir/src/common/Socket.cpp.s

CMakeFiles/client.dir/src/common/Socket.cpp.o.requires:

.PHONY : CMakeFiles/client.dir/src/common/Socket.cpp.o.requires

CMakeFiles/client.dir/src/common/Socket.cpp.o.provides: CMakeFiles/client.dir/src/common/Socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/client.dir/build.make CMakeFiles/client.dir/src/common/Socket.cpp.o.provides.build
.PHONY : CMakeFiles/client.dir/src/common/Socket.cpp.o.provides

CMakeFiles/client.dir/src/common/Socket.cpp.o.provides.build: CMakeFiles/client.dir/src/common/Socket.cpp.o


# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/src/client/StartWindow.cpp.o" \
"CMakeFiles/client.dir/src/client/main.cpp.o" \
"CMakeFiles/client.dir/src/common/Thread.cpp.o" \
"CMakeFiles/client.dir/src/common/Socket.cpp.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client: CMakeFiles/client.dir/src/client/StartWindow.cpp.o
client: CMakeFiles/client.dir/src/client/main.cpp.o
client: CMakeFiles/client.dir/src/common/Thread.cpp.o
client: CMakeFiles/client.dir/src/common/Socket.cpp.o
client: CMakeFiles/client.dir/build.make
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sebastian/Documents/tp4-grupal-7542-2c2017/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client

.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/requires: CMakeFiles/client.dir/src/client/StartWindow.cpp.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/src/client/main.cpp.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/src/common/Thread.cpp.o.requires
CMakeFiles/client.dir/requires: CMakeFiles/client.dir/src/common/Socket.cpp.o.requires

.PHONY : CMakeFiles/client.dir/requires

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	cd /home/sebastian/Documents/tp4-grupal-7542-2c2017 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sebastian/Documents/tp4-grupal-7542-2c2017 /home/sebastian/Documents/tp4-grupal-7542-2c2017 /home/sebastian/Documents/tp4-grupal-7542-2c2017 /home/sebastian/Documents/tp4-grupal-7542-2c2017 /home/sebastian/Documents/tp4-grupal-7542-2c2017/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client.dir/depend

