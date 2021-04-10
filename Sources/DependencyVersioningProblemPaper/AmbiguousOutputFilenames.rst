

Resolving Ambiguous Output Filenames
====================================

On Windows systems it is common to deploy shared libraries to the same directory that also holds the executable of
a program. In this scenario we need to make sure that the ``.dll`` files of one library in different versions
have different names.

On Linux shared libraries are often deployed to one system directory and therefor usually already contain the version
number in their name to prevent name clashes between files of different versions of a library.

In the example project we do not need to do anything to achieve that when we encode the version into the target names
because the target names are already a part of the output filename.




