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

	avion = new vector<Entite*>;

	/*
	avion[0] = new Infanterie(&texture_map, sf::IntRect(1152, 704, 64, 64));
	avion->setPosition(sf::Vector2f(0, 672));*/

	if (!font.loadFromFile("Ressources/Fonts/arial.ttf"))
	{
		// erreur...
	}
	if (!fond_pause.loadFromFile("Ressources/Sheets/back_paused.png"))
	{
		// erreur...
	}
	Paused = new EventController('p', &font, &fond_pause);

	// on charge la texture du tileset
	if (!texture_map.loadFromFile("Ressources/Tiled/Tilesheet.png"))
	{
		//handle error
	}
	if (!texture_life.loadFromFile("Ressources/Sheets/sheet_vie.png"))
	{
		//handle error
	}
	map_one.load(texture_map, sf::Vector2u(64, 64), level, 30, 17);	

	life = new Life_Controller(&texture_life);
	money = new Money_Controller(&texture_map);

	/*
	avion.push_back(new Infanterie(&texture_map, sf::IntRect(1152, 704, 64, 64)));
	avion.push_back(new Infanterie(&texture_map, sf::IntRect(1152, 704, 64, 64)));
	avion.push_back(new Infanterie(&texture_map, sf::IntRect(1152, 704, 64, 64)));
	avion.push_back(new Infanterie(&texture_map, sf::IntRect(1152, 704, 64, 64)));
	avion.push_back(new Infanterie(&texture_map, sf::IntRect(1152, 704, 64, 64)));
	*/
}

void PlayState::draw(const float dt)
{
	game->window.draw(map_one);
	game->window.draw(money->sprite_dollar);
	game->window.draw(money->sprite_deci);
	game->window.draw(money->sprite_uni);
	game->window.draw(life->sprite);
	for (int i = 0; i < avion->size(); i++)
	{
		game->window.draw(avion->at(i)->sprite);
	}
	if (Paused->Paused())
	{
		game->window.draw(Paused->back_pause);
		game->window.draw(Paused->text_pause);
	}
}

void PlayState::update(const float dt)
{
	if (Paused->Paused())
	{
		clock.restart();
	}
	else
	{
		if (life->getLife() != 0)
		{
			if (clock.getElapsedTime().asSeconds() > 2.0f) {
				avion->push_back(new Infanterie(&texture_map, sf::IntRect(1152, 704, 64, 64)));
				clock.restart();
			}

			for (int i = 0; i < avion->size(); i++)
			{
				avion->at(i)->road();
				if (EventController::EventDestroyEntite(avion))
				{
					life->decrementLife();
				}
			}
		}
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
			if (event.key.code == sf::Keyboard::P)
				Paused->Paused(!Paused->Paused());
			else if (event.key.code == sf::Keyboard::A && !Paused->Paused())
			{
				money->increment(1);
			}
			else if (event.key.code == sf::Keyboard::Z && !Paused->Paused())
			{
				money->decrement(1);
			}
			break;
		}
	}
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