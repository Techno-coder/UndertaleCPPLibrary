set(CMAKE_CXX_STANDARD 11)
project(UndertaleCPPLibrary)

file(GLOB_RECURSE SOURCE_FILES
        "${CMAKE_SOURCE_DIR}/src/*.h"
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        )

add_library(UndertaleCPPLibrary SHARED ${SOURCE_FILES})

set(CMAKE_MODULE_PATH ../libraries/)

find_package(SFML 2.4.2 COMPONENTS system window graphics audio network REQUIRED)
if(${SFML_FOUND})
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

