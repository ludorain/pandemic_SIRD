cmake_minimum_required(VERSION 3.16)
project(simulation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS_OFF)

include_directories("include")

add_executable(agent AGENT/main_pandemic.cpp AGENT/pandemic.cpp AGENT/parameters.cpp)
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
target_link_libraries(agent PRIVATE sfml-graphics)
target_compile_options(agent PRIVATE -Wall -Wextra)


add_executable(equation EQUATION/main.cpp EQUATION/pandemic.cpp EQUATION/people.cpp EQUATION/parameters.cpp)
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
target_link_libraries(equation PRIVATE sfml-graphics)
target_compile_options(equation PRIVATE -Wall -Wextra)

  
add_executable(equation.test EQUATION/doctest.cpp EQUATION/pandemic.cpp EQUATION/people.cpp EQUATION/parameters.cpp)
add_executable(agent.test AGENT/doctest.cpp AGENT/pandemic.cpp AGENT/parameters.cpp)


