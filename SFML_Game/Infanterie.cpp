#include "Infanterie.h"
#include <iostream>

Infanterie::Infanterie(sf::Texture *texture, sf::IntRect intRect):Unites(texture,intRect)
{
	this->sprite.setPosition(sf::Vector2f(0, 672));
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
	if (this->getPosition().x == 0 && this->getPosition().y == 672)
	{
		this->setMouvement(6);
	}
	else if (this->getPosition().x == 670 && this->getPosition().y == 672)
	{
		this->rotation(-90);
		this->setMouvement(8);

	}
	else if (this->getPosition().x == 670 && this->getPosition().y == 287)
	{
		this->rotation(90);
		this->setMouvement(6);
	}
	else if (this->getPosition().x == 865 && this->getPosition().y == 287)
	{
		this->rotation(90);
		this->setMouvement(2);
	}
	else if (this->getPosition().x == 865 && this->getPosition().y == 672)
	{
		this->rotation(-90);
		this->setMouvement(6);
	}
	else if (this->getPosition().x == 1630 && this->getPosition().y == 672)
	{
		this->rotation(90);
		this->setMouvement(2);
	}
	else if (this->getPosition().x == 1630 && this->getPosition().y == 1017)
	{
		this->setMouvement(-1);
		std::cout << "Game Over" << std::endl;
	}
}
