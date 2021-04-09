

Resolving Ambiguous Library Names in the Build Infrastructure
=============================================================

In CMake a library would be represented with the more general concept of a *target* (as in *generated target file*), so I will speak of targets
from here on. Targets can have a version, but there can not be two targets with the same name in a CMake project.

As described in the introduction, the basic approach is to encode the version into the library/target name.
This must happen in a way that the result is a valid CMake target name. So the usual ``.`` characters that
separate the parts of a version number are not allowed. For now I simply replace dots with underscores.
The target name for *dvpLibC 1.0.0* will then become ``dvpLibC_1_0_0``. I also use this transformation
scheme in the C++ code.

The problem with encoding the version into the target name is, that we need to change the target names
in our ``CMakeLists.txt`` files whenever the version changes. In a real project it must be possible
to do this with minimal effort or developers will get angry very quickly. In an ideal world we
would have tooling that requires a single command line call for incrementing the version of dependency.
All renaming of targets would than happen automatically.

For now my efforts did not go that far. I only tried to reduce the amount of work that is required for
incrementing the version of a dependency as much as possible.

In my `CMakeProjectFramework <https://github.com/Knitschi/CMakeProjectFramework>`_ based example project, the name of a library is derived from the name
of the directory that holds it's files.  

Currently the following steps need to be done

Library
* Create versions tag and push it. (will this alone provide the correct generated .h files?)

Client
* Update Git submodule
* Rename directory of git submodule.
* Change target name in CMakeLists.txt. This includes the packages.cmake file and the places where the library is used.

