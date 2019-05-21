#pragma once
#include "Entite.h"
class Entite_mobile:public Entite
{
protected:
	int vitesse = 1;

public:
	Entite_mobile(sf::Texture *texture, sf::IntRect intRect);
	~Entite_mobile();
};

