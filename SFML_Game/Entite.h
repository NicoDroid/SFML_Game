#pragma once
#include "SFML/Graphics.hpp"

class Entite
{
protected:
	sf::Vector2f position;
public:
	sf::Sprite sprite;

	Entite(sf::Texture *texture, sf::IntRect intRect);
	~Entite();

	sf::Vector2f getPosition();
	virtual void setPosition(sf::Vector2f position);

	virtual void deplacement() {};
	virtual void rotation(int v_rotation) {};

	virtual void setMouvement(int v_mouvement) {};
	virtual int getMouvement() { return 0; };
	virtual void road() {};
};
