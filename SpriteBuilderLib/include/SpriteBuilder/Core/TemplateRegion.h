#pragma once

#include <SpriteBuilder/Utils/DllUtils.h>

#include <GameBackbone/Core/GameRegion.h>

#include <TGUI/TGUI.hpp>



namespace GB::SB
{
    class libSpriteBuilder TemplateRegion : public GB::GameRegion
    {
    public:
        using GB::GameRegion::GameRegion;


        // GUI
        tgui::Gui& getGUI() {
            return regionGUI;
        };

    private:

        //GUI
        tgui::Gui regionGUI;
    };
}