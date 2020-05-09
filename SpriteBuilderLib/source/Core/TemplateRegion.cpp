#include <SpriteBuilder/Core/TemplateRegion.h>

using namespace GB::SB;

/// <summary>
/// Initializes a new instance of the <see cref="DemoRegion"/> class.
/// </summary>
/// <param name="window">The window.</param>
TemplateRegion::TemplateRegion(sf::RenderWindow& window) : regionGUI(window) {
	//initGui();
}

tgui::Gui& TemplateRegion::getGUI()
{
    return regionGUI;
};