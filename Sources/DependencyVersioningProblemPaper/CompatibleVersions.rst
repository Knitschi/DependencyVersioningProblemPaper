Compatible Versions
-------------------

This approach solves the `Dependency Versioning Problem` by allowing the relaxation of version requirements of the individual libraries
by introducing ranges of compatible versions. The definition of the compatibility is usually done via *Semantic Versioning* 
which introduces a three digit version number which could for example look like ``3.17.5`` where the
digits indicate the compatibility between the individual versions. These digits are called the *major*, *minor* and *patch* version (``<major>.<minor>.<patch>``).
Updating a dependency from version ``1.0.0`` to ``2.0.0`` may require changes to the code in the client. 
Updating from ``1.0.0`` to ``1.1.0`` requires a re-compilation of the client, but no changes to the code. 
Upgrading from ``1.0.0`` to ``1.0.1`` can be done by simply exchanging the binary file when the dependency is consumed as a so called dynamic library.

Limiting ourselves to two version digits, our initial dependency graph looks like this:

.. graphviz::
  :align: center
  :name: InitialGraphSemanticVersions
  :caption: Diamond dependency graph with simplified semantic versions

  digraph G {
    graph [bgcolor=transparent]
    node [shape=box width=0.1 height=0.1]
    "libA 1.0" -> "libB1 1.0"
    "libA 1.0" -> "libB2 1.0"
    "libB1 1.0" -> "libC 1.0"
    "libB2 1.0" -> "libC 1.0"
  }

In order to allow more flexibility in the dependency graph, the team working on ``libB2`` can now relax
the version requirement on ``libC`` to only require the major version 1. At the same time, the team working
on ``libC`` needs to provide updates to the *stable* version ``libC 1`` which fulfill the compatibility
promises that are defined by *Semantic Versioning*. 

These extra efforts made by team libC and team libB2 enable team libB1 to update their ``libC`` dependency to the
latest stable version ``1.1`` without breaking the dependency graph for the client ``libA``.

.. graphviz::
  :align: center
  :name: UpdatedGraphSemanticVersions
  :caption: Dependency graph after updating libC

  digraph G {
    graph [bgcolor=transparent]
    node [shape=box width=0.1 height=0.1]
    "libA 1.1" -> "libB1 1.1"
    "libA 1.1" -> "libB2 1.0"
    "libB1 1.1" -> "libC 1.1"
    "libB2 1.0" -> "libC 1.1"
  }

Due to the relaxed version requirements of ``libB2`` on ``libC``, ``libC`` only exists in one version in the dependency tree.
No changes to code of ``libB2`` were necessary.
In the C++ world team libA still has to re-compile and re-link the whole dependency tree after updating to ``libB1 1.1``.

This solution allows team libB1 to update its ``libC`` dependency without the need to coordinate the update with all other
libraries that depend on ``libC`` as long as the update is limited to a later compatible version. Another advantage that
is often mentioned is that this allows providing security patches without even re-compiling and re-deploying the complete
dependency graph. 

The costs for developers of this approach are huge though. First all involved teams need to agree on a way on how to pass on
the compatibility information to clients. In practice this has already happened by agreeing on semantic versioning.
The much harder problem for development teams is to ensure compatibility between versions. Especially ABI compatibility is very easily
broken. Tools like the `ABI Compliance Checker`_ may help to mitigate this problem, but developers are still very constrained on what
they can change while keeping the compatibility promise.

Also note that the *Compatible Versions* approach does not solve the problem in its full extend. What if ``libB1`` wants to upgrade to
a new major version of ``libC``. Then we are back to square one where we need to have two different versions of ``libC`` in the dependency graph.
The problem of finding combinations of versions that do not lead to requirement conflicts is sometimes called *Dependency Hell*.

In practice the *Compatible Versions* approach is used by most open source libraries that are found in the Linux eco-system. 
Here the system package managers manually curate a dependency graph that resolves remaining version conflicts. The same approach is used
by the vcpkg package manager.


.. _ABI Compliance Checker: https://lvc.github.io/abi-compliance-checker/"



