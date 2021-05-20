
Only one Version
----------------

This approach avoids the situation of different version requirements by updating ``libC`` and the version requirements
in all of its clients at the same time. This may also include changes to client code that adjusts to changes that were
made in ``libC``.
The next state of the diamond graph depicted in figure :ref:`InitialGraph` is then the following graph.

.. graphviz::
  :align: center
  :caption: Updating all versions in a diamond dependency graph at once

  digraph G {
    graph [bgcolor=transparent]
    node [shape=box width=0.1 height=0.1]
    "libA 2" -> "libB1 2"
    "libA 2" -> "libB2 2"
    "libB1 2" -> "libC 2"
    "libB2 2" -> "libC 2"
  }

With this approach it may make sense that the developers that are working on ``libC`` will also execute the updates in the client libraries.
This has the advantage that only one team needs to learn how to adjust client code to the changes in `libC` and libC-team is already
most familiar with the changes that were made to ``libC``.  

This solution requires the existence of a global maintainer who has write access to all the libraries in the dependency tree.
Another big problem is that the update of one library is potentially a global operation. This means that this solution does not scale well for arbitrarily large
code bases. It can also not be used in an heterogeneous environment like the open source codebase, where no all-mighty maintainer exists.
It can work well for smaller codebases where global access is possible.

Note that keeping all libraries in a single *monorepo* effectively implements this solution because the complete state of the dependency graph
advances with a single global version number. A prominent champion of this approach is Google. Google does not only keep their C++ codebase in a
single repository but rather their entire codebase including the sources of all utilized technologies. More about this interesting story can be found
in the book `Software Engineering at Google`_.



.. _Software Engineering at Google: https://www.oreilly.com/library/view/software-engineering-at/9781492082781/

