set(CMAKE_CXX_STANDARD 14)
project(UndertaleCPPLibrary)

file(GLOB_RECURSE SOURCE_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/headers/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/implementation/*.cpp"
        )

include_directories(../SFML-2.4.2/include/)
include_directories(headers)

add_library(UndertaleCPPLibrary SHARED ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-audio sfml-graphics sfml-window)
