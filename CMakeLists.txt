cmake_minimum_required(VERSION 3.10)

project(SonicGD)

add_executable(${PROJECT_NAME} src/main.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/libs/glfw/include)
target_link_libraries(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/libs/glfw/libglfw3.a)

find_package(OpenGL REQUIRED)


target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC ${OPENGL_LIBRARIES})


