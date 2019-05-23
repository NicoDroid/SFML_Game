#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class InputController
{
private:
	static int gestionAffiche(int prix);
	std::vector<int> prix;

public:
	sf::Sprite sprite_fond;

	std::vector<sf::Sprite> sprite;

	std::vector<sf::Sprite> sprite_prix;

	InputController(sf::Texture *texture_map, sf::Texture *texture_fond, sf::Texture *texture, sf::Vector2f position_fond, sf::Vector2f position_A, sf::Vector2f position_B, int prix_A, int prix_B);
	InputController(sf::Texture *texture, sf::Vector2f position_A, sf::Vector2f position_B);
	~InputController();

	int getTaille();
	std::vector<int> getPrix();
};

