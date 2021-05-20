# file libDvpC/CMakeLists.txt

include(cpfInitPackageProject)
include(cpfAddCppPackage)


cpfInitPackageProject()

set( PACKAGE_PUBLIC_HEADER
    ValueType.h
    ComplexType.h
)

set( PACKAGE_PRODUCTION_FILES
    ValueType.cpp
    ComplexType.cpp
) 

############################ Add Package ############################
cpfAddCppPackage( 
    TYPE                  LIB
    OWNER                 Knitschi
    BRIEF_DESCRIPTION
        "The low level library in the DVP example project."
    PACKAGE_NAMESPACE     libDvpC
    PUBLIC_HEADER         ${PACKAGE_PUBLIC_HEADER}
    PRODUCTION_FILES      ${PACKAGE_PRODUCTION_FILES}
)
