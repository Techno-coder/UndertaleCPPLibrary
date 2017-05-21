set(CMAKE_CXX_STANDARD 14)
project(UndertaleCPPLibraryTests)

file(GLOB_RECURSE SOURCE_FILES
		"${CMAKE_CURRENT_SOURCE_DIR}/tests/*.h"
		"${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp"
		)

add_library(CATCH INTERFACE)
target_include_directories(CATCH INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/catch.hpp)
include_directories(../src/headers)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} CATCH)
target_link_libraries(${PROJECT_NAME} UndertaleCPPLibrary)

enable_testing()
add_test(NAME ALL_TESTS COMMAND ${PROJECT_NAME})
