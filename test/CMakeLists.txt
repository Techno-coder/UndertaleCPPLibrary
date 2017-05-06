set(CMAKE_CXX_STANDARD 14)
project(UndertaleTestGame)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/Main.cpp)
include_directories(../src/src/headers)
target_link_libraries(${PROJECT_NAME} UndertaleCPPLibrary)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/ DESTINATION ${CMAKE_BINARY_DIR}/test/resources/)
