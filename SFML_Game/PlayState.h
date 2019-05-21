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


class PlayState : public GameState
{
private:
	void PauseGame();

	EventController *Paused;
	MapEngineController map_one;
	Life_Controller *life;
	Money_Controller *money;
	
	sf::Font font;

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

	float time_explosion = 0;

public:

	PlayState(Game* game);

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
};

#endif /* GAME_STATE_EDITOR_HPP */