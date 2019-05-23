#pragma once
#include "Entite_statique.h"
#include"SFML/Graphics.hpp"
#include "Game.h"

class Towers:public Entite_statique
{
private:
	float rotate = 0;
	int degat = 1;
	int prix = 1;
	int cadence_tir = false;
	float time_cadence_tir = 0;
	float time_fire = 0;
	int feu;

public:
	Towers(sf::Texture *texture, sf::Texture *texturefeu, int feu, sf::IntRect intRect, int prix, int degat, sf::Vector2f position);
	~Towers();

	int getDegat();

	void setCadence(bool cadence);
	bool getCadence();

	void setTimeCadence(float A, float B);
	float getTimeCadence();

	void setTimeFire(float A, float B);
	float getTimeFire();
	void setFire(bool fire);

	void setRotate(int rotate);
};

