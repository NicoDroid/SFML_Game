#pragma once
#include "SFML/Graphics.hpp"

class Life_Controller
{
private:
	int life_point = 12;
	sf::IntRect rec;
public:
	sf::Sprite sprite;

	Life_Controller(sf::Texture *texture);
	~Life_Controller();

	void decrementLife();
	int getLife();
	void setFullLife();
};

