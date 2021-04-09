

Implementing the *Coexisting Versions* approach in a C++ codebase
=================================================================

When using one dependency in multiple versions in a dependency tree in C++ the following problems occur.

* Target names in the build-system are ambiguous.
* Locations and/or names of generated binary files are ambiguous.
* Includes are ambiguous.
* Names of functions and types are ambiguous leading to violations of the *One Definition Rule*.


In this chapter I first show the basic approach on solving these problems using the tools that
the C++ language, compiler and build-systems have to offer. 
Later I create an example C++ project that implements the described solutions.
In my example I use Git and Git-Submodules to construct a dependency graph that can contain one library in multiple
versions. I use CMake as a (meta) build-system.

The basic idea of solving the problems is to encode the version name into the library name. Doing so, we
can let the infrastructure treat two versions of the same library as two different libraries.
With this approach we should not need to make any changes to the compiler or build system because
they already support having multiple libraries in one project.
But encoding the version into a library name also brings many problems. First off all we will need to change
all occurrences of the library name and related names throughout the whole project whenever we update the version.
When we use a code versioning system, the version is incremented whenever we make a commit to the CVS.
With Git we only know the new version identifier (commit hash) after we made the commit, so how can we embed it into
the library's name before we make that commit?

While the approach of embedding the version into the library's name is simple. Making it work in practice is not.
The rest of this article will describe the solutions that I found for the resulting problems and what problems
remain unsolved.


 





