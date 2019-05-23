#include "Towers.h"

Towers::Towers(sf::Texture *texture, sf::Texture *texturefeu, int feu, sf::IntRect intRect, int prix, int degat, sf::Vector2f position):Entite_statique(texture, intRect)
{
	this->prix = prix;
	this->degat = degat;
	this->feu = feu;

	this->sprite.setPosition(position.x, position.y);

	this->position.x = position.x;
	this->position.y = position.y;

	/*
	this->sprite.setPosition(position.x, position.y);
	this->position.x = position.x;
	this->position.y = position.y;
	*/

	this->sprite_fire.setTexture(*texturefeu);

	this->sprite_fire.setTextureRect(sf::IntRect(this->feu * 64, 770, 64, 64));

	this->sprite_fire.setOrigin(32, 32);

	this->sprite_fire.setPosition(position.x, position.y - ((5*(this->feu %19))+45));
	this->sprite_fire.setColor(sf::Color(25, 255, 255, 0));
}

Towers::~Towers()
{
}

int Towers::getDegat()
{
	return this->degat;
}

void Towers::setCadence(bool cadence)
{
	this->cadence_tir = cadence;
}

bool Towers::getCadence()
{
	return this->cadence_tir;
}

float Towers::getTimeCadence()
{
	return this->time_cadence_tir;
}

void Towers::setTimeCadence(float A, float B)
{
	this->time_cadence_tir = A + B;
}

void Towers::setTimeFire(float A, float B) 
{
	this->time_fire = A + B;
}

float Towers::getTimeFire()
{
	return this->time_fire;
}

void Towers::setFire(bool fire)
{
	if (fire)
	{
		this->sprite_fire.setColor(sf::Color(255, 255, 255, 255));
	}
	else
	{
		this->sprite_fire.setColor(sf::Color(255, 255, 255, 0));
	}
}


void Towers::setRotate(int rotate)
{
	switch (rotate)
	{
	case 0:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(0);

		this->sprite_fire.rotate(-this->rotate);
		this->sprite_fire.rotate(0);
		this->sprite_fire.setPosition(this->position.x, this->position.y - ((5 * (this->feu % 19)) + 45));

		this->rotate = 0;
		break;
	case 1:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(22.5);

		this->sprite_fire.rotate(-this->rotate);
		this->sprite_fire.rotate(22.5);
		this->sprite_fire.setPosition(this->position.x + 20, this->position.y - ((5 * (this->feu % 19)) + 45));

		this->rotate =22.5;
		break;
	case 2:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(67.5);

		this->sprite_fire.rotate(-this->rotate);
		this->sprite_fire.rotate(67.5);
		this->sprite_fire.setPosition(this->position.x+42.5, this->position.y - ((5 * (this->feu % 19)) + 45)+28.5);

		this->rotate = 67.5;
		break;
	case 3:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(90);

		this->sprite_fire.rotate(-this->rotate);
		this->sprite_fire.rotate(90);
		this->sprite_fire.setPosition(this->position.x + 45, this->position.y - ((5 * (this->feu % 19)) + 45) + 45);

		this->rotate = 90;
		break;
	case 4:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(112.5);

		this->sprite_fire.rotate(-this->rotate);
		this->sprite_fire.rotate(112.5);
		this->sprite_fire.setPosition(this->position.x+45, this->position.y - ((5 * (this->feu % 19)) + 45)+62.5);

		this->rotate = 112.5;
		break;
	case 5:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(157.5);

		this->sprite_fire.rotate(-this->rotate);
		this->sprite_fire.rotate(157.5);
		this->sprite_fire.setPosition(this->position.x+20, this->position.y - ((5 * (this->feu % 19)) -46));

		this->rotate = 157.5;
		break;
	case 6:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(180);

		this->sprite_fire.rotate(-this->rotate);
		this->sprite_fire.rotate(180);
		this->sprite_fire.setPosition(this->position.x, this->position.y - ((5 * (this->feu % 19)) -46));

		this->rotate = 180;
		break;
	case 7:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(202.5);

		this->sprite_fire.rotate(-this->rotate);
		this->sprite_fire.rotate(202.5);
		this->sprite_fire.setPosition(this->position.x-18, this->position.y - ((5 * (this->feu % 19)) - 46));

		this->rotate = 202.5;
		break;
	case 8:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(247.5);

		this->sprite_fire.rotate(-this->rotate);
		this->sprite_fire.rotate(247.5);
		this->sprite_fire.setPosition(this->position.x-40, this->position.y - ((5 * (this->feu % 19)) + 45)+62.5);

		this->rotate = 247.5;
		break;
	case 9:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(270);

		this->sprite_fire.rotate(-this->rotate);
		this->sprite_fire.rotate(270);
		this->sprite_fire.setPosition(this->position.x - 45, this->position.y - ((5 * (this->feu % 19)) + 45) + 45);

		this->rotate = 270;
		break;
	case 10:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(292.5);

		this->sprite_fire.rotate(-this->rotate);
		this->sprite_fire.rotate(292.5);
		this->sprite_fire.setPosition(this->position.x-40, this->position.y - ((5 * (this->feu % 19)) + 20));

		this->rotate = 292.5;
		break;
	case 11:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(337.5);

		this->sprite_fire.rotate(-this->rotate);
		this->sprite_fire.rotate(337.5);
		this->sprite_fire.setPosition(this->position.x - 20, this->position.y - ((5 * (this->feu % 19)) + 45));

		this->rotate = 337.5;
		break;
	default:
		break;
	}
}