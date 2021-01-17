#include "window.h"
#include <stdio.h>
void window_resize_callback(GLFWwindow* window, int w, int h)
{
    printf("%d %d\n",w,h);
    glViewport(0,0,w,h);
}