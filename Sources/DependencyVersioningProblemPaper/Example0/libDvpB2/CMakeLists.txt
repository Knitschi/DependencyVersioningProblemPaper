# file libDvpB2/CMakeLists.txt

include(cpfInitPackageProject)
include(cpfAddCppPackage)


cpfInitPackageProject()

set( PACKAGE_PUBLIC_HEADER
	libB2.h
)

set( PACKAGE_PRODUCTION_FILES
	libB2.cpp
)

############################ Add Package ############################
cpfAddCppPackage( 
    TYPE                  LIB
    OWNER                 Knitschi
    BRIEF_DESCRIPTION		
        "The second mid level library in the DVP example project."
    PACKAGE_NAMESPACE     dvpLibB2
    PUBLIC_HEADER         ${PACKAGE_PUBLIC_HEADER}
    PRODUCTION_FILES      ${PACKAGE_PRODUCTION_FILES}
    LINKED_LIBRARIES
        PUBLIC            dvpLibC
)
