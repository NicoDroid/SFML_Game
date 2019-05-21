#include "Money_Controller.h"



Money_Controller::Money_Controller(sf::Texture *texture)
{
		//Signe dollar
		sprite_dollar.setTexture(*texture);

		rec_dollar.left = 704;
		rec_dollar.top = 770;
		rec_dollar.width = 64;
		rec_dollar.height = 64;

		sprite_dollar.setTextureRect(rec_dollar);
		sprite_dollar.setPosition(sf::Vector2f(10, 10));

		//Signe decimal
		sprite_deci.setTexture(*texture);

		rec_deci.left = 0;
		rec_deci.top = 770;
		rec_deci.width = 64;
		rec_deci.height = 64;

		sprite_deci.setTextureRect(rec_deci);
		sprite_deci.setPosition(sf::Vector2f(50, 10));

		//Signe unitaire
		sprite_uni.setTexture(*texture);

		rec_uni.left = 64;
		rec_uni.top = 770;
		rec_uni.width = 64;
		rec_uni.height = 64;

		sprite_uni.setTextureRect(rec_uni);
		sprite_uni.setPosition(sf::Vector2f(75, 10));

		int money_deci = money / 10;
		int money_uni = money % 10;

		gestion_affiche(money_deci, money_uni);
}

Money_Controller::~Money_Controller()
{
}

void Money_Controller::increment(int valeur)
{
	if (money <99)
	{
		money+=valeur;

		int money_deci = money / 10;
		int money_uni = money % 10;

		gestion_affiche(money_deci, money_uni);
	}
}

void Money_Controller::decrement(int valeur)
{
	if (money >0)
	{
		money-=valeur;

		int money_deci = money / 10;
		int money_uni = money % 10;

		gestion_affiche(money_deci, money_uni);
	}
}

int Money_Controller::getMoney()
{
	return money;
}

void Money_Controller::gestion_affiche(int money_deci, int money_uni)
{
	switch (money_deci)
	{
	case 0:
		rec_deci.left = 0;
		sprite_deci.setTextureRect(rec_deci);
		break;
	case 1:
		rec_deci.left = 64;
		sprite_deci.setTextureRect(rec_deci);
		break;
	case 2:
		rec_deci.left = 128;
		sprite_deci.setTextureRect(rec_deci);
		break;
	case 3:
		rec_deci.left = 192;
		sprite_deci.setTextureRect(rec_deci);
		break;
	case 4:
		rec_deci.left = 256;
		sprite_deci.setTextureRect(rec_deci);
		break;
	case 5:
		rec_deci.left = 320;
		sprite_deci.setTextureRect(rec_deci);
		break;
	case 6:
		rec_deci.left = 384;
		sprite_deci.setTextureRect(rec_deci);
		break;
	case 7:
		rec_deci.left = 448;
		sprite_deci.setTextureRect(rec_deci);
		break;
	case 8:
		rec_deci.left = 512;
		sprite_deci.setTextureRect(rec_deci);
		break;
	case 9:
		rec_deci.left = 576;
		sprite_deci.setTextureRect(rec_deci);
		break;
	default:
		break;
	}

	switch (money_uni)
	{
	case 0:
		rec_uni.left = 0;
		sprite_uni.setTextureRect(rec_uni);
		break;
	case 1:
		rec_uni.left = 64;
		sprite_uni.setTextureRect(rec_uni);
		break;
	case 2:
		rec_uni.left = 128;
		sprite_uni.setTextureRect(rec_uni);
		break;
	case 3:
		rec_uni.left = 192;
		sprite_uni.setTextureRect(rec_uni);
		break;
	case 4:
		rec_uni.left = 256;
		sprite_uni.setTextureRect(rec_uni);
		break;
	case 5:
		rec_uni.left = 320;
		sprite_uni.setTextureRect(rec_uni);
		break;
	case 6:
		rec_uni.left = 384;
		sprite_uni.setTextureRect(rec_uni);
		break;
	case 7:
		rec_uni.left = 448;
		sprite_uni.setTextureRect(rec_uni);
		break;
	case 8:
		rec_uni.left = 512;
		sprite_uni.setTextureRect(rec_uni);
		break;
	case 9:
		rec_uni.left = 576;
		sprite_uni.setTextureRect(rec_uni);
		break;
	default:
		break;
	}
}

