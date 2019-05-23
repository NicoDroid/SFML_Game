#include <SFML/Graphics.hpp>

#include <iostream>

#include "PlayState.h"
#include "MenuState.h"
#include "GameState.h"
#include "FileController.h"

const int level[] =
{
	/*24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,
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
24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,232,178,178,230,24,24*/

24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,
24,114,24,24,24,114,24,133,86,86,86,86,86,86,86,86,133,24,157,157,114,114,114,114,24,24,24,24,24,24,
24,114,114,24,24,114,24,86,210,254,254,254,254,254,254,211,86,157,157,114,157,157,157,157,157,157,157,157,157,24,
24,114,24,114,24,114,24,86,232,84,84,224,224,84,84,230,86,157,157,114,157,157,157,114,114,157,157,157,157,24,
24,114,24,24,114,114,24,86,232,84,84,224,224,84,84,230,86,157,157,114,157,157,157,157,114,157,157,157,157,24,
24,114,24,24,24,114,24,86,232,178,178,207,209,178,178,230,86,24,157,157,114,114,114,114,114,157,157,157,157,24,
24,24,24,24,24,24,24,86,232,178,178,230,232,178,178,230,86,24,24,24,24,24,24,24,24,24,24,24,24,24,
24,24,297,86,86,86,86,86,232,178,178,230,232,178,178,230,86,86,86,86,86,86,86,86,86,86,86,86,130,24,
254,254,254,254,254,254,254,254,255,178,178,230,232,178,178,253,254,254,254,254,254,254,254,254,254,254,254,211,86,24,
224,224,224,224,224,224,224,224,224,84,84,230,232,84,84,224,224,224,224,224,224,224,224,224,224,84,84,230,86,24,
224,224,224,224,224,224,224,224,224,84,84,230,232,84,84,224,224,224,224,224,224,224,224,224,224,84,84,230,86,24,
208,208,208,208,208,208,208,208,208,208,208,234,233,208,208,208,208,208,208,208,208,208,208,208,209,178,178,230,86,24,
24,24,297,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,86,232,178,178,230,86,24,
24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,86,232,178,178,230,86,24,
24,24,24,24,24,24,24,245,136,24,24,24,24,24,24,24,24,24,136,245,24,24,24,86,232,178,178,230,86,24,
24,24,24,24,24,24,24,24,24,24,24,24,245,137,24,24,24,24,24,24,24,137,24,297,232,178,178,230,297,24,
24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,245,24,24,232,178,178,230,24,24
};


PlayState::PlayState(Game* game, SoundController *soundfond, SoundController *soundfond2)
{
	this->game = game;
	game->window.setMouseCursorVisible(true);

	m_sound = soundfond;
	m_sound->Stop();

	m_sound2 = soundfond2;
	m_sound2->Play();

	soundNuclear = new SoundController("nuclear.ogg",false);
	soundHeal = new SoundController("heal.ogg", false);

	view.reset(sf::FloatRect(0, 0, 1920, 1080));
	game->window.setView(view);

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
	if (!texture_map_fond.loadFromFile("Ressources/Tiled/maps_fond.png"))
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
	if (!texture_life_enemy.loadFromFile("Ressources/Sheets/life_enemis.png"))
	{
		// erreur...
	}

	Temp_mouse = new bool(false);
	Temp_tower = new int(0);

	tower = new vector<Entite*>;
	avion = new vector<Entite*>;
	avion2 = new vector<Entite*>;
	anime_destruction = new vector<sf::Sprite>;
	
	Control = new EventController('p', &font, &fond_pause);

	Input = new InputController(&texture_map, &texture_fond_bouton, &texture_bouton, sf::Vector2f(20,888), sf::Vector2f(84,952), sf::Vector2f(148,952),2,5);
	Input2 = new InputController(&texture_map, sf::Vector2f(192, 192), sf::Vector2f(1408, 192));

	sprite_map_fond.setTexture(texture_map_fond);
	Map_one.load(texture_map, sf::Vector2u(64, 64), level, 30, 17);	

	Life = new Life_Controller(&texture_life);
	Money = new Money_Controller(&texture_map);

	sprite.setTexture(texture_map);
	sprite.setTextureRect(sf::IntRect(19*64, 770, 64, 64)); //20
	sprite.setOrigin(32, 32);
	sprite.setPosition(50,50);
	//sprite.scale(0.05, 0.05);
}

