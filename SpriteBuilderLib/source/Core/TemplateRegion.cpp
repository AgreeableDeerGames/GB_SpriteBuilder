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

	m_editBox = tgui::EditBox::create();
	m_editBox->setPosition(50, 50);
	m_editBox->setSize(300, 30);
	m_editBox->setTextSize(16);
	this->GetGUI().add(m_editBox);

	m_loadButton = tgui::Button::create();
	//m_loadButton->setRenderer(theme.getRenderer("Button"));
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
		m_sheetSprite.setPosition(50, 150);

		this->addDrawable(0, m_sheetSprite);
		CreateLoadedGui();
	}
	else
	{
		this->removeDrawable(m_sheetSprite);
	}
}

void TemplateRegion::CreateLoadedGui()
{
	/*
	tgui::EditBox::Ptr m_topLeftX;
	tgui::EditBox::Ptr m_topLeftY;
	tgui::EditBox::Ptr m_botRightX;
	tgui::EditBox::Ptr m_botRightY;
	tgui::Button::Ptr m_addTexture;
	*/
	m_topLeftX = tgui::EditBox::create();
	m_topLeftX->setPosition(50, 100);
	m_topLeftX->setSize(50, 30);
	m_topLeftX->setTextSize(16);
	this->GetGUI().add(m_topLeftX);
	
	m_topLeftY = tgui::EditBox::create();
	m_topLeftY->setPosition(120, 100);
	m_topLeftY->setSize(50, 30);
	m_topLeftY->setTextSize(16);
	this->GetGUI().add(m_topLeftY);
	
	m_botRightX = tgui::EditBox::create();
	m_botRightX->setPosition(190, 100);
	m_botRightX->setSize(50, 30);
	m_botRightX->setTextSize(16);
	this->GetGUI().add(m_botRightX);
	
	m_botRightY = tgui::EditBox::create();
	m_botRightY->setPosition(260, 100);
	m_botRightY->setSize(50, 30);
	m_botRightY->setTextSize(16);
	this->GetGUI().add(m_botRightY);

	m_addFrame = tgui::Button::create();
	//m_addFrame->setRenderer(theme.getRenderer("Button"));
	m_addFrame->setPosition(350, 100);
	m_addFrame->setSize(100, 30);
	m_addFrame->setText("Add ");
	m_addFrame->connect("pressed", &TemplateRegion::LoadTexture, this);
	this->GetGUI().add(m_addFrame);
}