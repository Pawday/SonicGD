cmake_minimum_required(VERSION 3.10)

#project name
project(SonicGD)

#adding libraries
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/glew/build/cmake)
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/glfw)
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/portaudio)


add_executable(${PROJECT_NAME} src/main.c)


#set global libraries include path short names
    set(GLFW_INCLUDE ${GLFW_SOURCE_DIR}/include/GLFW)
    set(GLEW_INCLUDE ${glew_SOURCE_DIR}/../../include/GL)

#set libs includes for project
    target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_INCLUDE})
    target_include_directories(${PROJECT_NAME} PRIVATE ${GLEW_INCLUDE})

#link libraries
    target_link_libraries(${PROJECT_NAME} glfw)
    target_link_libraries(${PROJECT_NAME} glew_s)
    target_link_libraries(${PROJECT_NAME} portaudio_static)


#building modules
    #window module
        add_subdirectory(src/window)
        target_include_directories(${PROJECT_NAME} PRIVATE ${sgd_window_INCLUDE_DIRS})
        target_link_libraries(${PROJECT_NAME} sgd_window)
    #common module
        add_subdirectory(src/common)
        # #gl error wrapper
            target_include_directories(${PROJECT_NAME} PUBLIC ${sgd_error_wrapper_INCLUDE_DIRS})
            target_link_libraries(${PROJECT_NAME} sgd_error_wrapper)
    #shader module
        add_subdirectory(src/shader)
        target_include_directories(${PROJECT_NAME} PRIVATE ${sgd_shader_INCLUDE_DIRS})
        target_link_libraries(${PROJECT_NAME} sgd_shader)