void PlayState::draw(const float dt)
{
	game->window.draw(sprite_map_fond);
	game->window.draw(Map_one);
	game->window.draw(Money->sprite_dollar);
	game->window.draw(Money->sprite_centi);
	game->window.draw(Money->sprite_deci);
	game->window.draw(Money->sprite_uni);
	game->window.draw(Life->sprite);

	game->window.draw(Input->sprite_fond);
	for (int i = 0; i < Input->getTaille(); i++)
	{
		game->window.draw(Input->sprite[i]);
		game->window.draw(Input->sprite_prix[i]);
	}
	for (int i = 0; i < Input2->getTaille(); i++)
	{
		game->window.draw(Input2->sprite[i]);
	}
	for (int i = 0; i < tower->size(); i++)
	{
		game->window.draw(tower->at(i)->sprite);
		game->window.draw(tower->at(i)->sprite_fire);
	}
	for (int i = 0; i < avion->size(); i++)
	{
		game->window.draw(avion->at(i)->sprite);
		game->window.draw(avion->at(i)->sprite_life);
	}
	for (int i = 0; i < avion2->size(); i++)
	{
		game->window.draw(avion2->at(i)->sprite);
		game->window.draw(avion2->at(i)->sprite_life);
	}
	for (int i = 0; i < anime_destruction->size(); i++)
	{
		game->window.draw(anime_destruction->at(i));
		time_explosion += dt;
		if (time_explosion > 0.2f) {
			anime_destruction->erase(anime_destruction->begin() + i);
			cptDead++;
			time_explosion = 0;
		}
	}
	if (Control->Paused())
	{
		game->window.draw(Control->back__pause_gameover);
		game->window.draw(Control->text_pause);
	}
	if (Control->GameOver(cptDead))
	{
		game->window.draw(Control->back__pause_gameover);
		game->window.draw(Control->text_game_over);
		game->window.draw(Control->text_cptDead);
	}
	std::cout << "Mort: " << cptDead << endl;
	//game->window.draw(sprite);
}

void PlayState::update(const float dt)
{
	if (Control->Paused() || Control->GameOver(cptDead))
	{
		clock.restart();
		clock2.restart();
	}
	else if (Life->getLife()==0)
	{
		Control->GameOver(true);
	}else
	{
		clock3_temp += dt;
		
		//std::cout << "Time: " << clock3_temp << std::endl;
		EventController::Appariton_Disparition('a', avion, Life, Money, &clock, &texture_map, &texture_life_enemy, sf::Vector2f(0, 672), DifficultyController::setDifficulty(clock3_temp), &texture_explosion, anime_destruction);
		EventController::Appariton_Disparition('a', avion2, Life, Money, &clock2, &texture_map, &texture_life_enemy, sf::Vector2f(0, 604), DifficultyController::setDifficulty(clock3_temp)+0.25f, &texture_explosion, anime_destruction);
		EventController::Detection_enemi(avion, tower, &texture_explosion, anime_destruction, dt);
		EventController::Detection_enemi(avion2, tower, &texture_explosion, anime_destruction, dt);
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
			if (event.mouseButton.button == sf::Mouse::Left && !Control->Paused() && !Control->GameOver(cptDead))
			{
				sf::Vector2i localPosition = sf::Mouse::getPosition(game->window);
				std::cout << "x: " << localPosition.x << endl;
				std::cout << "y: " << localPosition.y << endl;
				
				EventController::Power(localPosition, Input2, game, 'n', avion, avion2, Money, Life, &texture_map, &texture_explosion, anime_destruction, soundNuclear, soundHeal);

				if (*Temp_mouse == true)
				{
					EventController::MouseCreateTower(&texture_tower, &texture_map, localPosition, tower, Temp_mouse, Temp_tower, Money, game);
				}
				else
				{
					EventController::MouseChoiceTower(localPosition, Input, Temp_mouse, Temp_tower, game);
				}
			}
			if (event.mouseButton.button == sf::Mouse::Right && !Control->Paused() && !Control->GameOver(cptDead))
			{
				sf::Vector2i localPosition = sf::Mouse::getPosition(game->window);
				std::cout << "x: " << localPosition.x << endl;
				std::cout << "y: " << localPosition.y << endl;

				EventController::MouseDestroyTower(localPosition, tower, game);
			}

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::P && !Control->GameOver(cptDead))
			{
				Control->Paused(!Control->Paused());			
			}
			else if (event.key.code == sf::Keyboard::M && !Control->Paused() && !Control->GameOver(cptDead))
			{
				Money->increment(5);
			}
			else if (event.key.code == sf::Keyboard::Escape)
			{
				game->pushState(new MenuState(game, m_sound, m_sound2));
			}
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