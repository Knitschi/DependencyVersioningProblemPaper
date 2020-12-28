
Introduction to the Dependency Versioning Problem
=================================================

C++ codebases usually group functionality into libraries. Very commonly needed functionality
is often provided by open source libraries that are then used by many other open source projects.
Companies will then often build their own libraries upon the basis that is formed by open source libraries.
This creates a complex tree of dependencies.

TODO add picture of example tree (maybe generated with conan)

This dependency graph is not controlled by a single organization. Instead there is a large amount of individual developers
or small teams that contribute to open source codebase. Even within companies there is often no global *owner* that can access
and modify all the existing repositories.

This dependency tree is not frozen in time. Libraries are extended and changed all the time which forms a chain of states of the library codebase.
These states are called versions and are usually managed by a Code Versioning System. Clients of the library do not depend on the library but on a certain
version of that library. In the following examples I will use a simple version labeling scheme where each subsequent state of a library is labeled with
an ascending integer.

In the dependency tree it can happen that so-called *diamond* patterns occur. In this situation we have multiple libraries depending on another library.

.. graphviz::
  :align: center
  :name: InitialGraph
  :caption: Diamond dependency graph

  digraph G {
    graph [bgcolor=transparent]
    node [shape=box width=0.1 height=0.1]
    "libA 1" -> "libB1 1"
    "libA 1" -> "libB2 1"
    "libB1 1" -> "libC 1"
    "libB2 1" -> "libC 1"
  }

The `1` is the before mentioned version label of the state of each library. The *Dependency Versioning* problem arises when the new version ``libB1 2`` decides
to depend on the latest version ``2`` of ``libC``. Additionally the developers of ``libA`` decide to update to ``libB1 2`` because it offers some new features
they want to use.

.. graphviz::
  :align: center
  :caption: Updating versions in a diamond dependency graph

  digraph G {
    graph [bgcolor=transparent]
    node [shape=box width=0.1 height=0.1]
    "libA 2" -> "libB1 2"
    "libA 2" -> "libB2 1"
    "libB1 2" -> "libC 2"
    "libB2 1" -> "libC 1"
  }

In a *normal* C++ dependency graph this is not possible if ``libB1`` and ``libB2`` use types from ``libC`` in their public interface due to
name clashes in ``libA`` and the resulting violation of the *One Definition Rule*. Types and functions that are declared with the
same name in ``libC 1`` and ``libC 2`` may have different implementations in both versions.

This means that the developers of ``libA`` can not update to ``libB1 2`` which is a **mayor** problem.
This problem does not only appear in C++ dependency graphs. All languages have to solve it. 
This problem is often called the *Dependency Versioning Problem*


