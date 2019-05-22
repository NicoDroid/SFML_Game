#include "Unites.h"

Unites::Unites(sf::Texture *texture, sf::Texture *texture_life, sf::IntRect intRect):Entite_mobile(texture, intRect)
{

}

Unites::~Unites()
{
}

void Unites::deplacement()
{
	if (mouvement == 0) //Arrêt
	{
		sprite_life.move(0, 0);
		sprite.move(0, 0);
	}
	else if (mouvement == 6) //Droite
	{
		sprite_life.move(4, 0);
		sprite.move(4, 0);
	}
	else if (mouvement == 2) //Bas
	{
		sprite_life.move(0, 4);
		sprite.move(0, 4);
	}
	else if (mouvement == 4) //Gauche
	{
		sprite_life.move(-4, 0);
		sprite.move(-4, 0);
	}
	else if (mouvement == 8) //Haut
	{
		sprite_life.move(0, -4);
		sprite.move(0, -4);
	}	
}

void Unites::setMouvement(int v_mouvement)
{
	this->mouvement = v_mouvement;
}

int Unites::getMouvement()
{
	return this->mouvement;
}

int Unites::getLife()
{
	return this->life;
}

void Unites::decrementLifeEntite(int v_life)
{
	sf::IntRect rec(105, 42 + (5 * (150 + 32)), 630, 150);

	this->life-=v_life;

	switch (this->getLife())
	{

	case 1:
		rec.top = 42 + (0 * (150 + 32));
		break;
	case 2:
		rec.top = 42 + (1 * (150 + 32));
		break;
	case 3:
		rec.top = 42 + (2 * (150 + 32));
		break;
	case 4:
		rec.top = 42 + (3 * (150 + 32));
		break;
	case 5:
		rec.top = 42 + (4 * (150 + 32));
		break;
	case 6:
		rec.top = 42 + (5 * (150 + 32));
		break;
	default:
		break;
	}
	this->sprite_life.setTextureRect(rec);
}