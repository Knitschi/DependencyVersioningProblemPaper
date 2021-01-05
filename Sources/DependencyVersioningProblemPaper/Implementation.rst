

Implementing the *Coexisting Versions* approach in a C++ codebase
=================================================================

When using one dependency in multiple versions in a dependency tree in C++ the following problems occur.

* Names of functions and types are ambiguous leading to violations of the *One Definition Rule*.
* Includes are ambiguous.
* Target names in the build-system are ambiguous.
* Locations and/or names of generated binary files are ambiguous.

In this chapter I create an example C++ project that tries to overcome these problems using the tools that
the C++ language, compiler and build-systems have to offer.
In my example I use Git and Git-Submodules to construct a dependency graph that can contain one library in multiple
versions. I use CMake as a (meta) build-system.


 