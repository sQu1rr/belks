ExternalProject_Add (
    catch
    PREFIX ${CMAKE_BINARY_DIR}/catch
    SOURCE_DIR ${LIBS_DIR}/catch
    GIT_REPOSITORY https://github.com/philsquared/Catch.git
    TIMEOUT 10
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON)

ExternalProject_Get_Property (catch source_dir)
set (CATCH_INCLUDE_DIR ${LIBS_DIR}/catch/single_include CACHE INTERNAL "Catch")
include_directories (${CATCH_INCLUDE_DIR})

file (GLOB_RECURSE TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach (fileSrc ${TEST_SRCS})
    get_filename_component (fileName ${fileSrc} NAME_WE)
    get_filename_component (filePath ${fileSrc} DIRECTORY)

    add_executable (test_${fileName} ${fileSrc})

    set_target_properties (test_${fileName} PROPERTIES 
        RUNTIME_OUTPUT_DIRECTORY ${TEST_BIN}/${filePath})

    add_test (NAME test_${fileName} 
        WORKING_DIRECTORY ${TEST_BIN}
        COMMAND ${TEST_BIN}/${filePath}/test_${fileName})
endforeach (fileSrc)
