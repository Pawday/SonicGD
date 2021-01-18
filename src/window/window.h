#ifndef _SGD_WINDOW_H
#define _SGD_WINDOW_H
#include <glfw3.h>

void sgd_window_init(GLFWwindow* window);

void sgd_window_resize_callback(GLFWwindow *window, int w, int h);

void sgd_window_get_size(int* width, int* height);

#endif /* _SGD_WINDOW_H */