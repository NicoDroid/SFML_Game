#pragma once
#include "Entite.h"

class Entite_statique:public Entite
{
public:
	Entite_statique(sf::Texture *texture, sf::IntRect intRect);
	~Entite_statique();
};

