#pragma once

#include <SpriteBuilder/Core/TemplateRegion.h>
#include <SpriteBuilder/Utils/DllUtils.h>

#include <GameBackbone/Core/GameRegion.h>

#include <TGUI/TGUI.hpp>
#include <TGUI/Widgets/TextBox.hpp>
#include <TGUI/Widgets/Button.hpp>


namespace GB::SB
{

	class libSpriteBuilder AnimationRegion : public TemplateRegion
	{
	public:
		// GUI
		void InitGui();

		void HandleMouseMove(sf::Vector2f windowCoordinates) override;

	private:

		void AddFrame();
		sf::Vector2f m_screenOffset;

		// GUI
		tgui::EditBox::Ptr m_topLeftX;
        tgui::EditBox::Ptr m_topLeftY;
        tgui::EditBox::Ptr m_botRightX;
        tgui::EditBox::Ptr m_botRightY;
        tgui::Button::Ptr m_addFrame;

		// Sprite Data
		sf::Texture m_sheetTexture;
        sf::Sprite m_sheetSprite;
	};

}