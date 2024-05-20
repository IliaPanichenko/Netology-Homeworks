cmake_minimum_required(VERSION 3.22.0)

if (WIN32)
message (STATUS "OK")
else ()
message (WARNING "System error")
endif ()

project(Simple_project)
add_executable(hello_Cmake my_first_cmake_program.cpp)