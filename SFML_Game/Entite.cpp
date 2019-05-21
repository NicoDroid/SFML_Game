#include "Entite.h"
#include <iostream>

Entite::Entite(sf::Texture *texture, sf::IntRect intRect)
{
	this->sprite.setTexture(*texture);
	this->sprite.setTextureRect(intRect);
	this->sprite.setOrigin(32, 32);
}

Entite::~Entite()
{
}

sf::Vector2f Entite::getPosition()
{
	sf::Vector2f position;

	position.x = sprite.getPosition().x;
	position.y = sprite.getPosition().y;

	return position;
}

void Entite::setPosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}