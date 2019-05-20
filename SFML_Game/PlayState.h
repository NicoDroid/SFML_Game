#pragma once
#ifndef GAME_STATE_EDITOR_HPP
#define GAME_STATE_EDITOR_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "GameState.h"
#include "MapEngineController.h"
#include "Entite.h"
#include "Infanterie.h"


class PlayState : public GameState
{
private:
	void PauseGame();

	int test = 0;

	MapEngineController map_one;
	sf::Texture texture_map;
	sf::Clock clock;

	std::vector<Entite*> *avion;

public:

	PlayState(Game* game);

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
};

#endif /* GAME_STATE_EDITOR_HPP */