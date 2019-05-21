#include "Towers.h"

Towers::Towers(sf::Texture *texture, sf::IntRect intRect, int prix, int degat, sf::Vector2f position):Entite_statique(texture, intRect)
{
	this->prix = prix;
	this->degat = degat;

	this->sprite.setPosition(position);
}


Towers::~Towers()
{
}


