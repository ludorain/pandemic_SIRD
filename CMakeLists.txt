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

if (BUILD_TESTING)
  string(REGEX REPLACE  " " "-O2" CMAKE_EXE_LINKER_FLAGS_DEBUG "")
  string(REGEX REPLACE  " " "-O2" CMAKE_CXX_FLAGS_DEBUG "")
  add_executable(equation.test EQUATION/doctest.cpp EQUATION/pandemic.cpp EQUATION/people.cpp EQUATION/parameters.cpp)
  add_test(NAME equation.test COMMAND equation.test)

  string(REGEX REPLACE  " " "-O2" CMAKE_EXE_LINKER_FLAGS_DEBUG "")
  string(REGEX REPLACE  " " "-O2" CMAKE_CXX_FLAGS_DEBUG "")
  add_executable(agent.test AGENT/doctest.cpp AGENT/pandemic.cpp AGENT/parameters.cpp)
  add_test(NAME agent.test COMMAND agent.test)

endif()