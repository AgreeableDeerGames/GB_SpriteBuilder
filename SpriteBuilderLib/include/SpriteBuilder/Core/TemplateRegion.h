#pragma once

#include <SpriteBuilder/Utils/DllUtils.h>

#include <GameBackbone/Core/GameRegion.h>

#include <TGUI/TGUI.hpp>
#include <TGUI/Widgets/TextBox.hpp>
#include <TGUI/Widgets/Button.hpp>



namespace GB::SB
{
    class libSpriteBuilder TemplateRegion : public GB::GameRegion
    {
    public:
        TemplateRegion(sf::RenderWindow& window);

        // GUI
        void InitGui();
        tgui::Gui& GetGUI();


    private:
        void LoadTexture();

        // Loaded Gui
        void CreateLoadedGui();
        tgui::EditBox::Ptr m_topLeftX;
        tgui::EditBox::Ptr m_topLeftY;
        tgui::EditBox::Ptr m_botRightX;
        tgui::EditBox::Ptr m_botRightY;
        tgui::Button::Ptr m_addFrame;

        // GUI
        tgui::Gui m_regionGUI;
        tgui::EditBox::Ptr m_editBox;
        tgui::Button::Ptr m_loadButton;


        sf::Texture m_sheetTexture;
        sf::Sprite m_sheetSprite;
    };
}