# This package contains files that provide build-configurations for the CI-Build-Server.
include(cpfInitPackageProject)
include(cpfAddFilePackage)

cpfInitPackageProject()

set(files
	Clang-shared-debug.config.cmake
	Clang-static-release.config.cmake
	cpfCIBuildConfigurations.json
	Gcc-shared-debug.config.cmake
	README.rst
	VS2017-shared.config.cmake
	VS2017-static.config.cmake
)

cpfAddFilePackage(
	SOURCES "${files}"
)