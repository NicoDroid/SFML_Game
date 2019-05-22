#include "Infanterie.h"
#include <iostream>

Infanterie::Infanterie(sf::Vector2f position, sf::Texture *texture, sf::Texture *texture_life, sf::IntRect intRect):Unites(texture, texture_life, intRect)
{
	this->sprite.setPosition(position);
	this->sprite_life.setTexture(*texture_life);

	sprite_life.setTextureRect(sf::IntRect(105, 42+(5*(150+32)), 630, 150));
	sprite_life.setOrigin(32, 32);
	sprite_life.scale(0.05, 0.05);
	sprite_life.setPosition(position.x, position.y - 10);
}

Infanterie::~Infanterie()
{
}

void Infanterie::rotation(int v_rotation)
{
	sprite.rotate(v_rotation);
}

void Infanterie::road()
{
	this->deplacement();
	//Vague1
	if (this->getPosition().x == 0 && this->getPosition().y == 672)
	{
		this->setMouvement(6);
	}
	else if (this->getPosition().x == 668 && this->getPosition().y == 672)
	{
		this->rotation(-90);
		this->setMouvement(8);

	}
	else if (this->getPosition().x == 668 && this->getPosition().y == 284)
	{
		this->rotation(90);
		this->setMouvement(6);
	}
	else if (this->getPosition().x == 864 && this->getPosition().y == 284)
	{
		this->rotation(90);
		this->setMouvement(2);
	}
	else if (this->getPosition().x == 864 && this->getPosition().y == 672)
	{
		this->rotation(-90);
		this->setMouvement(6);
	}
	else if (this->getPosition().x == 1628 && this->getPosition().y == 672)
	{
		this->rotation(90);
		this->setMouvement(2);
	}
	else if (this->getPosition().x == 1628 && this->getPosition().y == 1016)
	{
		this->setMouvement(-1);
		std::cout << "Game Over" << std::endl;
	}


	//Vague 2
	if (this->getPosition().x == 0 && this->getPosition().y == 604)
	{
		this->setMouvement(6);
	}
	else if (this->getPosition().x == 604 && this->getPosition().y == 604)
	{
		this->rotation(-90);
		this->setMouvement(8);

	}
	else if (this->getPosition().x == 604 && this->getPosition().y == 220)
	{
		this->rotation(90);
		this->setMouvement(6);
	}
	else if (this->getPosition().x == 928 && this->getPosition().y == 220)
	{
		this->rotation(90);
		this->setMouvement(2);
	}
	else if (this->getPosition().x == 928 && this->getPosition().y == 604)
	{
		this->rotation(-90);
		this->setMouvement(6);
	}
	else if (this->getPosition().x == 1696 && this->getPosition().y == 604)
	{
		this->rotation(90);
		this->setMouvement(2);
	}
	else if (this->getPosition().x == 1696 && this->getPosition().y == 1016)
	{
		this->setMouvement(-1);
		std::cout << "Game Over" << std::endl;
	}
}
