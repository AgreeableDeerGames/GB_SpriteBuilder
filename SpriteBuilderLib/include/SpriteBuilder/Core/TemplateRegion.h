#pragma once

#include <SpriteBuilder/Utils/DllUtils.h>

#include <GameBackbone/Core/GameRegion.h>

#include <TGUI/TGUI.hpp>



namespace GB::SB
{
    class libSpriteBuilder TemplateRegion : public GB::GameRegion
    {
    public:
        TemplateRegion(sf::RenderWindow& window);
        //using GB::GameRegion::GameRegion;

        // GUI
        tgui::Gui& getGUI();

    private:

        // GUI
        tgui::Gui regionGUI;
    };
}