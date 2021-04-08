

Common Solutions to the Dependency Versioning Problem
=====================================================

In practice the *dependency versioning problem* is usually solved with one of the following approaches.

#. Static dependency graph. If the components are never changed and updated, the problem never arises.
#. Only one Version. All clients are updated to use the new version of the library at the same time.
#. Compatible Versions. Libraries define multiple versions of a dependency that they can use. A version must be found that satisfies the requirements of all clients.

The following sections take a closer look at these approaches and their caveats.


Static dependency graph
-----------------------

With this approach the developers of ``libA`` simply never upgrade to newer versions of ``libB1`` or ``libB2``.
Note that they would still need to find a version of both libraries that use the same version of ``libC``.
Strictly speaking this is not a solution to the problem. It is rather a workaround which nevertheless may sometimes be appropriate
to overcome the problem. However this will usually only work for codebases with smaller dependency graphs and which are only developed
over a small period of time and than are never touched again.
This approach does not work for the general case of the *global* code-base that sees indefinite continuous development. 

