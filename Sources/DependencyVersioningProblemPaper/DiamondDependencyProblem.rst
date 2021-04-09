

The Diamond Dependency Problem
------------------------------

In the following examples I will use a simple version labeling scheme where each subsequent state of a library is labeled with
an ascending integer.

In an arbitrary dependency tree it can happen that so-called *diamond* patterns occur. In this situation we have multiple libraries depending on another library.

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

The `1` is the version label of the state of each library. The *dependency versioning* problem arises when the new version ``libB1 2`` decides
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

This means that in this situation the developers of ``libA`` are prohibited from updating ``libB1 1`` to ``libB1 2``.
This can be a **mayor** problem.
This problem is often called the *dependency versioning problem* and it does not only appear in C++ dependency graphs.
All languages that allow the consumption of libraries have to solve it.