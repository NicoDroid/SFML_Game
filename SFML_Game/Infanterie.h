#pragma once
#include "Unites.h"
class Infanterie:public Unites
{
protected:
public:
	Infanterie(sf::Vector2f position, sf::Texture *texture, sf::IntRect intRect);
	~Infanterie();

	void rotation(int v_rotation);

	void road();
};

