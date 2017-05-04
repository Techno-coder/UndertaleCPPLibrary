set(CMAKE_CXX_STANDARD 14)
project(UndertaleCPPLibrary)

file(GLOB_RECURSE SOURCE_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        )

file(GLOB_RECURSE EXTERNAL_SOURCE_FILES
        "${CMAKE_CURRENT_SOURCE_DIR}/external/*.h"
        )

set(CMAKE_MODULE_PATH ../libraries/)

add_library(UndertaleCPPLibrary SHARED ${SOURCE_FILES} ${EXTERNAL_SOURCE_FILES})

find_package(SFML 2.4.2 COMPONENTS system window graphics audio network REQUIRED)
if(${SFML_FOUND})
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()
