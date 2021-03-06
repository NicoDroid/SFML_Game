#include "SFML/Graphics.hpp"

#include <iostream>

#include "OptionState.h"
#include "MenuState.h"
#include "gameState.h"
#include "FileController.h"

OptionState::OptionState(Game* game, SoundController* soundfond)
{
	this->game = game;

	m_sound = soundfond;

	vector<int>Config = FileController::RecupFileOption();
	m_VolumeMenu = Config[0];
	m_VolumeGame = Config[1];

	if (!font.loadFromFile("Ressources/Fonts/arial.ttf"))
	{
		//handle error
	}

	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Blue);
	text[0].setString("OPTIONS");
	text[0].setPosition(sf::Vector2f(100, 100));

	text[1].setFont(font);
	text[1].setFillColor(sf::Color::Red);
	text[1].setString("Volume du menu: ");
	text[1].setPosition(sf::Vector2f(50, 200));

	text[2].setFont(font);
	text[2].setFillColor(sf::Color::Red);
	text[2].setString(std::to_string(m_VolumeMenu));
	text[2].setPosition(sf::Vector2f(300, 200));

	text[3].setFont(font);
	text[3].setFillColor(sf::Color::White);
	text[3].setString("Volume du jeu: ");
	text[3].setPosition(sf::Vector2f(50, 400));

	text[4].setFont(font);
	text[4].setFillColor(sf::Color::White);
	text[4].setString(std::to_string(m_VolumeGame));
	text[4].setPosition(sf::Vector2f(300, 400));
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
			{
				FileController::SetFileOption(m_VolumeMenu, m_VolumeGame);
				loadmenu();
			}
			else if (event.key.code == sf::Keyboard::Up)
				MoveUp();
			else if (event.key.code == sf::Keyboard::Down)
				MoveDown();
			else if (event.key.code == sf::Keyboard::Right)
				upSound();
			else if (event.key.code == sf::Keyboard::Left)
				downSound();
			break;
		}
	}
}

void OptionState::update(const float dt)
{

}

void OptionState::draw(const float dt)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS_OPTION; i++)
	{
		game->window.draw(text[i]);
	}	
}

void OptionState::loadmenu()
{
	game->pushState(new MenuState(game, m_sound));
}

void OptionState::MoveUp()
{
	if (selectedItemIndex == 0)
	{
		text[1].setFillColor(sf::Color::White);
		text[2].setFillColor(sf::Color::White);
		text[3].setFillColor(sf::Color::Red);
		text[4].setFillColor(sf::Color::Red);

		selectedItemIndex = 1;
	}
	else if (selectedItemIndex == 1)
	{
		text[1].setFillColor(sf::Color::Red);
		text[2].setFillColor(sf::Color::Red);
		text[3].setFillColor(sf::Color::White);
		text[4].setFillColor(sf::Color::White);

		selectedItemIndex = 0;
	}
}

void OptionState::MoveDown()
{
	if (selectedItemIndex == 0)
	{
		text[1].setFillColor(sf::Color::White);
		text[2].setFillColor(sf::Color::White);
		text[3].setFillColor(sf::Color::Red);
		text[4].setFillColor(sf::Color::Red);

		selectedItemIndex = 1;
	}
	else if (selectedItemIndex == 1)
	{
		text[1].setFillColor(sf::Color::Red);
		text[2].setFillColor(sf::Color::Red);
		text[3].setFillColor(sf::Color::White);
		text[4].setFillColor(sf::Color::White);

		selectedItemIndex = 0;
	}
}

void OptionState::upSound()
{
	if (m_VolumeMenu < 100 && selectedItemIndex==0)
	{
		text[2].setString(std::to_string(m_VolumeMenu += 10));
		m_sound->SetVolume(m_VolumeMenu);
	}
	else if (m_VolumeGame < 100 && selectedItemIndex == 1)
	{
		text[4].setString(std::to_string(m_VolumeGame += 10));
	}
}

void OptionState::downSound()
{
	if (m_VolumeMenu > 0 && selectedItemIndex == 0)
	{
		text[2].setString(std::to_string(m_VolumeMenu -= 10));
		m_sound->SetVolume(m_VolumeMenu);
	}
	else if (m_VolumeGame > 0 && selectedItemIndex == 1)
	{
		text[4].setString(std::to_string(m_VolumeGame -= 10));
	}
}