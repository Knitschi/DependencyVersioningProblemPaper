


*Coexisting Versions* as a Solution to the Dependency Versioning Problem in C++
###############################################################################

This article is still work in progress.


Abstract
********

In large software systems, codebases are usually composed of many libraries that form a complex dependency graph.
Often one library is used by many other libraries which sometimes is called a diamond dependency.
The *Dependency Versioning Problem* arises when one of the libraries in the tree is changed which means that a new version of the library is created.
In this situation at one of the clients requires the new version of library, while others still require the old version.
Currently the industry mainly uses 3 different approaches to work around this problem:

#. Static dependency tree. If the components are never changed and updated, the problem never arises.
#. Only one Version. All clients are updated to use the new version of the library at the same time.
#. Semantic Versioning. Libraries define multiple versions of a dependency that they can use. A version must be found that satisfies the requirements of all clients.

There is a fourth solution that has not been much discussed yet. Allow the library to exist in multiple versions in the dependency tree. This I call the *Coexisting Versions* approach.

This article discusses the advantages and disadvantages of these approaches and explores how the *Coexisting Versions* can be implemented in a C++ codebase.


Index
*****

.. toctree::
  :maxdepth: 2

  Problem
  CommonSolutionsAndStaticGraph
  OnlyOneVersion
  CompatibleVersions
  Implementation
  Conclusions
  References


