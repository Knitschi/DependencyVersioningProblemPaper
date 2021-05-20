

The Example Project
===================

In order to get some substance on which I can demonstrate my work on the *Coexisting Versions* approach, I created a C++ project with
a diamond dependency. C++ offers many ways for setting up a project so I need to introduce my specific way here.
The corner stones of my project setup are:

* The project uses Git and Git submodules for dependency acquisition.
* The project uses CMake as meta build system.
* The project uses the CPFCMake library for reducing the amount of code in *CMakeLists* files. 

I use these technologies in the example because those are the tools because they are the
ones I am most familiar with.
First I introduce the project setup without versioned dependency names as a starting point.
Later chapters will then demonstrate the problems that arise when we integrate versions into library
names.

The example project is available on my Github section. You can download it with

:code:`git clone --recursive https://github.com/Knitschi/DvpA.git`


Library Structure
-----------------

My example contains libraries that are similar to the dependency trees that are shown in the
chapters that introduce the diamond dependency problem. It adds the extra executable :code:`DvpA` at the
top of the dependency graph that can be run to ensure that everything works. The dependency
tree of the project looks like this.

.. graphviz::
  :align: center
  :name: DependencyGraphExample

  digraph G {
    graph [bgcolor=transparent]
    "DvpA" [shape = ellipse width=0.1 height=0.1]
    node [shape=box width=0.1 height=0.1]
    compound=true;
    subgraph clusterA
    {
        style=dashed
        DvpA -> libDvpA;
    }
    subgraph clusterB1
    {
        style=dashed
        libDvpB1
    }
    subgraph clusterB2
    {
        style=dashed
        libDvpB2
    }
    subgraph clusterC
    {
        style=dashed
        libDvpC
    }
    libDvpA -> libDvpB1;
    libDvpA -> libDvpB2;
    libDvpB1 -> libDvpC;
    libDvpB2 -> libDvpC;
  }

.. graphviz::
    :align: center
    :name: DependencyGraphExampleLegend
    :caption: Dependency Graph and Repository Structure of the Example Project

    digraph G {
        graph [bgcolor=transparent]
        color = black;
        edge [ style = invis ];
        legendNode0 [ label = "Executable", shape = ellipse ];
        legendNode1 [ label = "Shared Library", shape = rectangle ];
        legendNode2 [ label = "Repository", shape = rectangle, style=dashed ];
    }

The *dvp* stands for *dependency versioning problem*. I just added this to get more distinctive repository names
for my Github account.

In this setup *libDvpA* stands for the library that we are working on. *libDvpB1*, *libDvpB2* and *libDvpC*
are considered as external libraries. At the beginning *libDvpB1* and *libDvpB2* use the same version of library
*libDvpC*.


Repository and Dependency Acquisition
-------------------------------------

Our project needs a way of pulling in the dependencies. In this first approach I decided
to use a Git as a repository for my example and use the git submodules feature to pull in 
the dependencies. This means that *libDvpA* lives in the *host repository* which pulls in
the other library repositories via the Git submodule mechanism. When cloning the host repository
we need to use thee :code:`--recursive` option in order to get all the dependencies.
Using the Git submodule mechanism just adds the sources of the dependencies to a subdirectory
in the host project. The host repository also keeps track at which revision/version the
subrepositories should be checked out.

For now I have not investigated a soluting using a package manager to allow the consumption
of the external libraries as binary packages.


CMake Setup
-----------

The example project uses CMake as a build system. Additionally it uses packages from
my `CMakeProjectFramework`_ (CPF) project which mainly provides higher level
CMake functions to reduce repetitive code in *CMakeLists* files. This makes the example more
complicated, but it gives me a place where I can implement helper functionality when implementing
the versioned library names solution.

The *CPF* already supports a project layout where external libraries can be pulled in with
git submodules. The host repository contains a :code:`packages.cmake` file that lists
the added libraries.

.. literalinclude:: Example0/packages.cmake
    :language: cmake
    :linenos:

The root *CMakeLists* file contains a call to the function :code:`cpfAddPackages()` which
will internally read the names of the packages that are listed in the :code:`packages.cmake` file
and add them to the project.

.. literalinclude:: Example0/CMakeLists.txt
    :language: cmake
    :linenos:

In the *CPF* each package has another *CMakeLists* file that describes the content of
the package. The package *CMakeLists* file for the top level package *DvpA* looks like this

.. literalinclude:: Example0/DvpA/CMakeLists.txt
    :language: cmake
    :linenos:

The :code:`cpfInitPackageProject()` reads the version of the package from tags
of the Git repository that contains the package. It also reads the name of the
package directory and uses it as a name for the main target of the package.
This will be relevant when we need to add the version to the target names.
Then we have the usual lists of source files.
At the end we see a call to the :code:`cpfAddCppPackage()` which internally
adds the executable *DvpA* and the shared library *libDvpA*.
The argument :code:`LINKED_LIBRARIES PRIVATE dvpLibB1 dvpLibB2` tells CMake
that we want to use functionality from the libraries *dvpLibB1* and *dvpLibB2*
in libDvpA.

The *CMakeLists* files of the other library packages look almost the same.

.. literalinclude:: Example0/libDvpB1/CMakeLists.txt
    :language: cmake
    :linenos:

.. literalinclude:: Example0/libDvpB2/CMakeLists.txt
    :language: cmake
    :linenos:

.. literalinclude:: Example0/libDvpC/CMakeLists.txt
    :language: cmake
    :linenos:



.. _CMakeProjectFramework: https://github.com/Knitschi/CMakeProjectFramework


Library Content
---------------

asdfa




