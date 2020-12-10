cmake_minimum_required(VERSION 3.10)

project(SonicGD)

add_subdirectory(${CMAKE_SOURCE_DIR}/libs/glew/build/cmake)
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/glfw)

add_executable(${PROJECT_NAME} src/main.c)


target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_SOURCE_DIR}/include/GLFW)

target_include_directories(${PROJECT_NAME} PRIVATE ${glew_SOURCE_DIR}/../../include/GL)


target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glew_s)
