#pragma once
#include <vector>
#include "Entite.h"

class EventController
{
private:
	sf::Font font;
	sf::Texture fond_pause;
	
	bool paused=false;

public:
	sf::Sprite back_pause;
	sf::Text text_pause;

	EventController();
	EventController(char p, sf::Font *font, sf::Texture *texture);
	~EventController();

	static bool EventDestroyEntite(std::vector<Entite*> *entite);
	
	void Paused(bool paused);
	bool Paused();
};

