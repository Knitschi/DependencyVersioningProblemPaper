# file libDvpB1/CMakeLists.txt

include(cpfInitPackageProject)
include(cpfAddCppPackage)


cpfInitPackageProject()

set( PACKAGE_PUBLIC_HEADER
    libDvpB1.h
)

set( PACKAGE_PRODUCTION_FILES
    libDvpB1.cpp
)

############################ Add Package ############################
cpfAddCppPackage( 
    TYPE                  LIB
    OWNER                 Knitschi
    BRIEF_DESCRIPTION		
        "The first mid level library in the DVP example project."
    PACKAGE_NAMESPACE     libDvpB1
    PUBLIC_HEADER         ${PACKAGE_PUBLIC_HEADER}
    PRODUCTION_FILES      ${PACKAGE_PRODUCTION_FILES}
    LINKED_LIBRARIES		
        PUBLIC            dvpLibC
)
