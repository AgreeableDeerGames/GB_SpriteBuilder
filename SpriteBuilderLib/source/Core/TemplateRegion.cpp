#include <SpriteBuilder/Core/TemplateRegion.h>

#include <TGUI/Widgets/TextBox.hpp>

#include <SFML/Graphics/Texture.hpp>

using namespace GB::SB;

/// <summary>
/// Initializes a new instance of the <see cref="DemoRegion"/> class.
/// </summary>
/// <param name="window">The window.</param>
TemplateRegion::TemplateRegion(sf::RenderWindow& window) : m_regionGUI(window) {
	InitGui();
}

void TemplateRegion::InitGui()
{
	tgui::Theme theme("TGUI_Widgets/Black.txt");

	// Get a bound version of the window size
	// Passing this to setPosition or setSize will make the widget automatically update when the view of the gui changes
	tgui::Layout windowWidth = tgui::bindWidth(this->GetGUI());
	tgui::Layout windowHeight = tgui::bindHeight(this->GetGUI());

	// create a button to return to the parent region
	m_editBox = tgui::EditBox::create();
	m_editBox->setPosition(50, 50);
	m_editBox->setSize(300, 30);
	m_editBox->setTextSize(16);
	this->GetGUI().add(m_editBox);

	// Create a button to return to the parent region
	m_loadButton = tgui::Button::create();
	m_loadButton->setRenderer(theme.getRenderer("Button"));
	m_loadButton->setPosition(400, 50);
	m_loadButton->setSize(100, 30);
	m_loadButton->setText("Load Texture");
	m_loadButton->connect("pressed", &TemplateRegion::LoadTexture, this);
	this->GetGUI().add(m_loadButton);

}

tgui::Gui& TemplateRegion::GetGUI()
{
    return m_regionGUI;
};

void TemplateRegion::LoadTexture()
{
	// Load a texture for the animated sprite
	if (m_sheetTexture.loadFromFile(m_editBox->getText()))
	{
		m_sheetSprite.setTexture(m_sheetTexture);
		m_sheetSprite.setPosition(50, 100);

		this->addDrawable(0, m_sheetSprite);
	}
	else
	{
		this->removeDrawable(m_sheetSprite);
	}
}