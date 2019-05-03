#pragma once
#pragma once
#ifndef GAME_STATE_START_HPP
#define GAME_STATE_START_HPP
#define MAX_NUMBER_OF_ITEMS_MENU 3

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "SoundController.h"

class MenuState :public GameState
{
private:

	void loadgame();
	void loadoptions();

	int selectedItemIndex;
	sf::Font font;
	sf::Text text[MAX_NUMBER_OF_ITEMS_MENU];

	SoundController *m_sound;

public:
	MenuState(Game* game, SoundController* soundfond);
	~MenuState();

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

	void MoveUp();
	void MoveDown();
};


#endif /* GAME_STATE_START_HPP */