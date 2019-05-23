#include "SFML/Graphics.hpp"
#include "Game.h"
#include "GameState.h"
#include "FileController.h"
#include <vector>

Game::Game()
{
	std::vector<int>Config = FileController::RecupFileOption();
	int SizeX = Config[2];
	int SizeY = Config[3];

	window.create(sf::VideoMode(SizeX, SizeY), "HEHDefender", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
}

void Game::pushState(GameState* state)
{
	states.push_back(state);
}

void Game::popState()
{
	states.back();
	delete states.back();
	states.pop_back();
}

Game::~Game()
{
	while (!states.empty())
		popState();
}

GameState* Game::CurrentState()
{
	if (states.empty())
		return nullptr;
	else
		return states.back();
}

void Game::gameLoop()
{
	sf::Clock clock;

	while (window.isOpen())
	{
		//control du framerate
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		//exception handling
		if (CurrentState() == nullptr)
			continue;

		//récupérer l'entrée utilisateur pour le GameState actuel
		CurrentState()->handleInput();

		//update si nécessaire
		CurrentState()->update(dt);

		//clear window
		window.clear();

		//dessiner dans le GameState actuel
		CurrentState()->draw(dt);

		window.display();
	}
}