set(CMAKE_CXX_STANDARD 11)
project(UndertaleTestGame)

add_executable(${PROJECT_NAME} src/Main.cpp)
include_directories(../src/src/headers)
target_link_libraries(${PROJECT_NAME} UndertaleCPPLibrary)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/ DESTINATION ${CMAKE_BINARY_DIR}/test/resources/)
