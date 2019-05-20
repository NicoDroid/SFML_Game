#pragma once
#ifndef GAME_STATE_EDITOR_HPP
#define GAME_STATE_EDITOR_HPP

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "MapEngineController.h"
#include "Entite.h"
#include "Infanterie.h"
#include <vector>

class PlayState : public GameState
{
private:
	void PauseGame();

	MapEngineController map_one;
	sf::Texture texture_map;
	std::vector<Entite*> *avion;
	Entite *test;
	//Entite *avion;
	sf::Clock clock;

public:

	PlayState(Game* game);

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
};

#endif /* GAME_STATE_EDITOR_HPP */