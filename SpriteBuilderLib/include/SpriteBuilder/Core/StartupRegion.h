#pragma once

#include <SpriteBuilder/Core/TemplateRegion.h>
#include <SpriteBuilder/Utils/DllUtils.h>

#include <TGUI/TGUI.hpp>
#include <TGUI/Widgets/TextBox.hpp>
#include <TGUI/Widgets/Button.hpp>


namespace GB::SB
{
    class libSpriteBuilder StartupRegion : public TemplateRegion
    {
    public:
        StartupRegion(sf::RenderWindow& window);

        // GUI
        void InitGui();


    private:
        void LoadTexture();

        void SwapToAnimationRegion(sf::String filePath);

        // GUI
        tgui::Gui m_regionGUI;
        tgui::EditBox::Ptr m_editBox;
        tgui::Button::Ptr m_loadButton;
    };
}