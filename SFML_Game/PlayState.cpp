#include <SFML/Graphics.hpp>

#include <iostream>

#include "PlayState.h"
#include "MenuState.h"
#include "GameState.h"


PlayState::PlayState(Game* game)
{
	this->game = game;
}

void PlayState::draw(const float dt)
{
	sf::RectangleShape rect;
	rect.setPosition(sf::Vector2f(100, 100));
	rect.setSize(sf::Vector2f(100, 100));
	rect.setFillColor(sf::Color::Green);

	game->window.draw(rect);
}

void PlayState::update(const float dt)
{
}

void PlayState::handleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			this->game->window.close();
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				PauseGame();
			break;

		}
	}
}

void PlayState::PauseGame()
{
	std::cout << "Pause" << std::endl;
}