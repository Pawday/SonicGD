#include <stdio.h>
#include <glfw3.h>
#include <GL/gl.h>
int main()
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(1080,720,"",0,0);


    glfwShowWindow(window);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    


    glfwTerminate();
}