#include <SFML/Graphics.hpp>
using namespace std;
#include <iostream>
#include"Personnage.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 640), "SFML works!");

	sf::Event event;

	sf::Texture *texture=new sf::Texture;
	texture->loadFromFile("image.png");

	Personnage personnage(texture);

	sf::Clock clock;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				window.close();
		}

		
		if (clock.getElapsedTime().asSeconds() > 1.0f) {
			personnage.move();
			clock.restart();
		}

		window.clear();
		window.draw(personnage.sprite);
		window.display();
	}

	delete texture;
	return 0;
}