/*
 * Window.h
 *
 *  Created on: Apr 11, 2018
 *      Author: bmorales
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include "includes.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Window {
public:
	Window(unsigned int width, unsigned int height, const char* title);
	static void setIcon(const char* iconPath);
	static void render();
	static bool shouldClose();
	static void windowClean();

private:
	static GLFWwindow* window;

};

#endif /* WINDOW_H_ */
