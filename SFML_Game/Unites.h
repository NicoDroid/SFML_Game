#pragma once
#include "Entite_mobile.h"
class Unites:public Entite_mobile
{
protected:
	int mouvement = 0;
public:
	Unites(sf::Texture *texture, sf::IntRect intRect);
	~Unites();

	void deplacement();
	void setMouvement(int v_mouvement);
	virtual int getMouvement();
};

