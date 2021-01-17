#include "gl_error_wrapper.h"
#include <stdio.h>
#include <stdlib.h>

/*
    Find:
    ^( *)(gl[^( ^f ^e][a-zA-Z\(0-9,_]*\))
    Replase:
    $1GL($2)
*/

void checkError(char *file, int line_num)
{
    int wasError = 0;
    GLenum err = glGetError();
    while(err != GL_NO_ERROR)
    {
        wasError = 1;
        printf("%s:%d GL_ERROR 0x%x\n",file,line_num,err);
        err = glGetError();
    }

    #ifndef DEBUG
    if (wasError)
        exit(-1);
    #endif
}