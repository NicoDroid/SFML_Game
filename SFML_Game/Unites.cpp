#include "Unites.h"

Unites::Unites(sf::Texture *texture, sf::IntRect intRect):Entite_mobile(texture, intRect)
{

}


Unites::~Unites()
{
}

void Unites::deplacement()
{
	if (mouvement == 0) //Arrêt
	{
		sprite.move(0, 0);
	}
	else if (mouvement == 6) //Droite
	{
		sprite.move(5, 0);
	}
	else if (mouvement == 2) //Bas
	{
		sprite.move(0, 5);
	}
	else if (mouvement == 4) //Gauche
	{
		sprite.move(-5, 0);
	}
	else if (mouvement == 8) //Haut
	{
		sprite.move(0, -5);
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
	this->life-=v_life;
}