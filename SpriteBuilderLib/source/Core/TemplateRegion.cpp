#include <SpriteBuilder/Core/TemplateRegion.h>

#include <TGUI/Widgets/TextBox.hpp>

#include <SFML/Graphics/Texture.hpp>

using namespace GB::SB;

/// <summary>
/// Initializes a new instance of the <see cref="DemoRegion"/> class.
/// </summary>
/// <param name="window">The window.</param>
TemplateRegion::TemplateRegion(sf::RenderWindow& window) : m_regionGUI(window) {}

tgui::Gui& TemplateRegion::GetGUI()
{
    return m_regionGUI;
};