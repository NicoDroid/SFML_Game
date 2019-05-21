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
	else if (this->getPosition().x == 1630 && this->getPosition().y == 912) //1012
	{
		this->setMouvement(-1);
		std::cout << "Game Over" << std::endl;
	}


	//Vague 2
	if (this->getPosition().x == 0 && this->getPosition().y == 606)
	{
		this->setMouvement(6);
	}
	else if (this->getPosition().x == 605 && this->getPosition().y == 606)
	{
		this->rotation(-90);
		this->setMouvement(8);

	}
	else if (this->getPosition().x == 605 && this->getPosition().y == 221)
	{
		this->rotation(90);
		this->setMouvement(6);
	}
	else if (this->getPosition().x == 930 && this->getPosition().y == 221)
	{
		this->rotation(90);
		this->setMouvement(2);
	}
	else if (this->getPosition().x == 930 && this->getPosition().y == 606)
	{
		this->rotation(-90);
		this->setMouvement(6);
	}
	else if (this->getPosition().x == 1700 && this->getPosition().y == 606)
	{
		this->rotation(90);
		this->setMouvement(2);
	}
	else if (this->getPosition().x == 1700 && this->getPosition().y == 1106)
	{
		this->setMouvement(-1);
		std::cout << "Game Over" << std::endl;
	}
}
