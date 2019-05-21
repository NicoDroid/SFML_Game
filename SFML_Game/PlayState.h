#pragma once
#ifndef GAME_STATE_EDITOR_HPP
#define GAME_STATE_EDITOR_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameState.h"
#include "MapEngineController.h"
#include "Entite.h"
#include "Infanterie.h"
#include "Life_Controller.h"
#include "Money_Controller.h"
#include "EventController.h"
#include "InputController.h"
#include "Towers.h"


class PlayState : public GameState
{
private:

	EventController *Paused;
	MapEngineController Map_one;
	Life_Controller *Life;
	Money_Controller *Money;
	InputController *Input;
	
	bool *Temp_mouse;
	int *Temp_tower;

	sf::Font font;

	sf::Texture texture_tower;

	sf::Texture texture_bouton;
	sf::Texture texture_fond_bouton;

	sf::Texture texture_map;
	sf::Sprite sprite;

	sf::Texture texture_life;
	sf::Texture fond_pause;

	sf::Texture texture_explosion;

	sf::Clock clock;
	sf::Clock clock2;

	std::vector<Entite*> *avion;
	std::vector<Entite*> *avion2;
	std::vector<sf::Sprite> *anime_destruction;
	std::vector<Entite*> *tower;

	float time_explosion = 0;

public:

	PlayState(Game* game);

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
};

#endif /* GAME_STATE_EDITOR_HPP */