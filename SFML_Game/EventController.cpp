#include "EventController.h"
#include <iostream>


EventController::EventController()
{
}

EventController::EventController(char p, sf::Font *font, sf::Texture *texture)
{
	back_pause.setTexture(*texture);
	back_pause.setColor(sf::Color(255, 255, 255, 158));
	back_pause.scale(sf::Vector2f(2, 2));

	text_pause.setFont(*font);
	text_pause.setString("PAUSE");
	text_pause.setCharacterSize(40);
	text_pause.setFillColor(sf::Color::White);
	text_pause.setPosition(1720 / 2, 880 / 2);
}

EventController::~EventController()
{
}

bool EventController::EventDestroyEntite(std::vector<Entite*> *entite)
{
	for (int i = 0; i < entite->size(); i++)
	{
		if (entite->at(i)->getMouvement() == -1)
		{
			
			delete entite->at(i);
			entite->erase(entite->begin() + i);
			return true;
		}
		return false;
	}
}

void EventController::Paused(bool paused)
{
	this->paused = paused;
}
bool EventController::Paused()
{
	return this->paused;
}

