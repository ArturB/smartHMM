# **********************************************************************
# Copyright (c) Artur M. Brodzki 2020. All rights reserved.
# **********************************************************************

cmake_minimum_required ( VERSION 3.4.3 )

project( smarthmm CXX C )
set (VERSION_MAJOR 1)
set (VERSION_MINOR 0)
set (VERSION_PATCH 0)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

# Necessary includes
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${CMAKE_SOURCE_DIR}
)
include(CPack)
include(CheckCXXCompilerFlag)
include(GNUInstallDirs)
include(RequireLibrary)

# Check binary dependencies
require_library(openblas "")
require_library(armadillo "")
require_library(omp "")

# Debug and release build
option ( ENABLE_DEBUG "Enable debugging options (bugreports and developers only)" OFF )
option ( ENABLE_RELEASE "Enable compiler -O3 optimization flags" ON )

set( CMAKE_CXX_FLAGS "-Wall -fopenmp " )
if ( ENABLE_DEBUG )
    set( CMAKE_BUILD_TYPE "DEBUG" )
    string ( APPEND CMAKE_CXX_FLAGS "-g -DDEBUG " )
else ( ENABLE_DEBUG )
    string ( APPEND CMAKE_CXX_FLAGS "-DNDEBUG " )
endif ( ENABLE_DEBUG )

if ( ENABLE_RELEASE )
    set( CMAKE_BUILD_TYPE "RELEASE" )
    string ( APPEND CMAKE_CXX_FLAGS "-O3 " )
endif ( ENABLE_RELEASE )

# Output dirs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Process src dir
add_subdirectory ( src )
# Process test dir
add_subdirectory( test )

# CPack configuration
set (CPACK_GENERATOR TGZ)
set (CPACK_PACKAGE_NAME "smart-hmm")
set (CPACK_PACKAGE_VENDOR "Artur M. Brodzki")
set (CPACK_PACKAGE_VERSION_MAJOR "${VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${VERSION_MINOR}")
set (CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH}")
set (CPACK_PACKAGE_INSTALL_DIRECTORY "dist")
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set (CPACK_SOURCE_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}")
set (CPACK_SOURCE_IGNORE_FILES "${CMAKE_BINARY_DIR}/*")
set (CPACK_SOURCE_GENERATOR TGZ)

# Print configuration flags
message("
-------------------------------------------------------

Build type: ${CMAKE_BUILD_TYPE}

Build output options:
    ARCH_OUT:  ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
    LIBR_OUT:  ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
    RUNT_OUT:  ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}

Install options:
    RUN_DIR:  ${CMAKE_INSTALL_FULL_BINDIR}
    LIB_DIR:  ${CMAKE_INSTALL_FULL_LIBDIR}
    INC_DIR:  ${CMAKE_INSTALL_FULL_INCLUDEDIR}

Compiler options:
    CXX:            ${CMAKE_CXX_COMPILER}
    CXXFLAGS:       ${CMAKE_CXX_FLAGS}
")
