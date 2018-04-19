/*
 * Window.cpp
 *
 *  Created on: Apr 11, 2018
 *      Author: bmorales
 */

#include "Window.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLFWwindow* Window::window;

/**
 * Constructor, Creates a window using glfw libraries.
 *
 * @param width pixel length for the width.
 * @param height pixel length for the height.
 * @param title title for the window to display.
 */
Window::Window(unsigned int width = 800, unsigned int height = 600, const char* title = "default window")
{
	    // glfw: initialize and configure
	    // ------------------------------
	    glfwInit();
	    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	    // glfw window creation
	    // --------------------
	    window = glfwCreateWindow(width, height, title, NULL, NULL);
	    if(window == NULL) {
	        std::cout << "Failed to create GLFW window" << std::endl;
	        glfwTerminate();
	        return;
	    }

	    glfwMakeContextCurrent(window);
	    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


}

/**
 * Get the window for others to use
 */
GLFWwindow* Window::getWindow()
{
	return window;
}

/**
 * Add an icon to the window
 *
 * @param iconPath the path to the icon image.
 */
void Window::setIcon(const char* iconPath)
{
	GLFWimage icon[1];

	if(window == NULL) {
		std::cout << "Window is none existent, can't add icon" << std::endl;
	}

	icon[0].pixels = stbi_load(iconPath, &icon[0].width, &icon[0].height, 0, STBI_rgb_alpha);
	glfwSetWindowIcon(window, 1, icon);

	stbi_image_free(icon[0].pixels);

}

/**
 * Update what goes to the screen
 */
void Window::render()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

/**
 * Determines whether a close command has been requested
 *
 * Returns true if close command has been requested
 */
bool Window::shouldClose()
{
	return glfwWindowShouldClose(window);
}

/**
 * terminate, clearing all previously allocated GLFW resources
 */
void Window::windowClean()
{
	glfwTerminate();
}

//glfw: whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0,0,width, height);
}

