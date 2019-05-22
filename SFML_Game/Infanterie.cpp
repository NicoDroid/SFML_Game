#include "Infanterie.h"
#include <iostream>

Infanterie::Infanterie(sf::Vector2f position, sf::Texture *texture, sf::IntRect intRect):Unites(texture,intRect)
{
	this->sprite.setPosition(position);
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
