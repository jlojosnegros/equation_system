cmake_minimum_required(VERSION 3.9)
project(sistema_ecuaciones)

SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Change the output folder to avoid pollute
# set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

# executables and libraries go in the same path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

#incluimos el directorio donde deberian quedar todas las librerias en la busqueda del compilador al linkar.
link_directories(${LIBRARY_OUTPUT_PATH})

# Add root to include path
SET(PROJECT_ROOT_DIR ${PROJECT_SOURCE_DIR})
# add include directories for all the subprojects
include_directories("${PROJECT_ROOT_DIR}")

enable_testing(true)

#add the subprojects folders
add_subdirectory(3pp EXCLUDE_FROM_ALL)
add_subdirectory(source)

