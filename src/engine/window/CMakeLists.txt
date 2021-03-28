cmake_minimum_required(VERSION 3.10)


set(MODULE sgd_window)

add_library(sgd_window STATIC
    window.c
)


target_include_directories(${MODULE} PRIVATE ${GLFW_INCLUDE})
target_include_directories(${MODULE} PRIVATE ${GLEW_INCLUDE})

target_include_directories(${MODULE} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
