set(CMAKE_CXX_STANDARD 14)
project(UndertaleCPPLibrary)

file(GLOB_RECURSE SOURCE_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        )

file(GLOB_RECURSE EXTERNAL_SOURCE_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/external/*.h"
        )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

add_library(UndertaleCPPLibrary SHARED ${SOURCE_FILES} ${EXTERNAL_SOURCE_FILES})
include_directories(../SFML-2.4.2/include/)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-audio sfml-graphics sfml-window)
