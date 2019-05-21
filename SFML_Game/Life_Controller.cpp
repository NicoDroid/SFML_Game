#include "Life_Controller.h"

Life_Controller::Life_Controller(sf::Texture *texture)
{
	this->sprite.setTexture(*texture);

	rec.left = 0;
	rec.top = 0;
	rec.width = 480;
	rec.height = 480;

	this->sprite.setTextureRect(rec);

	this->sprite.setPosition(sf::Vector2f(1400, -150));
}


Life_Controller::~Life_Controller()
{
}

void Life_Controller::decrementLife()
{
	if (life_point != 0)
	{
		life_point--;

		if (rec.left != 1440 && rec.top == 0) //Ligne 1
		{
			rec.left += 480;
		}
		else if (rec.left == 1440 && rec.top == 0)
		{
			rec.left = 0;
			rec.top = 480;
		}
		else if (rec.left != 1440 && rec.top == 480) //Ligne 2
		{
			rec.left += 480;
		}
		else if (rec.left == 1440 && rec.top == 480)
		{
			rec.left = 0;
			rec.top = 960;
		}
		else if (rec.left != 1440 && rec.top == 960) //Ligne 3
		{
			rec.left += 480;
		}
		else if (rec.left == 1440 && rec.top == 960)
		{
			rec.left = 0;
			rec.top = 1440;
		}
		this->sprite.setTextureRect(rec);
	}
}

int Life_Controller::getLife()
{
	return life_point;
}