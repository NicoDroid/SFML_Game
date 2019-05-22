#pragma once
#include "Entite_mobile.h"
class Unites:public Entite_mobile
{
protected:
	int mouvement = 0;
	int life = 6;
	
public:
	
	Unites(sf::Texture *texture, sf::Texture *texture_life, sf::IntRect intRect);
	~Unites();

	void deplacement();
	void setMouvement(int v_mouvement);
	void decrementLifeEntite(int v_life);
	int getLife();

	virtual int getMouvement();
};

