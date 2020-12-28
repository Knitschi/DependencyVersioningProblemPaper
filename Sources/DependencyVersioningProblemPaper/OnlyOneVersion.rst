
Only one Version
----------------

When a new version of ``libC`` is published, all the clients in the
dependency graph are updated at the same time to use the new version of ``libC``.
The next state of the global codebase following the sitionation in figure :ref:`InitialGraph`
is than the follwing graph.

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
This has the advantage that only one team needs to learn how to adjust client code to the changes in `libC` and it is the team that already
is most familiar with the changes in ``libC``.  

This solution requires the existence of a global maintainer who has write access to all the libraries in the dependency tree.
Another big problem is that the update of one library is a global operation. This means that it will not scale for arbitrarily large
code bases. In my opinion, both of these requirements make it 

This approach is also called the monorepo approach because when it is used the whole codebase can be in a single monolythic repository that
advances with a single global version number. A prominent champion of this approach is Google. Google does not only keep their C++ codebase in a
single repository but rather their entire codebase including the sources of all utilized technologies. More about this interesting story can be found
in the book `Software Engineering at Google`_.



.. _Software Engineering at Google: https://www.oreilly.com/library/view/software-engineering-at/9781492082781/"

