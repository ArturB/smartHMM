cmake_minimum_required(VERSION 3.10)

project(smarthmm VERSION 0.1.1)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Output dirs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CPACK_OUTPUT_FILE_PREFIX ${CMAKE_BINARY_DIR}/dist)

# Compile library
add_subdirectory(src)
# Compile tests
add_subdirectory(test)

# CPack Installer
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "${smarthmm_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${smarthmm_VERSION_MINOR}")
include(CPack)
