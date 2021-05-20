

Implementing the *Coexisting Versions* approach in a C++ codebase
=================================================================

When using one dependency in multiple versions in a dependency tree in C++ the following problems occur.

* Target names in the build-system are ambiguous.
* Filesystem paths of generated binary files are ambiguous.
* The :code:`#include` directives in the C++ code are ambiguous.
* Names of functions and types are ambiguous leading to violations of the *One Definition Rule*.

In this chapter I first show the basic approach on solving these problems using the tools that
the C++ language, compiler and build-systems have to offer. 
Later I create an example C++ project that implements the described solutions.
In my example I use Git and Git-Submodules to construct a dependency graph that can contain one library in multiple
versions. I use CMake as a (meta) build-system.

The basic idea of solving the problems is to encode the version name into the library name. 
Doing so, we can let the infrastructure treat two versions of the same library as two different libraries.
With this approach we should not need to make any changes to the compiler or build system because
they already support having multiple different libraries in one project.
Here I use underscores and numbers in library names which works in CMake and C++ code.
The versioned naming scheme is then :code:`libA` -> :code:`libA_1_0_0`.

But encoding the version into a library name brings us problems when we want to update the library to
a new version. We now have to find all occurrences of the library name and replace it with the new
versioned name. Finding a solution that reduces the renaming work to a minimum is important to make
this approach usable in practice. I was able to mitigate some of the renaming problems, some I could not
solve in the scope of this investigation.

In order to demonstrate the problems I created a C++ project with a diamond dependency similar
to the dependency graphs that where shown in the first chapters. The following chapter gives
a quick overview 