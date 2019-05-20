#include <SFML/Graphics.hpp>

#include <iostream>

#include "PlayState.h"
#include "MenuState.h"
#include "GameState.h"

const int level[] =
{
	24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,
24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,
24,24,24,24,24,24,24,86,210,254,254,254,254,254,254,211,86,24,24,24,24,24,24,24,24,24,24,24,24,24,
24,24,24,24,24,24,24,24,232,84,84,224,224,84,84,230,24,24,24,24,24,24,24,24,24,24,24,24,24,24,
24,24,24,24,24,24,24,24,232,84,84,224,224,84,84,230,24,24,24,24,24,24,24,24,24,24,24,24,24,24,
24,24,24,24,24,24,24,24,232,178,178,207,209,178,178,230,24,24,24,24,24,24,24,24,24,24,24,24,24,24,
24,24,24,24,24,24,24,24,232,178,178,230,232,178,178,230,24,24,24,24,24,24,24,24,24,24,24,24,24,24,
24,24,24,24,24,24,24,86,232,178,178,230,232,178,178,230,86,24,24,24,24,24,24,24,24,24,24,24,24,24,
254,254,254,254,254,254,254,254,255,178,178,230,232,178,178,253,254,254,254,254,254,254,254,254,254,254,254,211,86,24,
224,224,224,224,224,224,224,224,224,84,84,230,232,84,84,224,224,224,224,224,224,224,224,224,224,84,84,230,24,24,
224,224,224,224,224,224,224,224,224,84,84,230,232,84,84,224,224,224,224,224,224,224,224,224,224,84,84,230,24,24,
208,208,208,208,208,208,208,208,208,208,208,234,233,208,208,208,208,208,208,208,208,208,208,208,209,178,178,230,24,24,
24,24,24,24,24,24,24,86,24,24,24,24,24,24,24,24,86,24,24,24,24,24,24,86,232,178,178,230,86,24,
24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,232,178,178,230,24,24,
24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,232,178,178,230,24,24,
24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,232,178,178,230,24,24,
24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,232,178,178,230,24,24

};


PlayState::PlayState(Game* game)
{
	this->game = game;

	// on charge la texture du tileset
	if (!texture.loadFromFile("Ressources/Tiled/Tilesheet.png"))
	{
		//handle error
	}

	map.load(texture, sf::Vector2u(64, 64), level, 30, 17);

	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(1152, 704, 64, 64));
	sprite.setOrigin(32, 32);
	sprite.setPosition(0, 672);
	
}

void PlayState::draw(const float dt)
{
	game->window.draw(map);
	game->window.draw(sprite);
}

void PlayState::update(const float dt)
{
	
	if (sprite.getPosition().x == 0 && sprite.getPosition().y==672)
	{
		status = 1;
	}else if(sprite.getPosition().x == 670 && sprite.getPosition().y == 672)
	{
		sprite.rotate(-90);		
		status = 2;
		
	}else if (sprite.getPosition().x == 670 && sprite.getPosition().y == 287)
	{
		
		status = 1;
		sprite.rotate(90);
	}else if (sprite.getPosition().x == 865 && sprite.getPosition().y == 287)
	{
		
		status = 3;
		sprite.rotate(90);
	}
	else if (sprite.getPosition().x == 865 && sprite.getPosition().y == 672)
	{
		
		status = 1;
		sprite.rotate(-90);
	}
	else if (sprite.getPosition().x == 1630 && sprite.getPosition().y == 672)
	{
		sprite.rotate(90);
		status = 3;
		
	}
	else if (sprite.getPosition().x == 1630 && sprite.getPosition().y == 1017)
	{
		cout << "Game Over" << endl;
	}

	if (status == 1)
	{
		sprite.move(5, 0);
	}else if(status == 2)
	{
		sprite.move(0, -5);
	}
	else if (status == 3)
	{
		sprite.move(0, 5);
	}
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




/*
	if (event.key.code == sf::Keyboard::Right)
			{
				sprite.move(5, 0);

			}
			else if (event.key.code == sf::Keyboard::Up)
			{
				sprite.move(0, -5);
			}
			else if (event.key.code == sf::Keyboard::Left)
			{
				sprite.rotate(-90);
			}
			else if (event.key.code == sf::Keyboard::Down)
			{
				sprite.move(0, 5);
			}
			else if (event.key.code == sf::Keyboard::H)
			{
				cout << sprite.getPosition().x << endl;
				cout << sprite.getPosition().y << endl;
			}
*/