cmake_minimum_required(VERSION 3.10)


set(MODULE sgd_engine)



add_library(${MODULE} INTERFACE)


add_subdirectory(window)
add_subdirectory(common)
add_subdirectory(loader)
add_subdirectory(shader)


#modules
    #window module
        target_link_libraries(${MODULE} INTERFACE sgd_window)
    #common module
        # #gl error wrapper
            target_link_libraries(${MODULE} INTERFACE sgd_error_wrapper)
    #loader module
        target_link_libraries(${MODULE} INTERFACE sgd_loader)
    #shader module
        target_link_libraries(${MODULE} INTERFACE sgd_shader)