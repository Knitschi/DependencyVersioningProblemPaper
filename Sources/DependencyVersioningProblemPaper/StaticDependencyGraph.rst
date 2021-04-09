

Static dependency graph
-----------------------

With this approach the developers of ``libA`` simply never upgrade to newer versions of ``libB1`` or ``libB2``.
Note that they would still need to find a version of both libraries that use the same version of ``libC``.
Strictly speaking this is not a solution to the problem. It is rather a workaround which nevertheless may sometimes be appropriate
to overcome the problem. However this will usually only work for codebases with smaller dependency graphs and which are only developed
over a small period of time and than are never touched again.
This approach does not work for the general case of the *global* code-base that sees indefinite continuous development. 