#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#include "FileController.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	sf::Font font;
	sf::Text text;
	int i=0;
	if (!font.loadFromFile("arial.ttf"))
		cout << "Erreur Fonts" << endl;

	text.setFont(font);
	text.setString(to_string(i));
	text.setCharacterSize(18);
	text.setFillColor(sf::Color::Red);

	FileOptionController::SetVolumeMenu();
	FileOptionController::SetVolumeGame();

	FileOptionController::RecupOptions();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Right)
					text.setString(to_string(i += 10));
				if (event.key.code == sf::Keyboard::Left)
					text.setString(to_string(i -= 10));
			}
				
		}
		window.clear();
		window.draw(text);
		window.display();
	}
	return 0;
}