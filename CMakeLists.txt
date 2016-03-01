cmake_minimum_required (VERSION 2.8)

project (belks)

set (FLAGS "-Wall -Werror -std=c++14 -pedantic-errors -pipe")
set (FLAGS "${FLAGS} -fno-stack-protector") # Some linux distributions have it
set (FLAGS "${FLAGS} -march=native") # Building for this PC only

if (UNIX)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS}")
endif ()

set (LIBS_DIR ${CMAKE_SOURCE_DIR}/libs)
include(ExternalProject)
find_package(Git REQUIRED)

ExternalProject_Add (
    gsl
    PREFIX ${CMAKE_BINARY_DIR}/gsl
    SOURCE_DIR ${LIBS_DIR}/gsl
    GIT_REPOSITORY https://github.com/Microsoft/GSL.git
    TIMEOUT 10
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON)
include_directories (${LIBS_DIR}/gsl/include)

enable_testing (true)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (TEST_BIN ${CMAKE_SOURCE_DIR}/test-bin)

include_directories (include)

add_subdirectory (tests)
