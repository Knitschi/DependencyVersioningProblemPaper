
set( CPF_CONFIG "Default" CACHE STRING "the config name" FORCE)

set( CMAKE_GENERATOR "Visual Studio 16 2019" CACHE STRING "The CMake generator" FORCE)
set( CMAKE_MAKE_PROGRAM "ninja" CACHE STRING "For some generators the make program must be set manually." FORCE)
set( CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_LIST_DIR}/EmptyToolchain.cmake" CACHE PATH "The file that defines the compiler and compile options for all compile configurations." FORCE)
set( CMAKE_BUILD_TYPE "Release" CACHE STRING "The compile configuration used by single configuration make tools." FORCE)
set( CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/../install" CACHE STRING "The path to which to build results are copied by the install targets.")