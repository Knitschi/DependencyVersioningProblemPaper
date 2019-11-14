# This is the CMakeLists.txt file for the CMakeProjectFramework CI-project.

include("${CMAKE_SOURCE_DIR}/CPFCMake/cpfInitCIProject.cmake")
cmake_minimum_required(VERSION ${CPF_MINIMUM_CMAKE_VERSION})

project(DependencyVersioningProblemPaperBuildProject)

cpfAddPackages(
	GLOBAL_FILES ../README.md ../LICENSE
)

