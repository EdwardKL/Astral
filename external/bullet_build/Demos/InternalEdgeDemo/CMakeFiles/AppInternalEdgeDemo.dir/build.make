# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 2.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Programs\CMake 2.8\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programs\CMake 2.8\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = "D:\Programs\CMake 2.8\bin\cmake-gui.exe"

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Documents\Astral\external\bullet-2.81-rev2613

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Documents\Astral\external\bullet_build

# Include any dependencies generated for this target.
include Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/depend.make

# Include the progress variables for this target.
include Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/progress.make

# Include the compile flags for this target's objects.
include Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/flags.make

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/flags.make
Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/includes_CXX.rsp
Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj: D:/Documents/Astral/external/bullet-2.81-rev2613/Demos/InternalEdgeDemo/InternalEdgeDemo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report D:\Documents\Astral\external\bullet_build\CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\InternalEdgeDemo && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\AppInternalEdgeDemo.dir\InternalEdgeDemo.obj -c D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\InternalEdgeDemo\InternalEdgeDemo.cpp

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.i"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\InternalEdgeDemo && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\InternalEdgeDemo\InternalEdgeDemo.cpp > CMakeFiles\AppInternalEdgeDemo.dir\InternalEdgeDemo.i

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.s"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\InternalEdgeDemo && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\InternalEdgeDemo\InternalEdgeDemo.cpp -o CMakeFiles\AppInternalEdgeDemo.dir\InternalEdgeDemo.s

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj.requires:
.PHONY : Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj.requires

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj.provides: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj.requires
	$(MAKE) -f Demos\InternalEdgeDemo\CMakeFiles\AppInternalEdgeDemo.dir\build.make Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj.provides.build
.PHONY : Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj.provides

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj.provides.build: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.obj: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/flags.make
Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.obj: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/includes_CXX.rsp
Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.obj: D:/Documents/Astral/external/bullet-2.81-rev2613/Demos/InternalEdgeDemo/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report D:\Documents\Astral\external\bullet_build\CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.obj"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\InternalEdgeDemo && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\AppInternalEdgeDemo.dir\main.obj -c D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\InternalEdgeDemo\main.cpp

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppInternalEdgeDemo.dir/main.i"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\InternalEdgeDemo && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\InternalEdgeDemo\main.cpp > CMakeFiles\AppInternalEdgeDemo.dir\main.i

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppInternalEdgeDemo.dir/main.s"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\InternalEdgeDemo && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\InternalEdgeDemo\main.cpp -o CMakeFiles\AppInternalEdgeDemo.dir\main.s

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.obj.requires:
.PHONY : Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.obj.requires

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.obj.provides: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.obj.requires
	$(MAKE) -f Demos\InternalEdgeDemo\CMakeFiles\AppInternalEdgeDemo.dir\build.make Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.obj.provides.build
.PHONY : Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.obj.provides

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.obj.provides.build: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.obj

# Object files for target AppInternalEdgeDemo
AppInternalEdgeDemo_OBJECTS = \
"CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj" \
"CMakeFiles/AppInternalEdgeDemo.dir/main.obj"

# External object files for target AppInternalEdgeDemo
AppInternalEdgeDemo_EXTERNAL_OBJECTS =

Demos/InternalEdgeDemo/AppInternalEdgeDemo.exe: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj
Demos/InternalEdgeDemo/AppInternalEdgeDemo.exe: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.obj
Demos/InternalEdgeDemo/AppInternalEdgeDemo.exe: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/build.make
Demos/InternalEdgeDemo/AppInternalEdgeDemo.exe: Demos/OpenGL/libOpenGLSupport.a
Demos/InternalEdgeDemo/AppInternalEdgeDemo.exe: src/BulletDynamics/libBulletDynamics.a
Demos/InternalEdgeDemo/AppInternalEdgeDemo.exe: src/BulletCollision/libBulletCollision.a
Demos/InternalEdgeDemo/AppInternalEdgeDemo.exe: src/LinearMath/libLinearMath.a
Demos/InternalEdgeDemo/AppInternalEdgeDemo.exe: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/objects1.rsp
Demos/InternalEdgeDemo/AppInternalEdgeDemo.exe: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable AppInternalEdgeDemo.exe"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\InternalEdgeDemo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AppInternalEdgeDemo.dir\link.txt --verbose=$(VERBOSE)
	cd /d D:\Documents\Astral\external\bullet_build\Demos\InternalEdgeDemo && "D:\Programs\CMake 2.8\bin\cmake.exe" -E copy_if_different D:/Documents/Astral/external/bullet-2.81-rev2613/GLUT32.DLL D:/Documents/Astral/external/bullet_build/Demos/InternalEdgeDemo

# Rule to build all files generated by this target.
Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/build: Demos/InternalEdgeDemo/AppInternalEdgeDemo.exe
.PHONY : Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/build

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/requires: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/InternalEdgeDemo.obj.requires
Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/requires: Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/main.obj.requires
.PHONY : Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/requires

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/clean:
	cd /d D:\Documents\Astral\external\bullet_build\Demos\InternalEdgeDemo && $(CMAKE_COMMAND) -P CMakeFiles\AppInternalEdgeDemo.dir\cmake_clean.cmake
.PHONY : Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/clean

Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\Astral\external\bullet-2.81-rev2613 D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\InternalEdgeDemo D:\Documents\Astral\external\bullet_build D:\Documents\Astral\external\bullet_build\Demos\InternalEdgeDemo D:\Documents\Astral\external\bullet_build\Demos\InternalEdgeDemo\CMakeFiles\AppInternalEdgeDemo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Demos/InternalEdgeDemo/CMakeFiles/AppInternalEdgeDemo.dir/depend

