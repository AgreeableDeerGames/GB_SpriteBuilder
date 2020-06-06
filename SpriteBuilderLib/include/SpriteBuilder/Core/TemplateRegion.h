#pragma once

#include <SpriteBuilder/Utils/DllUtils.h>

#include <GameBackbone/Core/GameRegion.h>

#include <TGUI/TGUI.hpp>
#include <TGUI/Widgets/TextBox.hpp>
#include <TGUI/Widgets/Button.hpp>

#include <SFML/System/Vector2.hpp>



namespace GB::SB
{
    class libSpriteBuilder TemplateRegion : public GB::GameRegion
    {
    public:
        TemplateRegion(sf::RenderWindow& window);

        virtual void HandleMouseMove(sf::Vector2f windowCoordinates){}

        tgui::Gui& TemplateRegion::GetGUI();

    private:
        // GUI
        tgui::Gui m_regionGUI;

    };
}