cmake_minimum_required(VERSION 3.9)

# Decision: Public headers goes directly in the project root folder
SET(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# Source files goes in the /src folder
SET(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

SET(PROJECT_TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)

# add project include folder to include path
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")


#=== Targets ===
set (EQUATION_SYSTEM_SOURCES
        ${PROJECT_SOURCE_DIR}/main.cpp
        )

set (EQUATION_SYSTEM_HEADERS

)

add_executable(equation_system ${EQUATION_SYSTEM_SOURCES} ${EQUATION_SYSTEM_HEADERS})



