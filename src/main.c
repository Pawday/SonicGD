#include <glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <glfw3.h>
#include <portaudio.h>
#include <gl_error_wrapper.h>
#include <shader.h>
#include <loader.h>

#include "window/window.h"


#define DEBUG 0



int main()
{
    
    //init glfw
    if (!glfwInit())
        return -1;


    GLFWwindow* window = glfwCreateWindow(1080,720,"",0,0);\

    glfwShowWindow(window);
    glfwMakeContextCurrent(window);
    sgd_window_init(window);

    //init glew
    GLenum glew_err = glewInit();
    if (GLEW_OK != glew_err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(glew_err));
        return -1;
    }

    glfwSetWindowSizeCallback(window,sgd_window_resize_callback);    

    while (!glfwWindowShouldClose(window))
    {
        GL(glClear(GL_COLOR_BUFFER_BIT));

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
}