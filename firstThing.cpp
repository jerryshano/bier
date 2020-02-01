#include <GL/glew.h>
#include <GLFW/glfw3.h>
#define GLEW_STATIC

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // init glew
    glewExperimental = GL_TRUE;
    glewInit();

    
    // before the loop
    float color_scale = 1.0;
    float dt = 1.0 / 60.0;
    float color_speed = 0.01;
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        //glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        //glClearColor(0.7, 0.0, 0.5, 1.0);

        // in the loop
        if (color_scale > 1.0) {
            color_scale = 0.0;
        }
        else {
            color_scale += color_speed * dt;
        }
        glClearColor(0.7 * color_scale, 0.0 * color_scale, 0.5 * color_scale, 1.0);


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}