#include "Infanterie.h"

Infanterie::Infanterie(sf::Texture *texture, sf::IntRect intRect):Unites(texture,intRect)
{
}


Infanterie::~Infanterie()
{
}

void Infanterie::rotation(int v_rotation)
{
	sprite.rotate(v_rotation);
}
