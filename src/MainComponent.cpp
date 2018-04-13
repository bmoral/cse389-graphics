/*
 * MainComponent.cpp
 *
 *  Created on: Apr 13, 2018
 *      Author: bmorales
 */

#include "MainComponent.h"
#include "Window.h"

MainComponent::MainComponent() {

}
/**
 * Start the engine to drive the 3D world
 */
void MainComponent::start()
{
	run();
}

/**
 * Stop running the engine driving the 3D world
 */
void MainComponent::stop()
{

}

/**
 * Run the engine
 */
void MainComponent::run()
{
	//render loop
	while(!Window::shouldClose()){
		render();
	}

	//Clean-Up when render loop exits
	cleanUp();
}

/**
 * Elements to render
 */
void MainComponent::render()
{
	Window::render();
}

/**
 * Clean up before exiting
 */
void MainComponent::cleanUp()
{
	Window::windowClean();
}
