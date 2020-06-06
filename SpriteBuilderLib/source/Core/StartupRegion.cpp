
#include <SpriteBuilder/Core/StartupRegion.h>

#include <TGUI/TGUI.hpp>

using namespace GB::SB;

void StartupRegion::InitGui()
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
	m_loadButton->connect("pressed", &StartupRegion::LoadTexture, this);
	this->GetGUI().add(m_loadButton);
}

void StartupRegion::LoadTexture()
{
	SwapToAnimationRegion(m_editBox->getText());
}

void StartupRegion::SwapToAnimationRegion(sf::String filePath)
{

}