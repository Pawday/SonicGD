#ifndef _SGD_GL_ERROR_WRAPPER_H
#include <glew.h>
#define _SGD_GL_ERROR_WRAPPER_H

void checkError(char *file, int line_num);
#define GL(function_call) function_call; checkError(__FILE__,__LINE__)

#endif