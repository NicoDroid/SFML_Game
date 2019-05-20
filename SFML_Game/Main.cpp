#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "game.h"
#include "MenuState.h"
#include "SoundController.h"
#include "FileController.h"


int main()
{
	Game game;

	SoundController soundfond("speck.ogg", true);
	soundfond.SetVolume(FileController::RecupFileOption()[0]);
	soundfond.Play();

	game.pushState(new MenuState(&game, &soundfond));

	game.gameLoop();

	return 0;
}





/*
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(shape);
		window.display();

	}*/