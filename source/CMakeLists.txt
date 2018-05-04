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
        ${PROJECT_SOURCE_DIR}/Term.cpp
        ${PROJECT_SOURCE_DIR}/Constant.cpp
        ${PROJECT_SOURCE_DIR}/Variable.cpp
        )

set (EQUATION_SYSTEM_HEADERS
        ${PROJECT_INCLUDE_DIR}/NameSet.hpp
        ${PROJECT_INCLUDE_DIR}/Term.hpp
        ${PROJECT_INCLUDE_DIR}/Constant.hpp
        ${PROJECT_INCLUDE_DIR}/Variable.hpp
)

add_library(equation_system ${EQUATION_SYSTEM_SOURCES} ${EQUATION_SYSTEM_HEADERS})

include_directories("${PROJECT_ROOT_DIR}/3pp/GUnit/include")
#== Test Targets ==
# Term
set(TERM_TEST_SOURCES
        ${PROJECT_TEST_DIR}/Term_test.cpp
        )

set(TERM_TEST_HEADERS
        )

add_executable(Term_test ${TERM_TEST_SOURCES} ${TERM_TEST_HEADERS})
target_link_libraries(Term_test gtest_main equation_system)
add_dependencies(Term_test equation_system)


# Constant
set(CONSTANT_TEST_SOURCES
        ${PROJECT_TEST_DIR}/Constant_test.cpp
        )

set(CONSTANT_TEST_HEADERS
        )

add_executable(Constant_test ${CONSTANT_TEST_SOURCES} ${CONSTANT_TEST_HEADERS})
target_link_libraries(Constant_test gtest_main equation_system)
add_dependencies(Constant_test equation_system)

# Variable
set(VARIABLE_TEST_SOURCES
        ${PROJECT_TEST_DIR}/Variable_test.cpp
        )

set(VARIABLE_TEST_HEADERS
        )

add_executable(Variable_test ${VARIABLE_TEST_SOURCES} ${VARIABLE_TEST_HEADERS})
target_link_libraries(Variable_test gtest_main equation_system)
add_dependencies(Variable_test equation_system)