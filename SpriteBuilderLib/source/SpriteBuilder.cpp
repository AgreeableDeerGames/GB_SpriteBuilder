#include <SpriteBuilder.h>

#include <SpriteBuilder/Core/EventController.h>

using namespace GB::SB;
SpriteBuilder::SpriteBuilder()
{
	// Initialize an instance of DemoCoreEventController
	EventController controller;
	// Start the loop on the DemoCoreEventController to start the Demo
	controller.runLoop();
}