cmake_minimum_required(VERSION 3.10)
project(CPP_Challenge VERSION 0.1 DESCRITION "Solutions to CPP Challenge")
set(CMAKE_CXX_STANDARD 11)
PROJECT(CPP_Challenge)
#target_include_directories(CPP_Challenge PUBLIC
#                          "${PROJECT_BINARY_DIR}"
#                           )
#add_compile_options()
#set(SOURCE_FILES main.cpp)
a#dd_subdirectory(../CPP_Challenge/include)

add_executable(test loesungen/test.cpp)
