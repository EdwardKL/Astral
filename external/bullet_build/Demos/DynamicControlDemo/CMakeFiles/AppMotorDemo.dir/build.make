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
include Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/depend.make

# Include the progress variables for this target.
include Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/progress.make

# Include the compile flags for this target's objects.
include Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/flags.make

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.obj: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/flags.make
Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.obj: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/includes_CXX.rsp
Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.obj: D:/Documents/Astral/external/bullet-2.81-rev2613/Demos/DynamicControlDemo/MotorDemo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report D:\Documents\Astral\external\bullet_build\CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.obj"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\DynamicControlDemo && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\AppMotorDemo.dir\MotorDemo.obj -c D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\DynamicControlDemo\MotorDemo.cpp

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppMotorDemo.dir/MotorDemo.i"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\DynamicControlDemo && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\DynamicControlDemo\MotorDemo.cpp > CMakeFiles\AppMotorDemo.dir\MotorDemo.i

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppMotorDemo.dir/MotorDemo.s"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\DynamicControlDemo && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\DynamicControlDemo\MotorDemo.cpp -o CMakeFiles\AppMotorDemo.dir\MotorDemo.s

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.obj.requires:
.PHONY : Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.obj.requires

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.obj.provides: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.obj.requires
	$(MAKE) -f Demos\DynamicControlDemo\CMakeFiles\AppMotorDemo.dir\build.make Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.obj.provides.build
.PHONY : Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.obj.provides

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.obj.provides.build: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.obj

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.obj: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/flags.make
Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.obj: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/includes_CXX.rsp
Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.obj: D:/Documents/Astral/external/bullet-2.81-rev2613/Demos/DynamicControlDemo/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report D:\Documents\Astral\external\bullet_build\CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.obj"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\DynamicControlDemo && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\AppMotorDemo.dir\main.obj -c D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\DynamicControlDemo\main.cpp

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppMotorDemo.dir/main.i"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\DynamicControlDemo && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\DynamicControlDemo\main.cpp > CMakeFiles\AppMotorDemo.dir\main.i

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppMotorDemo.dir/main.s"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\DynamicControlDemo && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\DynamicControlDemo\main.cpp -o CMakeFiles\AppMotorDemo.dir\main.s

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.obj.requires:
.PHONY : Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.obj.requires

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.obj.provides: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.obj.requires
	$(MAKE) -f Demos\DynamicControlDemo\CMakeFiles\AppMotorDemo.dir\build.make Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.obj.provides.build
.PHONY : Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.obj.provides

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.obj.provides.build: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.obj

# Object files for target AppMotorDemo
AppMotorDemo_OBJECTS = \
"CMakeFiles/AppMotorDemo.dir/MotorDemo.obj" \
"CMakeFiles/AppMotorDemo.dir/main.obj"

# External object files for target AppMotorDemo
AppMotorDemo_EXTERNAL_OBJECTS =

Demos/DynamicControlDemo/AppMotorDemo.exe: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.obj
Demos/DynamicControlDemo/AppMotorDemo.exe: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.obj
Demos/DynamicControlDemo/AppMotorDemo.exe: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/build.make
Demos/DynamicControlDemo/AppMotorDemo.exe: Demos/OpenGL/libOpenGLSupport.a
Demos/DynamicControlDemo/AppMotorDemo.exe: src/BulletDynamics/libBulletDynamics.a
Demos/DynamicControlDemo/AppMotorDemo.exe: src/BulletCollision/libBulletCollision.a
Demos/DynamicControlDemo/AppMotorDemo.exe: src/LinearMath/libLinearMath.a
Demos/DynamicControlDemo/AppMotorDemo.exe: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/objects1.rsp
Demos/DynamicControlDemo/AppMotorDemo.exe: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable AppMotorDemo.exe"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\DynamicControlDemo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AppMotorDemo.dir\link.txt --verbose=$(VERBOSE)
	cd /d D:\Documents\Astral\external\bullet_build\Demos\DynamicControlDemo && "D:\Programs\CMake 2.8\bin\cmake.exe" -E copy_if_different D:/Documents/Astral/external/bullet-2.81-rev2613/GLUT32.DLL D:/Documents/Astral/external/bullet_build/Demos/DynamicControlDemo

# Rule to build all files generated by this target.
Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/build: Demos/DynamicControlDemo/AppMotorDemo.exe
.PHONY : Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/build

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/requires: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/MotorDemo.obj.requires
Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/requires: Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/main.obj.requires
.PHONY : Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/requires

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/clean:
	cd /d D:\Documents\Astral\external\bullet_build\Demos\DynamicControlDemo && $(CMAKE_COMMAND) -P CMakeFiles\AppMotorDemo.dir\cmake_clean.cmake
.PHONY : Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/clean

Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\Astral\external\bullet-2.81-rev2613 D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\DynamicControlDemo D:\Documents\Astral\external\bullet_build D:\Documents\Astral\external\bullet_build\Demos\DynamicControlDemo D:\Documents\Astral\external\bullet_build\Demos\DynamicControlDemo\CMakeFiles\AppMotorDemo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Demos/DynamicControlDemo/CMakeFiles/AppMotorDemo.dir/depend

