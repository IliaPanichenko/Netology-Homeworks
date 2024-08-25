cmake_minimum_required(VERSION 3.20)
project(PG_project)
add_executable(PG_project PG_project.cpp)
add_subdirectory(C:\\Users\\ipanichenko\\Downloads\\libpqxx-7.7.4 libpqxx-build) # Укажите путь к libpq++
target_compile_features(PG_project PRIVATE cxx_std_17) # Включите C++17
target_link_libraries(PG_project pqxx)