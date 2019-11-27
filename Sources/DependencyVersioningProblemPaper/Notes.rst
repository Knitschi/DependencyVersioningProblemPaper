How do Conan or vcpkg handle compatibility schemes?
===================================================

How does a package specify to which other versions of itself it is compatible?
Is it possible to provide an exact list of compatible versions instead of semver rules or ranges?
Are their any other common formats of specifying dependencies and compatibilites in the C++ world?


I think that a fully automated solution would require a format that allows to specify a list of compatible versions for each dependency.
Should this list be maintained by the client or the dependency?

What format of dependency specification should be used in the CPF?
Do we need to support multiple formats for multiple package manager?

Answers
-------

* It looks like one vcpkg instance can only have one version of a dependency. There seems to be
no mechanism for handling compatible versions. 

* Conan allows to specify ranges of depended on versions, which but it does not work for custom version formats.
However version specification expressions can be "ored" and I should check if that can be used to define a list
of allowed versions.
https://docs.conan.io/en/latest/versioning/version_ranges.html
Conan does not compute a "joint" compatibility, it will use the version from the most down-stream requirement.
It should be possible though to optian all requirements using conan and implement that functionality.
Alternatively one could try to convince the conan guys to implement it :).


Questions for Conan
===================

* How does configuration information get from the profile files in ~/.conan/profiles/
into the cmake project? Must be via conanbuildinfo.cmake


Ideas for automated compatibility determination
===============================================

Package side tests and compatiblity list
----------------------------------------

The package must provide *Specification-Tests* for its public interface.
If Specification-Tests of version A are passed by version B, we define that B is compatible
and version A can be replaced by version B. The extent of the tests will then determine
how true the compatibility statement really is.

The CI system of the package then has to check combinations tests versions and production code versions
and production code versions against each other to create the compatiblity list.

In the C++ world we have to consider the two kinds of compatibility.
API and ABI compatibility. To check the first we need to replace the source code
of the package and the tests. To check the seconds it is enough to exange the shared
libraries of the production package that are loaded by the test executable. Maybe it
would be necessary to run the tests and libraries with some sort of runtime code analysis
like an address sanitizer in order to detect problems that result from binary incompatibility.

Disadvantage:
The compatibilty list does not reflect the clients use-case. This means
that it may not include versions that could be compatible for the client,
or it may include versions that are not compatilbe for the client because
the client relies on "unspecified" behavior.


Package side tests and compatiblity list
----------------------------------------

However in praxis a package client is more interested if package versions are compatible
to his use-case, which may be more or less restricting than the tests that are provided
by the package itself.

In this case the CI-system would need to compile different package versions against the
clients production code and run the tests of the clients production code.
Would we need to do this for several combinations of package versions if multiple
dependencies are involved?

Disadvantage:
This would require more compute resources as every client needs to run their own
compatibility checks. This may take too much time to be practicable.



Is compatibility transitive?
============================

Case 1: -> Not the case if tests change in any of the version increments.
    * A has function that takes 10 seconds and test requires 15 seconds.
    * B improves performance to 5 seconds and changes test to require 7 seconds.
    * C makes any other unrelated compatible change.
    -> A will not pass the tests of C.

If tests do not change between versions, then compatibility is transitive.
(If tests of A and B are the same, C will pass also the tests of A if it passes the tests of B)

