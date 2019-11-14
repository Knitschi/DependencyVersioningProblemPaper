# This package contains files that provide build-configurations for the CI-Build-Server.
include(cpfInitPackageProject)
include(cpfAddFilePackage)

cpfInitPackageProject(LANGUAGES NONE)

set(files
	cpfCIBuildConfigurations.json
	Default.config.cmake
	EmptyToolchain.cmake
)

cpfAddFilePackage(
	SOURCES "${files}"
)