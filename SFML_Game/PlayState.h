#pragma once
#ifndef GAME_STATE_EDITOR_HPP
#define GAME_STATE_EDITOR_HPP

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "MapEngineController.h"


class PlayState : public GameState
{
private:
	void PauseGame();
	sf::Sprite sprite;
	// on crée la tilemap avec le niveau précédemment défini
	MapEngineController map;
	sf::Texture texture;
	int status = 0;
public:

	PlayState(Game* game);

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();
};

#endif /* GAME_STATE_EDITOR_HPP */