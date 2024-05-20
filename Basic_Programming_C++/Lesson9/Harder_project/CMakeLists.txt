cmake_minimum_required(VERSION 3.22.0)

if (WIN32)
message (STATUS "OK")
else ()
message (WARNING "System error")
endif ()

project(Harder_project)
add_executable(Hierarchy_class "Class_Hierarchy.cpp" Triangle.h Triangle.cpp Square.h Square.cpp right_triangle.h right_triangle.cpp Rhombus.h Rhombus.cpp Rectangle.h Rectangle.cpp Quadrangle.h Quadrangle.cpp Parallelogram.h Parallelogram.cpp isosceles_triangle.h isosceles_triangle.cpp Figure.h Figure.cpp equilateral_triangle.h equilateral_triangle.cpp)