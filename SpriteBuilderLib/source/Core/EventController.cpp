#include <SpriteBuilder/Core/EventController.h>

#include <TGUI/TGUI.hpp>

#include <string>

using namespace GB::SB;

#define APP_NAME "SpriteBuilder"

EventController::EventController() : CoreEventController(APP_NAME), mainRegion(getWindow())
{
	// Set the camera to the same as the window
	camera.reset(sf::FloatRect(0, 0, (float)getWindow().getSize().x, (float)getWindow().getSize().y));
	setActiveRegion(&mainRegion);
}

/// <summary>
/// Handles all events
/// </summary>
/// <param name = "event">The event.</param>
void EventController::handleEvent(sf::Event& event)
{
	if (!handleGUIEvent(event)) {
		handleCoreEvent(event);
	}
}

/// <summary>
/// Handles non GUI user/window events.
/// </summary>
/// <param name="event">The event.</param>
/// <returns></returns>
void EventController::handleCoreEvent(sf::Event & event)
{
	// Handle events not handled by the GUI
	switch (event.type) 
	{
		case sf::Event::Closed:
		{
			// Close the window, thus closing the game.
			getWindow().close();
			return;
		}
		case sf::Event::MouseMoved:
		{
			// Get the pixel position and map it to coordinates
			sf::Vector2i mousePos(event.mouseMove.x, event.mouseMove.y);
			sf::Vector2f actualPosition = getWindow().mapPixelToCoords(mousePos);
			// Pass the event to the active region to handle
			return;
		}
		case sf::Event::MouseButtonPressed:
		{
			// Get the pixel position and map it to coordinates
			sf::Vector2i mousePos(event.mouseButton.x, event.mouseButton.y);
			sf::Vector2f actualPosition = getWindow().mapPixelToCoords(mousePos);
			// Pass the event to the active region to handle
			return;
		}
		case sf::Event::MouseWheelScrolled:
		{
			// Pass the event to the active region to handle
			return;
		}
		case sf::Event::KeyPressed:
		{
			// Pass the event to the active region to handle
			return;
		}
		case sf::Event::KeyReleased:
		{
			// Pass the event to the active region to handle
			return;
		}
		case sf::Event::Resized:
		{
			// Reset the camera to the same as the window
			camera.reset(sf::FloatRect(0, 0, (float)event.size.width, (float)event.size.height));
			// Set the view on the window to be the reset camera
			getWindow().setView(camera);
			return;
		}
		default:
		{
			return;
		}
	}
}

/// <summary>
/// Handles the GUI event.
/// </summary>
/// <param name="event">The event.</param>
/// <returns>Returns true if the event was consumed by the GUI. Returns false otherwise.</returns>
bool EventController::handleGUIEvent(sf::Event& event) {
	if (!static_cast<TemplateRegion*>(getActiveRegion())->getGUI().handleEvent(event)) {
		return false;
	}
	return true;
}