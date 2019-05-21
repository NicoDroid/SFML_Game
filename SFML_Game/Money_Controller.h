#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class Money_Controller
{
private:
	sf::IntRect rec_dollar;
	sf::IntRect rec_deci;
	sf::IntRect rec_uni;

	int money = 5;

	void gestion_affiche(int money_deci, int money_uni);
public:
	sf::Sprite sprite_dollar;
	sf::Sprite sprite_deci;
	sf::Sprite sprite_uni;

	Money_Controller(sf::Texture *texture);
	~Money_Controller();

	void increment(int valeur);
	void decrement(int valeur);

	int getMoney();
};

