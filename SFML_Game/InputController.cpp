#include "InputController.h"


InputController::InputController(sf::Texture *texture, sf::Vector2f position_A, sf::Vector2f position_B)
{
	sf::Sprite spriteNuclear;
	//spriteNuclear.setTexture(*texture);
	spriteNuclear.setTextureRect(sf::IntRect(0, 0, 64, 64));
	spriteNuclear.setPosition(position_A);
	this->sprite.push_back(spriteNuclear);

	sf::Sprite spriteLife;
	//spriteLife.setTexture(*texture);
	spriteLife.setTextureRect(sf::IntRect(0, 0, 64, 64));
	spriteLife.setPosition(position_B);
	this->sprite.push_back(spriteLife);
}

InputController::InputController(sf::Texture *texture_map, sf::Texture *texture_fond, sf::Texture *texture, sf::Vector2f position_fond, sf::Vector2f position_A, sf::Vector2f position_B, int prix_A, int prix_B)
{
	sf::IntRect rect_fond(0, 0, 256, 192);
	this->sprite_fond.setTexture(*texture_fond);
	this->sprite_fond.setTextureRect(rect_fond);
	this->sprite_fond.setPosition(position_fond);

	sf::Sprite spriteA(*texture, sf::IntRect(0, 0, 64, 64));
	spriteA.setPosition(position_A);

	sf::Sprite spriteB(*texture, sf::IntRect(64, 0, 64, 64));
	spriteB.setPosition(position_B);

	this->sprite.push_back(spriteA);
	this->sprite.push_back(spriteB);

	this->prix.push_back(prix_A);
	this->prix.push_back(prix_B);

	sf::Sprite spritePrixA(*texture_map, sf::IntRect(InputController::gestionAffiche(prix_A), 770, 64, 64));
	spritePrixA.setPosition(position_A.x,position_A.y+64);

	sf::Sprite spritePrixB(*texture_map, sf::IntRect(InputController::gestionAffiche(prix_B), 770, 64, 64));
	spritePrixB.setPosition(position_B.x, position_B.y + 64);

	this->sprite_prix.push_back(spritePrixA);
	this->sprite_prix.push_back(spritePrixB);
}


InputController::~InputController()
{
}

int InputController::getTaille()
{
	return sprite.size();
}

std::vector<int> InputController::getPrix()
{
	return this->prix;
}

int InputController::gestionAffiche(int prix)
{
	switch (prix)
	{
	case 0:
		return 0;
		break;
	case 1:
		return 64;
		break;
	case 2:
		return 128;
		break;
	case 3:
		return 192;
		break;
	case 4:
		return 256;
		break;
	case 5:
		return 320;
		break;
	case 6:
		return 384;
		break;
	case 7:
		return 448;
		break;
	case 8:
		return 512;
		break;
	case 9:
		return 576;
		break;
	default:
		return 0;
		break;
	}
}