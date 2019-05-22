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

	if (!font.loadFromFile("Ressources/Fonts/arial.ttf"))
	{
		// erreur...
	}
	if (!fond_pause.loadFromFile("Ressources/Sheets/back_paused.png"))
	{
		// erreur...
	}
	if (!texture_bouton.loadFromFile("Ressources/Sheets/boutons.png"))
	{
		// erreur...
	}
	if (!texture_fond_bouton.loadFromFile("Ressources/Sheets/fond_boutons.png"))
	{
		// erreur...
	}
	if (!texture_map.loadFromFile("Ressources/Tiled/Tilesheet.png"))
	{
		//handle error
	}
	if (!texture_life.loadFromFile("Ressources/Sheets/sheet_vie.png"))
	{
		//handle error
	}
	if (!texture_explosion.loadFromFile("Ressources/Sheets/explosion.png"))
	{
		// erreur...
	}
	if (!texture_tower.loadFromFile("Ressources/Sheets/towers.png"))
	{
		// erreur...
	}

	Temp_mouse = new bool(false);
	Temp_tower = new int(0);
	cadence_tir = new float(0);

	tower = new vector<Entite*>;
	avion = new vector<Entite*>;
	avion2 = new vector<Entite*>;
	anime_destruction = new vector<sf::Sprite>;
	
	Paused = new EventController('p', &font, &fond_pause);

	Input = new InputController(&texture_map, &texture_fond_bouton, &texture_bouton, sf::Vector2f(20,888), sf::Vector2f(84,952), sf::Vector2f(148,952),2,5);

	Map_one.load(texture_map, sf::Vector2u(64, 64), level, 30, 17);	

	Life = new Life_Controller(&texture_life);
	Money = new Money_Controller(&texture_map);

	sprite.setTexture(texture_explosion);
	sprite.setTextureRect(sf::IntRect(289, 33, 70, 70));
	sprite.setOrigin(32, 32);
	sprite.setPosition(50,50);
}

void PlayState::draw(const float dt)
{
	game->window.draw(Map_one);
	game->window.draw(Money->sprite_dollar);
	game->window.draw(Money->sprite_deci);
	game->window.draw(Money->sprite_uni);
	game->window.draw(Life->sprite);

	game->window.draw(Input->sprite_fond);
	for (int i = 0; i < Input->getTaille(); i++)
	{
		game->window.draw(Input->sprite[i]);
		game->window.draw(Input->sprite_prix[i]);
	}
	for (int i = 0; i < tower->size(); i++)
	{
		game->window.draw(tower->at(i)->sprite);
	}
	for (int i = 0; i < avion->size(); i++)
	{
		game->window.draw(avion->at(i)->sprite);
	}
	for (int i = 0; i < avion2->size(); i++)
	{
		game->window.draw(avion2->at(i)->sprite);
	}
	for (int i = 0; i < anime_destruction->size(); i++)
	{
		game->window.draw(anime_destruction->at(i));
		time_explosion += dt;
		if (time_explosion > 0.2f) {
			anime_destruction->erase(anime_destruction->begin() + i);
			time_explosion = 0;
		}
	}
	if (Paused->Paused())
	{
		game->window.draw(Paused->back_pause);
		game->window.draw(Paused->text_pause);
	}
	//game->window.draw(sprite);
}

void PlayState::update(const float dt)
{
	if (Paused->Paused())
	{
		clock.restart();
		clock2.restart();
	}
	else
	{

			//EventController::Appariton_Disparition('a', avion, Life, Money, &clock, &texture_map, sf::Vector2f(0, 672), 5.0f, &texture_explosion, anime_destruction);
			EventController::Appariton_Disparition('a', avion2, Life, Money, &clock2, &texture_map,sf::Vector2f(0, 604), 5.0f, &texture_explosion, anime_destruction);
			//EventController::Detection_enemi(avion, tower, &texture_explosion, anime_destruction, cadence_tir);
			EventController::Detection_enemi(avion2, tower, &texture_explosion, anime_destruction, cadence_tir);	
			*cadence_tir += dt;
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
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i localPosition = sf::Mouse::getPosition(game->window);
				std::cout << "x: " << localPosition.x << endl;
				std::cout << "y: " << localPosition.y << endl;
				
				if (*Temp_mouse == true)
				{
					EventController::MouseCreateTower(&texture_tower, localPosition, tower, Temp_mouse, Temp_tower, Money);
				}
				else
				{
					EventController::MouseChoiceTower(localPosition, Input, Temp_mouse, Temp_tower);
				}
			}

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::P)
				Paused->Paused(!Paused->Paused());
			else if (event.key.code == sf::Keyboard::Z && !Paused->Paused())
			{
				Money->increment(1);
			}
			else if (event.key.code == sf::Keyboard::E && !Paused->Paused())
			{
				Money->decrement(1);
			}
			else if (event.key.code == sf::Keyboard::L && !Paused->Paused())
			{
				EventController::Nuclear_Destruction('n', avion, Money, &texture_map, &texture_explosion, anime_destruction);
				EventController::Nuclear_Destruction('n', avion2, Money, &texture_map, &texture_explosion, anime_destruction);
				std::cout << Money->getMoney() << endl;
			}
		}
	}
}



/*
	iif (event.key.code == sf::Keyboard::Right)
			{
				sprite.move(5, 0);

			}
			else if (event.key.code == sf::Keyboard::Up)
			{
				sprite.move(0, -5);
			}
			else if (event.key.code == sf::Keyboard::Left)
			{
				sprite.move(-5, 0);
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
			else if (event.key.code == sf::Keyboard::R)
			{
				sprite.rotate(90);
			}
			break;
		}
*/