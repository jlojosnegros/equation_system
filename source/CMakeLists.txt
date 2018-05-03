cmake_minimum_required(VERSION 3.9)

SET(CMAKE_VERBOSE_MAKEFILE OFF)
# Decision: Public headers goes directly in the project root folder
SET(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR})
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
#add_dependencies(klondike BetterEnums )
#add_dependencies(klondike POCO)
#target_link_libraries(klondike PocoFoundation)



#=== Test targets ===
#set( TEST_SMART_ENUM_SOURCES
#        ${PROJECT_TEST_DIR}/test_smart_enum.cpp
#        )
#
#set( TEST_SMART_ENUM_HEADERS
#        ${PROJECT_COMMON_INCLUDE_DIR}/pointee_comparator.hpp
#        ${PROJECT_COMMON_INCLUDE_DIR}/smart_enum.hpp
#        )
#
#add_executable(test_smart_enum ${TEST_SMART_ENUM_SOURCES} ${TEST_SMART_ENUM_HEADERS})
#add_dependencies(test_smart_enum catch )
