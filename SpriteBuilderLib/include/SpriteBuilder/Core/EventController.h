#pragma once

#include <SpriteBuilder/Utils/DllUtils.h>
#include <SpriteBuilder/Core/TemplateRegion.h>

#include <GameBackbone/Core/CoreEventController.h>


namespace GB::SB
{
	class libSpriteBuilder EventController final : public GB::CoreEventController
	{
	public:
		// Constructors
		EventController();
		EventController(const EventController& other) = delete;
		EventController(EventController&& other) = default;
		EventController& operator=(const EventController& other) = delete;
		EventController& operator=(EventController&& other) = default;
		virtual ~EventController() = default;

		// Event handling
		void handleEvent(sf::Event& event) override;

	protected:
		void draw() override;

	private:
		void handleCoreEvent(sf::Event& event);
		bool handleGUIEvent(sf::Event& event);

		void postDraw();

		sf::View camera;
		TemplateRegion mainRegion;
	};
}
