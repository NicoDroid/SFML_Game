#pragma once
#ifndef OPTION_STATE_START_HPP
#define OPTION_STATE_START_HPP
#define MAX_NUMBER_OF_ITEMS_OPTION 7

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "SoundController.h"
#include <string>

class OptionState :public GameState
{
private:
	void MoveUp();
	void MoveDown();

	void loadmenu();

	void upValeur();
	void downValeur();

	sf::View view;

	sf::Texture texture;
	sf::Sprite sprite;

	sf::Font font;
	sf::Text text[MAX_NUMBER_OF_ITEMS_OPTION];
	int selectedItemIndex = 0;

	int m_VolumeMenu;
	int m_VolumeGame;
	
	int scaleX;
	int scaleY;

	string resolution;

	SoundController *m_sound;
	SoundController *m_sound2;

public:
	OptionState(Game* game, SoundController* soundfond, SoundController* soundfond2);
	~OptionState();

	virtual void draw(const float dt);
	virtual void update(const float dt);
	virtual void handleInput();

};

#endif /* OPTION_STATE_START_HPP */
