Notes on the "Versions are different dependencies" experiment
=============================================================

Operations for adding the version number as a postfix to the package name and namespaces
----------------------------------------------------------------------------------------

Switch submodule directories to one that contains the version.

.. code-block::

    git mv Sources/dvpLibC Sources/dvpLibC_1_0_0
    git mv Sources/dvpLibB1 Sources/dvpLibB1_2_0_0
    git mv Sources/dvpLibB2 Sources/dvpLibB2_1_0_0

-> Internal packages must not be post-fixed with a version number because they can only occur in one version.

Change the variable names in the :code:`packages.cmake` file.

.. code-block::

    # file packages.cmake

    set( CPF_PACKAGES 
	    EXTERNAL CPFCMake
        EXTERNAL CPFBuildscripts
        EXTERNAL dvpLibC_1_0_0
        EXTERNAL dvpLibB1_2_0_0
        EXTERNAL dvpLibB2_1_0_0
        OWNED dvpLibA
    )

Update target references in LINKED_LIBS lists.

Change all the includes to the target names with the version numbers.

Append the version to the namespaces. VSAssist failed to rename the namespace usages in front of the function calls.

At this point the project should build.

Problems:
    - A version can no longer be simply set by adding a tag to a commit, because the commit must already contain the version in the source code.


Operations for globally incrementing the version number of dvpLibC_1_0_0 to dvpLibC_1_1_0
--------------------------------------------------------------------------------

This documents what needs to be done to update the version of dvpLibC for all dependencies at the same time.

Rename the namespace.
Rename the external directory.
Update all includes.
Commit dvpLIbC and tag the commit with the new version.


Operations for incrementing the version number of dvpLibC_1_1_0 to dvpLibC_2_0_0 only for dvpLibB1
--------------------------------------------------------------------------------------------------

Add dvpLIbC as a second submodule.

.. code-block::

    git submodule add https://github.com/Knitschi/dvpLibC.git Sources/dvpLibC_2_0_0

Add dvpLibC_2_0_0 to the :code:`packages.cmake` file.

Update the entry in libB1 LINKED_LIBRARIES list.

Update the namespace in libC1_2_0_0 and libB1_2_0_0.

Fix compile errors in libA by transforming one type into the other.

Type transformations
....................

ValueType (all data public)

Nothing changed.
    - Copy values.
Function was added.
    - Copy values.
Function signature changed.
    - Copy values.
Function was removed.
    - Copy values.
Data member was added.
    - Copy values and find an appropriate one for the new value.
Data member was removed.
    - Copy existing values.

ComplexType (private data and not copiable, passed around by pointer)

Nothing changed.
    - reinterpret cast.
Function added.
    - reinterpret cast.
Function signature changed.
    - reinterpret cast.
Function removed.
    - reinterpret cast.
Private data added.
    - ?
Private data removed.
    - ?


Further Work:
- libC1 should probably provide its own library/libraries for type transformations. How would that be organized?
- Is there a way how the renames of the namespaces can be prevented and be replaced with macros?
    - How can the macros be correctly defined in a client project that uses multiple versions?
        - Maybe include files that define the macro just before the macro is used?



