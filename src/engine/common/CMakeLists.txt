cmake_minimum_required(VERSION 3.10)

#Error Wrapper
    set(SGD_ERROR_WRAPPER sgd_error_wrapper)

    add_library(${SGD_ERROR_WRAPPER} STATIC
        gl_error_wrapper.c
    )

    target_include_directories(${SGD_ERROR_WRAPPER} PRIVATE ${GLEW_INCLUDE})
    target_include_directories(${SGD_ERROR_WRAPPER} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})