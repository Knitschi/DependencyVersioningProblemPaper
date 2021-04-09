

Common Solutions to the Dependency Versioning Problem
=====================================================

In practice the *dependency versioning problem* is usually solved with one of the following approaches.

#. Static dependency graph. If the components are never changed and updated, the problem never arises.
#. Only one Version. All clients are updated to use the new version of the library at the same time.
#. Compatible Versions. Libraries define multiple versions of a dependency that they can use. A version must be found that satisfies the requirements of all clients.

We will see that all of these solutions have severe disadvantages. This Article is about promoting a fourth solution that
is not widely used. This solution is introduced after the others and I call it here the *coexisting versions* approach.

But let's have a look at the existing solutions...

