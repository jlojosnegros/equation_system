cmake_minimum_required(VERSION 3.7)

#root project
project (gherkin_calculator)

SET(CMAKE_VERBOSE_MAKEFILE OFF)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)


#trying to exclude third party libraries from 'make clean' but it does not work
set_directory_properties(PROPERTIES CLEAN_NO_CUSTOM true)

#add the subprojects folders
add_subdirectory(GUnit)

