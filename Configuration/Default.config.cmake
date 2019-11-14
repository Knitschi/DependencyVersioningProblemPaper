# This file contains cmake project configuration parameters.

# Inherit configuration parameters.
include( "C:/dev/DependencyVersioningProblemPaper/Sources/CIBuildConfigurations/Default.config.cmake" )
set( CPF_PARENT_CONFIG "Default" CACHE STRING "The CI-configuration from which this config derives." FORCE)

# internal variables
set( CPF_CONFIG "Default" CACHE STRING "The name of the cmake configuration that is defined by this file." FORCE)

# Overridden or new cache variables.

# Inherited cache variables.
# set( CMAKE_BUILD_TYPE "Release" CACHE STRING "The compile configuration used by single configuration make tools." FORCE )
# set( CMAKE_GENERATOR "Ninja" CACHE STRING "The CMake generator" FORCE )
# set( CMAKE_MAKE_PROGRAM "ninja" CACHE STRING "For some generators the make program must be set manually." FORCE )
# set( CPF_CONFIG "Default" CACHE STRING "the config name" FORCE )

