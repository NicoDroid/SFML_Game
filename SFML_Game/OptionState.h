#pragma once
#ifndef OPTION_STATE_START_HPP
#define OPTION_STATE_START_HPP

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "SoundController.h"

class OptionState :public GameState
{
private:
	void loadmenu();

	sf::Font font;
	sf::Text text;

	SoundController *m_sound;

public:
	OptionState(Game* game, SoundController* soundfond);
	~OptionState();

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

};

#endif /* OPTION_STATE_START_HPP */
