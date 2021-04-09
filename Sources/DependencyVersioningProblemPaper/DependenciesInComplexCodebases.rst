

Dependencies in Complex Codebases
---------------------------------

C++ codebases usually group functionality into libraries. Very commonly needed functionality
is often provided by open source libraries that are then used by many other open source projects.
Companies will then often build their own libraries upon the basis that is formed by the open source libraries.
This creates a complex tree of dependencies.

TODO add picture of example tree (maybe generated with conan)

This global dependency graph is not controlled by a single organization. Instead there is a large amount of individual developers
or small teams that contribute to the global open source codebase. Even within companies there is often no global *owner* who can access
and modify all the existing repositories. 

The global codebase is also not frozen in time. Libraries are extended and changed all the time.
These changes form a chain of states of the library. The individual states in time are usually called versions
and are often managed by a *code versioning system*. Consumers of a library have to select a version of
that library when using it in their own code to make sure they get the expected APIs and behavior.