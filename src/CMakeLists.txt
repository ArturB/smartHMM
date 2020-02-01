# **********************************************************************
# Copyright (c) Artur M. Brodzki 2020. All rights reserved.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# **********************************************************************

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_library (
    smarthmm SHARED
        scientific/ml/smart-hmm.h
)
set_target_properties(
    smarthmm PROPERTIES
    LINKER_LANGUAGE CXX
)
target_link_libraries(
    smarthmm
    armadillo
    omp
)
install (
    TARGETS smarthmm
    LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
)
install(
    FILES scientific/ml/smart-hmm
    DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}
)
