#pragma once
#include "Entite_statique.h"
#include"SFML/Graphics.hpp"

class Towers:public Entite_statique
{
private:
	int degat = 1;
	int prix = 1;

	sf::Vector2f position;

public:

	Towers(sf::Texture *texture, sf::IntRect intRect, int prix, int degat, sf::Vector2f position);
	~Towers();
};
