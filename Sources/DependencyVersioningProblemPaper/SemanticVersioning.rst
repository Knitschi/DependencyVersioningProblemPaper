Semantic Versioning
-------------------

This approach solves the `Dependency Versioning Problem` by allowing the relaxation of version requirements of the individual libraries
by introducing ranges of compatible versions. *Semantic Versioning* introduces a three digit version number which could for example look like ``3.17.5`` where the
digits indicate the compatibility between the individual versions. These digits are called the *major*, *minor* and *patch* version (``<major>.<minor>.<patch>``).
Updating a dependency from version ``1.0.0`` to ``2.0.0`` may require changes to the code in the client. 
Updating from ``1.0.0`` to ``1.1.0`` requires a re-compilation of the client, but no changes to the code. 
Upgrading from ``1.0.0`` to ``1.0.1`` can be done by simply exchanging the binary file when the dependency is consumed as a so called dynamic library.

With this versioning scheme our initial dependency tree would look like this:

.. graphviz::
  :align: center
  :name: InitialGraphSemanticVersions
  :caption: Diamond dependency graph

  digraph G {
    graph [bgcolor=transparent]
    node [shape=box width=0.1 height=0.1]
    "libA 1.0.0" -> "libB1 1.0.0"
    "libA 1.0.0" -> "libB2 1.0.0"
    "libB1 1.0.0" -> "libC 1.0.0"
    "libB2 1.0.0" -> "libC 1.0.0"
  }


With this system, the version requirements of ``libB1`` for ``libC`` would be relaxed by only requiring libC 1