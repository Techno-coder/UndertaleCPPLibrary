set(CMAKE_CXX_STANDARD 14)
project(UndertaleTestGame)

add_executable(${PROJECT_NAME} Main.cpp)
include_directories(../src/headers)

target_link_libraries(${PROJECT_NAME} UndertaleCPPLibrary)
file(COPY resources DESTINATION ${CMAKE_BINARY_DIR}/test/resources/)
