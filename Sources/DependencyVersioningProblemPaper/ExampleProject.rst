

The Example Project
===================


Build Infrastructure
--------------------

Our build infrastructure needs a way of *acquiring* external libraries, that somehow defines
which version is pulled in. Then there will be some interaction with the build system that somehow finds
the external acquired libraries and integrates them into the build setup.

The C++ ecosystem provides a whole zoo of different build systems and package managers.
Finding solutions for all of them would have been too much work. So my example project
concentrates on one build system and one way of dependency acquisition.

As a build system it uses *CMake* with which I am most familiar.
For dependency acquisition it uses the Git submodules mechanism which is used
to *inline* the external libraries into the host repository.