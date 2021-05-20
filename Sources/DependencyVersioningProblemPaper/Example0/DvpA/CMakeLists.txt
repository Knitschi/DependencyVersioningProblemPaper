# file DvpA/CMakeLists.txt

include(cpfInitPackageProject)
include(cpfAddCppPackage)

cpfInitPackageProject()

set( PACKAGE_PUBLIC_HEADER
    libA.h
) 

set( PACKAGE_PRODUCTION_FILES
    libA.cpp
    main.cpp
)

############################ Add Package ############################
cpfAddCppPackage( 
    TYPE CONSOLE_APP
    OWNER Knitschi
    BRIEF_DESCRIPTION		
        "The top level executable and library in the DVP example project."
    PACKAGE_NAMESPACE dvpLibA
    PUBLIC_HEADER ${PACKAGE_PUBLIC_HEADER}
    PRODUCTION_FILES ${PACKAGE_PRODUCTION_FILES}
    LINKED_LIBRARIES		
        PRIVATE dvpLibB1 dvpLibB2
)

