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

void MainComponent::start()
{
	run();
}

void MainComponent::stop()
{

}

void MainComponent::run()
{
	//render loop
	while(!Window::shouldClose()){
		render();
	}

	//Clean-Up when render loop exits
	Window::windowClean();
}

void MainComponent::render()
{
	Window::render();
}

void MainComponent::cleanUp()
{

}
