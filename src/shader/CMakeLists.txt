cmake_minimum_required(VERSION 3.10)


set(MODULE sgd_shader)

add_library(sgd_shader STATIC
    shader.c
)

target_include_directories(${MODULE} PRIVATE ${GLEW_INCLUDE})
target_include_directories(${MODULE} PRIVATE ${GLFW_INCLUDE})
target_include_directories(${MODULE} PRIVATE ${sgd_error_wrapper_INCLIDE_DIRS})
target_include_directories(${MODULE} PRIVATE ${sgd_window_INCLIDE_DIRS})

target_link_libraries(${MODULE} sgd_error_wrapper)
target_link_libraries(${MODULE} glew_s)
target_link_libraries(${MODULE} sgd_window)

target_include_directories(${MODULE} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})