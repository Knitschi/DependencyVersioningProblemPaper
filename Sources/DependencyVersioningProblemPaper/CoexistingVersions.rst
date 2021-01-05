
Coexisting Versions
-------------------

The solutions to the *Dependency Versioning Problem* that were discussed in the previous chapters all have some major drawbacks
which prevent them from scaling to support the global codebase. There is a fourth solution though that is currently not widely used,
but which does not suffer from the problems of the usual solutions. 

Why not allow multiple versions of a dependency to coexist in the dependency graph?

.. graphviz::
  :align: center
  :caption: Allowing multiple versions of a dependency

  digraph G {
    graph [bgcolor=transparent]
    node [shape=box width=0.1 height=0.1]
    "libA 2" -> "libB1 2"
    "libA 2" -> "libB2 1"
    "libB1 2" -> "libC 2"
    "libB2 1" -> "libC 1"
  }

With this approach the above pictured dependency graph would compile and lead to no undefined behavior.
This solution allows each library to update their dependencies independent of any other library in the full dependency graph.
It removes the need for either executing global updates or finding and maintaining compatible versions. The only drawback
is that it increases binary size. But modern linkers may be able to remove function definitions that are duplicated by 
multiple versions of a library. (TODO Check if that really happens when activating full program optimization)

The *Coexisting Versions* approach is currently already supported by the Rust ecosystem. See `How Rust Solved Dependency Hell`_ and
`The Cargo Book, Chapter Dependency Resolution`_ for more information about that. According to the article, Rust encodes the version information
into the mangled names of the linked binaries to resolve ambiguous names.

In the C++ ecosystem, having one dependency in multiple versions in a dependency graph is not possible by default. It causes problems due to
ambiguous names during compilation, linking and in makefiles.

In the next chapter I create an example C++ project that tries to overcome these problems in order to arrive at an design that allows
multiple versions of one library to exist in a single dependency graph.


.. _The Cargo Book, Chapter Dependency Resolution: "https://doc.rust-lang.org/cargo/reference/resolver.html"
.. _How Rust Solved Dependency Hell: "https://stephencoakley.com/2019/04/24/how-rust-solved-dependency-hell"