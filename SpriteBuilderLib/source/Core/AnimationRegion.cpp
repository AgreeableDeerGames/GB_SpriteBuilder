#include <SpriteBuilder/Core/AnimationRegion.h>
#include <SpriteBuilder/Utils/DllUtils.h>

#include <GameBackbone/Core/GameRegion.h>

#include <TGUI/TGUI.hpp>
#include <TGUI/Widgets/TextBox.hpp>
#include <TGUI/Widgets/Button.hpp>

#include <charconv>
#include <string>

using namespace GB::SB;

void AnimationRegion::InitGui()
{
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
	m_addFrame->connect("pressed", &AnimationRegion::AddFrame, this);
	this->GetGUI().add(m_addFrame);
}

void AnimationRegion::AddFrame()
{
	int topLeftX = 0;
	int topLeftY = 0;
	int botRightX = 0;
	int botRightY = 0;


	// Parse the user input dimensions of the animation frame
	std::string topLeftXStr = m_topLeftX->getText().toAnsiString();
	const auto praseTopLeftXResult = std::from_chars(topLeftXStr.data(), topLeftXStr.data() + topLeftXStr.size(), topLeftX);

	std::string topLeftYStr = m_topLeftY->getText().toAnsiString();
	const auto praseTopLeftYResult = std::from_chars(topLeftYStr.data(), topLeftYStr.data() + topLeftYStr.size(), topLeftY);

	std::string  botRightXStr = m_botRightX->getText().toAnsiString();
	const auto praseBotRightXResult = std::from_chars(botRightXStr.data(), botRightXStr.data() + botRightXStr.size(), botRightX);

	std::string botRightYStr = m_botRightY->getText().toAnsiString();
	const auto praseBotRightYResult = std::from_chars(botRightYStr.data(), botRightYStr.data() + botRightYStr.size(), botRightY);

	if (praseTopLeftXResult.ec != std::errc() ||
		praseTopLeftYResult.ec  != std::errc() ||
		praseBotRightXResult.ec  != std::errc() ||
		praseBotRightYResult.ec  != std::errc())
	{
		throw std::runtime_error("Invalid frame dim strings");
	}

	sf::IntRect frameBounds(topLeftX, topLeftY, botRightX - topLeftX, botRightY - topLeftY);
}

void AnimationRegion::HandleMouseMove(sf::Vector2f windowCoordinates)
{
	/*
	if (coords are within texture bounds)
	{
		convert coords to pixel coords on the texture

		use pixel coords to populate the two edit boxes that have "focus"/"priority"
	}
	else
	{
		// I think do nothing.
	}
	*/
}

