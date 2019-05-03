#include "SFML/Graphics.hpp"

#include <iostream>

#include "OptionState.h"
#include "MenuState.h"
#include "gameState.h"

OptionState::OptionState(Game* game, SoundController* soundfond)
{
	this->game = game;

	m_sound = soundfond;

	if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
	{
		//handle error
	}

	text.setFont(font);
	text.setFillColor(sf::Color::Red);
	text.setString("OPTIONS");
	text.setPosition(sf::Vector2f(100, 100));
}

OptionState::~OptionState()
{
	delete m_sound;
}

void OptionState::handleInput()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			game->window.close();
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				loadmenu();
			else if (event.key.code == sf::Keyboard::Z)
				m_sound->SetVolume(100);
			break;
		}
	}
}

void OptionState::update(const float dt)
{

}

void OptionState::draw(const float dt)
{
	game->window.draw(text);
}

void OptionState::loadmenu()
{
	game->pushState(new MenuState(game, m_sound));
}