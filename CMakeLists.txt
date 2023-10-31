cmake_minimum_required(VERSION 3.0.0)
project(first VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

include_directories(include include/text_query)
aux_source_directory(src SRC_LIST)
aux_source_directory(src/text_query TEXT_LIST)

#add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_executable(main main.cpp ${TEXT_LIST} ${SRC_LIST})

#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
