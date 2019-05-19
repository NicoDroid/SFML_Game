#pragma once
#include"SFML/Graphics.hpp"

class Personnage
{
private:
	sf::IntRect rectSourceSprite;

public:
	sf::Sprite sprite;

	Personnage(sf::Texture *texture);
	~Personnage();

	void move();

};

