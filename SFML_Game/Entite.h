#pragma once
#include "SFML/Graphics.hpp"

class Entite
{
protected:
	sf::Vector2f position;
public:
	sf::Sprite sprite;
	sf::Sprite sprite_life;
	sf::Sprite sprite_fire;

	Entite(sf::Texture *texture, sf::IntRect intRect);
	~Entite();

	sf::Vector2f getPosition();
	virtual void setPosition(sf::Vector2f position);

	virtual void deplacement() {};
	virtual void rotation(int v_rotation) {};

	virtual void setMouvement(int v_mouvement) {};
	virtual int getMouvement() { return 0; };
	virtual void road() {};
	virtual void decrementLifeEntite(int v_life) {};
	virtual int getLife() { return 0; };
	virtual int getDegat() { return 0; };
	virtual void setCadence(bool cadence) {};
	virtual bool getCadence() { return false; };
	virtual void setTimeCadence(float A, float B) {};
	virtual float getTimeCadence() { return 0; };
	virtual void setTimeFire(float A, float B) {};
	virtual float getTimeFire() { return 0; };
	virtual void setFire(bool fire) {};
	virtual void setRotate(int rotate) {};
};

