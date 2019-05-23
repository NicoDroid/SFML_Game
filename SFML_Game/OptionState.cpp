#include "SFML/Graphics.hpp"

#include <iostream>
#include <sstream>

#include "OptionState.h"
#include "MenuState.h"
#include "gameState.h"
#include "FileController.h"

OptionState::OptionState(Game* game, SoundController* soundfond, SoundController* soundfond2)
{
	

	this->game = game;
	game->window.setMouseCursorVisible(false);

	m_sound = soundfond;
	m_sound2 = soundfond2;

	vector<int>Config = FileController::RecupFileOption();
	m_VolumeMenu = Config[0];
	m_VolumeGame = Config[1];

	scaleX = Config[2];
	scaleY = Config[3];

	std::stringstream sresolution;
	sresolution << scaleX << " X " << scaleY;
	resolution = sresolution.str();
	
	if (!texture.loadFromFile("Ressources/Sheets/sample.png"))
	{
		// erreur...
	}
	if (!font.loadFromFile("Ressources/Fonts/arial.ttf"))
	{
		//handle error
	}

	sprite.setTexture(texture);
	//sprite.setTextureRect(sf::IntRect(0, 0, 1920, 1080));
	sprite.scale(sf::Vector2f(2.5, 2.5));

	view.reset(sf::FloatRect(0, 0, 1920, 1080));
	game->window.setView(view);

	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Blue);
	text[0].setString("OPTIONS");
	text[0].setPosition(1920 / 2, 1080 / (MAX_NUMBER_OF_ITEMS_OPTION + 1) * 1);

	text[1].setFont(font);
	text[1].setFillColor(sf::Color::Red);
	text[1].setString("Volume du menu: ");
	text[1].setPosition(1920 / 2, 1080 / (MAX_NUMBER_OF_ITEMS_OPTION + 1) * 2);

	text[2].setFont(font);
	text[2].setFillColor(sf::Color::Red);
	text[2].setString(std::to_string(m_VolumeMenu));
	text[2].setPosition(1920 / 2 +300, 1080 / (MAX_NUMBER_OF_ITEMS_OPTION + 1) * 2);

	text[3].setFont(font);
	text[3].setFillColor(sf::Color::White);
	text[3].setString("Volume du jeu: ");
	text[3].setPosition(1920 / 2, 1080 / (MAX_NUMBER_OF_ITEMS_OPTION + 1) * 3);

	text[4].setFont(font);
	text[4].setFillColor(sf::Color::White);
	text[4].setString(std::to_string(m_VolumeGame));
	text[4].setPosition(1920 / 2 +300, 1080 / (MAX_NUMBER_OF_ITEMS_OPTION + 1) * 3);

	text[5].setFont(font);
	text[5].setFillColor(sf::Color::White);
	text[5].setString("Resolution: ");
	text[5].setPosition(1920 / 2, 1080 / (MAX_NUMBER_OF_ITEMS_OPTION + 1) * 4);

	text[6].setFont(font);
	text[6].setFillColor(sf::Color::White);
	text[6].setString(resolution);
	text[6].setPosition(1920 / 2 + 300, 1080 / (MAX_NUMBER_OF_ITEMS_OPTION + 1) * 4);
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
				FileController::SetFileOption(m_VolumeMenu, m_VolumeGame, scaleX, scaleY);
				loadmenu();
			}
			else if (event.key.code == sf::Keyboard::Up)
				MoveUp();
			else if (event.key.code == sf::Keyboard::Down)
				MoveDown();
			else if (event.key.code == sf::Keyboard::Right)
				upValeur();
			else if (event.key.code == sf::Keyboard::Left)
				downValeur();
			break;
		}
	}
}

void OptionState::update(const float dt)
{

}

void OptionState::draw(const float dt)
{
	game->window.draw(sprite);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS_OPTION; i++)
	{
		game->window.draw(text[i]);
	}	
}

void OptionState::loadmenu()
{
	game->pushState(new MenuState(game, m_sound, m_sound2));
}

