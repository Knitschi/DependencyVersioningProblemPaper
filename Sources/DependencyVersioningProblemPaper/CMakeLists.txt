# This package contains the source files for the paper 
# "Finding a Solution for the Dependency Versioning Problem in C++" 
# which is generated with Sphinx.

include(cpfInitPackageProject)
include(cpfAddSphinxPackage)

cpfInitPackageProject(LANGUAGES NONE)

file(GLOB_RECURSE sources RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" CONFIGURE_DEPENDS "*")


cpfAddSphinxPackage(
	SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}
	OTHER_FILES ${sources}
	ADDITIONAL_SPHINX_ARGUMENTS "-W"
	SOURCE_SUFFIXES rst md
)

