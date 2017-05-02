set(CMAKE_CXX_STANDARD 14)
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

find_package(THOR 2 REQUIRED)
if(THOR_FOUND)
    include_directories(${THOR_INCLUDE_DIR})
    include_directories(${AURORA_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${THOR_LIBRARY})
endif()
