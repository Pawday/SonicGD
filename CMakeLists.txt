cmake_minimum_required(VERSION 3.10)

#project name
project(SonicGD)


#platform settings
    #WIN32
    if(WIN32)
        set(CMAKE_USE_WIN32_THREADS_INIT ON)
    endif(WIN32)
    


if(CMAKE_BUILD_TYPE STREQUAL Debug)
    add_compile_definitions(DEBUG)
    set(WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()


#adding libraries sources directoris
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/glew/build/cmake)
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/glfw)
add_subdirectory(${CMAKE_SOURCE_DIR}/libs/portaudio)


#disable link shared library glew
set_target_properties(glew PROPERTIES EXCLUDE_FROM_ALL TRUE)


add_executable(${PROJECT_NAME} src/main.c)



#set global libraries include path short names
    set(GLFW_INCLUDE ${GLFW_SOURCE_DIR}/include/GLFW)
    set(GLEW_INCLUDE ${glew_SOURCE_DIR}/../../include/GL)

#set libs includes for project
    target_include_directories(${PROJECT_NAME} PRIVATE ${GLFW_INCLUDE})
    target_include_directories(${PROJECT_NAME} PRIVATE ${GLEW_INCLUDE})


add_subdirectory(${CMAKE_SOURCE_DIR}/src/engine)


#link libraries
    target_link_libraries(${PROJECT_NAME} glfw)
    target_link_libraries(${PROJECT_NAME} glew_s)
    target_link_libraries(${PROJECT_NAME} portaudio_static)
    target_link_libraries(${PROJECT_NAME} sgd_engine)



install(DIRECTORY ${CMAKE_SOURCE_DIR}/res DESTINATION ${CMAKE_BINARY_DIR})