#include "window.h"
#include <stdio.h>

static int local_width = 0;
static int local_height = 0;
static GLFWwindow* local_window;

void sgd_window_init(GLFWwindow* window)
{
    local_window = window;
    glfwGetWindowSize(local_window,&local_width,&local_height);
}

void sgd_window_resize_callback(GLFWwindow* window, int w, int h)
{
    glViewport(0,0,w,h);
    local_width = w;
    local_height = h;
}

void sgd_window_get_size(int* width, int* height)
{
    *width = local_width;
    *height = local_height;
}