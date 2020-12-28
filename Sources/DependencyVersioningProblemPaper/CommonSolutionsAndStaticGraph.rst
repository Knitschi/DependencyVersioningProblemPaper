

Common Solutions to the Dependency Versioning Problem
=====================================================

In practice there are currently three ways to solve the *Dependency Versioning Problem*.

#. Static dependency graph. If the components are never changed and updated, the problem never arises.
#. Only one Version. All clients are updated to use the new version of the library at the same time.
#. Compatible Versions. Libraries define multiple versions of a dependency that they can use. A version must be found that satisfies the requirements of all clients.
 
 
Static dependency graph
-----------------------

With this approach the developers of ``libA`` simply never upgrade to newer versions of ``libB1`` or ``libB2``.
Note that they would still need to find a version of both libraries that use the same version of ``libC``.
Strictly speaking this is not a solution to the problem. It is rather a workaround which nevertheless may sometimes be appropriate
to overcome the problem. However this will usually only work for codebases with smaller dependency graphs and which are only developed
over a small time-period and than are never touched again.
This approach does not work for the general case of the *global* code-base that sees indefinite continuous development. 

