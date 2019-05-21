#include "EventController.h"
#include <iostream>


EventController::EventController()
{
}

//Gestion des pauses
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

//Gestion des destruction d'entites
bool EventController::EventDestroyEntite(std::vector<Entite*> *entite, sf::Texture *texture_explosion, std::vector<sf::Sprite> *sprite_destruction)
{
	for (int i = 0; i < entite->size(); i++)
	{
		if (entite->at(i)->getMouvement() == -1)
		{
			EventController::AnimeDestruction(texture_explosion, entite->at(i)->getPosition(), sprite_destruction);
			delete entite->at(i);
			entite->erase(entite->begin() + i);
			return true;
		}
		return false;
	}
} //Gestio,

//Fonctions des pauses
void EventController::Paused(bool paused)
{
	this->paused = paused;
}
bool EventController::Paused()
{
	return this->paused;
}

//Gestion des apparitionn d'entites
void EventController::Appariton(char a, std::vector<Entite*> *entite, Life_Controller *life, Money_Controller *money, sf::Clock *clock, sf::Texture *texture_map, sf::Vector2f position, float vitesse_apparition, sf::Texture *texture_explosion, std::vector<sf::Sprite> *sprite_destruction)
{
	if (life->getLife() != 0)
	{
		if (clock->getElapsedTime().asSeconds() > vitesse_apparition) {
			entite->push_back(new Infanterie(position, texture_map, sf::IntRect(1152, 704, 64, 64)));
			money->increment(5);
			clock->restart();
		}

		for (int i = 0; i < entite->size(); i++)
		{
			entite->at(i)->road();
			if (EventController::EventDestroyEntite(entite,texture_explosion,sprite_destruction))
			{
				life->decrementLife();
			}
		}
	}
}

void EventController::AnimeDestruction(sf::Texture *texture_explosion, sf::Vector2f position, std::vector<sf::Sprite> *sprite_destruction)
{
	sf::Sprite sprite(*texture_explosion, sf::IntRect(289, 33, 70, 70));
	sprite.setPosition(position);
	sprite.setOrigin(35,35);
	sprite_destruction->push_back(sprite);
}


