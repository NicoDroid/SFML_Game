#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "SFML/Graphics.hpp"

class GameState;

class Game
{
private:
	std::vector<GameState*> states;

public:
	//constructeur et destructeur
	Game();
	~Game();

	//fonctions pour changer le GameState
	void pushState(GameState* state);
	void popState();

	//fonction pour récupérer le State actuel
	GameState* CurrentState();

	//fonction boucle Game
	void gameLoop();

	//sfml window
	sf::RenderWindow window;
};

#endif /* Game_HPP */