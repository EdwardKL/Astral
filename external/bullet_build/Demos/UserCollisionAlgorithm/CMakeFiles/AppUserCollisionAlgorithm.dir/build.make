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
include Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/depend.make

# Include the progress variables for this target.
include Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/progress.make

# Include the compile flags for this target's objects.
include Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/flags.make

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/flags.make
Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/includes_CXX.rsp
Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj: D:/Documents/Astral/external/bullet-2.81-rev2613/Demos/UserCollisionAlgorithm/UserCollisionAlgorithm.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report D:\Documents\Astral\external\bullet_build\CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\UserCollisionAlgorithm && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\AppUserCollisionAlgorithm.dir\UserCollisionAlgorithm.obj -c D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\UserCollisionAlgorithm\UserCollisionAlgorithm.cpp

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.i"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\UserCollisionAlgorithm && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\UserCollisionAlgorithm\UserCollisionAlgorithm.cpp > CMakeFiles\AppUserCollisionAlgorithm.dir\UserCollisionAlgorithm.i

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.s"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\UserCollisionAlgorithm && D:\Programs\MinGW\bin\mingw32-g++-4.7.2.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\UserCollisionAlgorithm\UserCollisionAlgorithm.cpp -o CMakeFiles\AppUserCollisionAlgorithm.dir\UserCollisionAlgorithm.s

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj.requires:
.PHONY : Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj.requires

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj.provides: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj.requires
	$(MAKE) -f Demos\UserCollisionAlgorithm\CMakeFiles\AppUserCollisionAlgorithm.dir\build.make Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj.provides.build
.PHONY : Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj.provides

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj.provides.build: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/__/__/build/bullet.obj: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/flags.make
Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/__/__/build/bullet.obj: D:/Documents/Astral/external/bullet-2.81-rev2613/build/bullet.rc
	$(CMAKE_COMMAND) -E cmake_progress_report D:\Documents\Astral\external\bullet_build\CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building RC object Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/__/__/build/bullet.obj"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\UserCollisionAlgorithm && D:\Programs\MinGW\bin\windres.exe  -O coff $(RC_FLAGS) $(RC_DEFINES) D:\Documents\Astral\external\bullet-2.81-rev2613\build\bullet.rc CMakeFiles\AppUserCollisionAlgorithm.dir\__\__\build\bullet.obj

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/__/__/build/bullet.obj.requires:
.PHONY : Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/__/__/build/bullet.obj.requires

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/__/__/build/bullet.obj.provides: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/__/__/build/bullet.obj.requires
	$(MAKE) -f Demos\UserCollisionAlgorithm\CMakeFiles\AppUserCollisionAlgorithm.dir\build.make Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/__/__/build/bullet.obj.provides.build
.PHONY : Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/__/__/build/bullet.obj.provides

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/__/__/build/bullet.obj.provides.build: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/__/__/build/bullet.obj

# Object files for target AppUserCollisionAlgorithm
AppUserCollisionAlgorithm_OBJECTS = \
"CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj" \
"CMakeFiles/AppUserCollisionAlgorithm.dir/__/__/build/bullet.obj"

# External object files for target AppUserCollisionAlgorithm
AppUserCollisionAlgorithm_EXTERNAL_OBJECTS =

Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm.exe: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm.exe: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/__/__/build/bullet.obj
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm.exe: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/build.make
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm.exe: Demos/OpenGL/libOpenGLSupport.a
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm.exe: src/BulletDynamics/libBulletDynamics.a
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm.exe: src/BulletCollision/libBulletCollision.a
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm.exe: src/LinearMath/libLinearMath.a
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm.exe: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/objects1.rsp
Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm.exe: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable AppUserCollisionAlgorithm.exe"
	cd /d D:\Documents\Astral\external\bullet_build\Demos\UserCollisionAlgorithm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\AppUserCollisionAlgorithm.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/build: Demos/UserCollisionAlgorithm/AppUserCollisionAlgorithm.exe
.PHONY : Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/build

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/requires: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/UserCollisionAlgorithm.obj.requires
Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/requires: Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/__/__/build/bullet.obj.requires
.PHONY : Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/requires

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/clean:
	cd /d D:\Documents\Astral\external\bullet_build\Demos\UserCollisionAlgorithm && $(CMAKE_COMMAND) -P CMakeFiles\AppUserCollisionAlgorithm.dir\cmake_clean.cmake
.PHONY : Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/clean

Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Documents\Astral\external\bullet-2.81-rev2613 D:\Documents\Astral\external\bullet-2.81-rev2613\Demos\UserCollisionAlgorithm D:\Documents\Astral\external\bullet_build D:\Documents\Astral\external\bullet_build\Demos\UserCollisionAlgorithm D:\Documents\Astral\external\bullet_build\Demos\UserCollisionAlgorithm\CMakeFiles\AppUserCollisionAlgorithm.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : Demos/UserCollisionAlgorithm/CMakeFiles/AppUserCollisionAlgorithm.dir/depend
