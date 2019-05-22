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

void Towers::setRotate(int rotate)
{
	switch (rotate)
	{
	case 0:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(0);
		this->rotate = 0;
		break;
	case 1:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(22.5);
		this->rotate =22.5;
		break;
	case 2:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(67.5);
		this->rotate = 67.5;
		break;
	case 3:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(90);
		this->rotate = 90;
		break;
	case 4:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(112.5);
		this->rotate = 112.5;
		break;
	case 5:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(157.5);
		this->rotate = 157.5;
		break;
	case 6:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(180);
		this->rotate = 180;
		break;
	case 7:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(202.5);
		this->rotate = 202.5;
		break;
	case 8:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(247.5);
		this->rotate = 247.5;
		break;
	case 9:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(270);
		this->rotate = 270;
		break;
	case 10:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(292.5);
		this->rotate = 292.5;
		break;
	case 11:
		this->sprite.rotate(-this->rotate);
		this->sprite.rotate(337.5);
		this->rotate = 337.5;
		break;
	default:
		break;
	}
}