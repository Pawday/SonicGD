cmake_minimum_required(VERSION 3.10)

#Loader module
    set(LOADER sgd_loader)


    if(WIN32)
        add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
        add_library (
            ${LOADER} STATIC
            win/loader.c
        )
    endif(WIN32)
    
    

    target_include_directories(${LOADER} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})