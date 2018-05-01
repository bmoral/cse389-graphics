/*
 * Window.h
 *
 *  Created on: Apr 11, 2018
 *      Author: bmorales
 */

#ifndef WINDOW_H_
#define WINDOW_H_

//#include "includes.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Window {
public:
	Window(unsigned int width, unsigned int height, const char* title);
	static void setIcon(const char* iconPath);
	static void render();
	static bool shouldClose();
	static void windowClean();
	static GLFWwindow* getWindow();
	static void setFullscreen();
	static unsigned int SCR_WIDTH;
	static unsigned int SCR_HEIGHT;

private:
	static GLFWwindow* window;
	static int dxpos, dypos;
	static int dwidth, dheight;

};

#endif /* WINDOW_H_ */
