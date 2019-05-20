#pragma once
#include "Unites.h"
class Infanterie:public Unites
{
protected:
public:
	Infanterie(sf::Texture *texture, sf::IntRect intRect);
	~Infanterie();

	void rotation(int v_rotation);
};

