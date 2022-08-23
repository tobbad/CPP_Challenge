cmake_minimum_required(VERSION 3.10)
project(CPP_Challenge VERSION 0.1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_executable(loesung_01 loesung_01.cpp)
target_include_directories(loesung_01 PUBLIC ${POJRCT_BINARY_DIR})
#target_include_directories(CPP_Challenge PUBLIC
#                          "${PROJECT_BINARY_DIR}"
#                          "${PROJECT_SOURCE_DIR}/lib"
#                          )
configure_file(version.in.h version.h)

add_subdirectory(lib)
list(APPEND EXTRA_LIB lib)
list(APPEND EXTRA_INCLUDE lib)

target_link_libraries(loesung_01 STATIC  lib)
