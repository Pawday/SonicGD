#include <glew.h>
#include <stdio.h>
#include <glfw3.h>


void callback(GLFWwindow* window, int w, int h)
{
    glViewport(0,0,w,h);
    printf("%d %d\n",h,w);
};


int main()
{
    
    //init glfw
    if (!glfwInit())
        return -1;


    GLFWwindow* window = glfwCreateWindow(1080,720,"",0,0);


    glfwShowWindow(window);
    glfwMakeContextCurrent(window);

    //init glew
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
        return -1;
    }

    glfwSetWindowSizeCallback(window,callback);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    

    glfwTerminate();
}