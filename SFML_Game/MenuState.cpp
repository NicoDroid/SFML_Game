#include "SFML/Graphics.hpp"

#include <iostream>

#include "MenuState.h"
#include "GameState.h"
#include "PlayState.h"
#include "OptionState.h"
#include "FileController.h"

MenuState::MenuState(Game* game, SoundController* soundfond, SoundController* soundfond2)
{

	this->game = game;
	game->window.setSize(sf::Vector2u(FileController::RecupFileOption()[2], FileController::RecupFileOption()[3]));
	game->window.setMouseCursorVisible(false);

	if (!font.loadFromFile("Ressources/Fonts/arial.ttf"));
	if (!texture_titre.loadFromFile("Ressources/Sheets/titre.png"))
	{
		//handle error
	}
	if (!texture.loadFromFile("Ressources/Sheets/sample.png"))
	{
		// erreur...
	}

	sprite.setTexture(texture);
	sprite.scale(sf::Vector2f(2.5, 2.5));
	sprite_titre.setTexture(texture_titre);
	sprite_titre.setPosition(sf::Vector2f(250, 150));
	sprite_titre.scale(sf::Vector2f(1.5, 1.5));

	view.reset(sf::FloatRect(0, 0, 1920, 1080));
	game->window.setView(view);

	m_sound = soundfond;
	m_sound2 = soundfond2;
	m_sound->Play();
	m_sound2->Stop();

	float width = game->window.getSize().x;
	float height = game->window.getSize().y;
	//std::cout << "x: " << game->window.getSize().x << std::endl;
	//std::cout << "y: " << game->window.getSize().y << std::endl;
	
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Red);
	text[0].setString("Play");
	text[0].setCharacterSize(40);
	text[0].setOrigin(20,20);
	text[0].setPosition(sf::Vector2f(1920 / 2, 1080 / (MAX_NUMBER_OF_ITEMS_MENU + 1) * 1));

	text[1].setFont(font);
	text[1].setFillColor(sf::Color::White);
	text[1].setString("Options");
	text[1].setCharacterSize(40);
	text[1].setOrigin(20, 20);
	text[1].setPosition(sf::Vector2f(1920/ 2, 1080 / (MAX_NUMBER_OF_ITEMS_MENU + 1) * 2));

	text[2].setFont(font);
	text[2].setFillColor(sf::Color::White);
	text[2].setString("Exit");
	text[2].setCharacterSize(40);
	text[2].setOrigin(20, 20);
	text[2].setPosition(sf::Vector2f(1920/ 2, 1080 / (MAX_NUMBER_OF_ITEMS_MENU + 1) * 3));
}

void MenuState::handleInput()
{
	sf::Event event;

	while (game->window.pollEvent(event))
	{
		switch (event.type)
		{
			// ferme la fenêtre
		case sf::Event::Closed:
			game->window.close();
			break;

			// change entre les GameState
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Up)
				MoveUp();
			else if (event.key.code == sf::Keyboard::Down)
				MoveDown();
			else if (event.key.code == sf::Keyboard::Return && selectedItemIndex == 0)
				loadgame();
			else if (event.key.code == sf::Keyboard::Return && selectedItemIndex == 1)
				loadoptions();
			else if (event.key.code == sf::Keyboard::Return && selectedItemIndex == 2)
				game->window.close();
			break;
		}
	}
}

MenuState::~MenuState()
{
	delete m_sound;
	delete m_sound2;
}

void MenuState::update(const float dt)
{

}

void MenuState::draw(const float dt)
{
	game->window.draw(sprite);
	game->window.draw(sprite_titre);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS_MENU; i++)
	{
		game->window.draw(text[i]);
	}
}

void MenuState::loadgame()
{
	game->pushState(new PlayState(game, m_sound, m_sound2));
	m_sound->Stop();
}

void MenuState::loadoptions()
{
	game->pushState(new OptionState(game, m_sound, m_sound2));
}

void MenuState::MoveUp()
{
	if (selectedItemIndex == 0)
	{
		text[0].setFillColor(sf::Color::White);
		text[1].setFillColor(sf::Color::White);
		text[2].setFillColor(sf::Color::Red);

		selectedItemIndex = 2;
	}
	else if (selectedItemIndex == 1)
	{
		text[0].setFillColor(sf::Color::Red);
		text[1].setFillColor(sf::Color::White);
		text[2].setFillColor(sf::Color::White);

		selectedItemIndex = 0;
	}
	else if (selectedItemIndex == 2)
	{
		text[0].setFillColor(sf::Color::White);
		text[1].setFillColor(sf::Color::Red);
		text[2].setFillColor(sf::Color::White);

		selectedItemIndex = 1;
	}
}

void MenuState::MoveDown()
{
	if (selectedItemIndex == 0)
	{
		text[0].setFillColor(sf::Color::White);
		text[1].setFillColor(sf::Color::Red);
		text[2].setFillColor(sf::Color::White);

		selectedItemIndex = 1;
	}
	else if (selectedItemIndex == 1)
	{
		text[0].setFillColor(sf::Color::White);
		text[1].setFillColor(sf::Color::White);
		text[2].setFillColor(sf::Color::Red);

		selectedItemIndex = 2;
	}
	else if (selectedItemIndex == 2)
	{
		text[0].setFillColor(sf::Color::Red);
		text[1].setFillColor(sf::Color::White);
		text[2].setFillColor(sf::Color::White);

		selectedItemIndex = 0;
	}
}



