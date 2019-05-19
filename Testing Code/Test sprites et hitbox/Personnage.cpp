#include "Personnage.h"



Personnage::Personnage(sf::Texture *texture)
{
	sprite.setPosition(50, 50);

	rectSourceSprite.left = 190;
	rectSourceSprite.top = 0;

	rectSourceSprite.height = 190;
	rectSourceSprite.width = 170;

	sprite.setTexture(*texture);
	sprite.setTextureRect(rectSourceSprite);
}


Personnage::~Personnage()
{
}

void Personnage::move()
{
	if (rectSourceSprite.left == 380)
		rectSourceSprite.left = 0;
	else
		rectSourceSprite.left += 190;

	sprite.setTextureRect(rectSourceSprite);
}