void OptionState::MoveUp()
{
	if (selectedItemIndex == 0)
	{
		text[1].setFillColor(sf::Color::White);
		text[2].setFillColor(sf::Color::White);
		text[3].setFillColor(sf::Color::White);
		text[4].setFillColor(sf::Color::White);
		text[5].setFillColor(sf::Color::Red);
		text[6].setFillColor(sf::Color::Red);

		selectedItemIndex = 2;
	}
	else if (selectedItemIndex == 1)
	{
		text[1].setFillColor(sf::Color::Red);
		text[2].setFillColor(sf::Color::Red);
		text[3].setFillColor(sf::Color::White);
		text[4].setFillColor(sf::Color::White);
		text[5].setFillColor(sf::Color::White);
		text[6].setFillColor(sf::Color::White);

		selectedItemIndex = 0;
	}
	else if (selectedItemIndex == 2)
	{
		text[1].setFillColor(sf::Color::White);
		text[2].setFillColor(sf::Color::White);
		text[3].setFillColor(sf::Color::Red);
		text[4].setFillColor(sf::Color::Red);
		text[5].setFillColor(sf::Color::White);
		text[6].setFillColor(sf::Color::White);

		selectedItemIndex = 1;
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
		text[5].setFillColor(sf::Color::White);
		text[6].setFillColor(sf::Color::White);

		selectedItemIndex = 1;
	}
	else if (selectedItemIndex == 1)
	{
		text[1].setFillColor(sf::Color::White);
		text[2].setFillColor(sf::Color::White);
		text[3].setFillColor(sf::Color::White);
		text[4].setFillColor(sf::Color::White);
		text[5].setFillColor(sf::Color::Red);
		text[6].setFillColor(sf::Color::Red);

		selectedItemIndex = 2;
	}
	else if (selectedItemIndex == 2)
	{
		text[1].setFillColor(sf::Color::Red);
		text[2].setFillColor(sf::Color::Red);
		text[3].setFillColor(sf::Color::White);
		text[4].setFillColor(sf::Color::White);
		text[5].setFillColor(sf::Color::White);
		text[6].setFillColor(sf::Color::White);

		selectedItemIndex = 0;
	}
}

void OptionState::upValeur()
{
	if (m_VolumeMenu < 100 && selectedItemIndex==0)
	{
		text[2].setString(std::to_string(m_VolumeMenu += 10));
		m_sound->SetVolume(m_VolumeMenu);
	}
	else if (m_VolumeGame < 100 && selectedItemIndex == 1)
	{
		text[4].setString(std::to_string(m_VolumeGame += 10));
		m_sound2->SetVolume(m_VolumeGame);
	}
	else if (selectedItemIndex == 2)
	{
		switch (scaleX)
		{
		case 1920:
			scaleX = 1280;
			scaleY = 720;
			resolution = "1280 X 720";
			break;
		case 1280:
			scaleX = 1366;
			scaleY = 768;
			resolution = "1366 X 768";
			break;
		case 1366:
			scaleX = 1024;
			scaleY = 768;
			resolution = "1024 X 768";
			break;
		case 1024:
			scaleX = 800;
			scaleY = 600;
			resolution = "800 X 600";
			break;
		case 800:
			scaleX = 1920;
			scaleY = 1080;
			resolution = "1920 X 1080";
			break;
		default:
			break;
		}
		text[6].setString(resolution);
	}
}

void OptionState::downValeur()
{
	if (m_VolumeMenu > 0 && selectedItemIndex == 0)
	{
		text[2].setString(std::to_string(m_VolumeMenu -= 10));
		m_sound->SetVolume(m_VolumeMenu);
	}
	else if (m_VolumeGame > 0 && selectedItemIndex == 1)
	{
		text[4].setString(std::to_string(m_VolumeGame -= 10));
		m_sound2->SetVolume(m_VolumeGame);
	}
	else if (selectedItemIndex == 2)
	{
		switch (scaleX)
		{
		case 1920:
			scaleX = 800;
			scaleY = 600;
			resolution = "800 X 600";
			break;
		case 1280:
			scaleX = 1920;
			scaleY = 1080;
			resolution = "1920 X 1080";
			break;
		case 1366:
			scaleX = 1280;
			scaleY = 720;
			resolution = "1280 X 72";
			break;
		case 1024:
			scaleX = 1366;
			scaleY = 720;
			resolution = "1366 X 720";
			break;
		case 800:
			scaleX = 1024;
			scaleY = 720;
			resolution = "1024 X 720";
			break;
		default:
			break;
		}
		text[6].setString(resolution);
	}
}
