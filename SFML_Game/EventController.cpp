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
int EventController::EventDestroyEntite(std::vector<Entite*> *entite, sf::Texture *texture_explosion, std::vector<sf::Sprite> *sprite_destruction, Money_Controller *money)
{
	for (int i = 0; i < entite->size(); i++)
	{
		if (entite->at(i)->getMouvement() == -1)
		{
			delete entite->at(i);
			entite->erase(entite->begin() + i);
			return 1;
		}
		if (entite->at(i)->getLife() <= 0 && entite->at(i)->getMouvement() != -1)
		{
			money->increment(5);
			EventController::AnimeDestruction(texture_explosion, entite->at(i)->getPosition(), sprite_destruction);
			delete entite->at(i);
			entite->erase(entite->begin() + i);
			return 2;
		}
		return 0;
	}
}

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
void EventController::Appariton_Disparition(char a, std::vector<Entite*> *entite, Life_Controller *life, Money_Controller *money, sf::Clock *clock, sf::Texture *texture_map, sf::Vector2f position, float vitesse_apparition, sf::Texture *texture_explosion, std::vector<sf::Sprite> *sprite_destruction)
{
	if (life->getLife() != 0)
	{
		if (clock->getElapsedTime().asSeconds() > vitesse_apparition) {
			entite->push_back(new Infanterie(position, texture_map, sf::IntRect(1152, 704, 64, 64)));
			clock->restart();
		}

		for (int i = 0; i < entite->size(); i++)
		{
			entite->at(i)->road();
			if (EventController::EventDestroyEntite(entite, texture_explosion, sprite_destruction, money) == 1)
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
	sprite.setOrigin(35, 35);
	sprite_destruction->push_back(sprite);
}

void EventController::Nuclear_Destruction(char n, std::vector<Entite*> *entite, Money_Controller *money, sf::Texture *texture_map, sf::Texture *texture_explosion, std::vector<sf::Sprite> *sprite_destruction)
{
	for (int i = 0; i < entite->size(); i++)
	{
		entite->at(i)->decrementLifeEntite(6);
	}
	EventController::EventDestroyEntite(entite, texture_explosion, sprite_destruction, money);
}

void EventController::Heal_Full(char h, Life_Controller *life)
{
	life->setFullLife();
}

void EventController::MouseChoiceTower(sf::Vector2i localPosition, InputController *input, bool *Temp_mouse, int *Temp_tower)
{
	if ((localPosition.x >= input->sprite[0].getPosition().x && localPosition.x <= input->sprite[0].getPosition().x + 64) && (localPosition.y >= input->sprite[0].getPosition().y && localPosition.y <= input->sprite[0].getPosition().y + 64))
	{
		std::cout << "Dedans1" << std::endl;
		*Temp_mouse = true;
		*Temp_tower = 0;

	}else if ((localPosition.x >= input->sprite[1].getPosition().x && localPosition.x <= input->sprite[1].getPosition().x + 64) && (localPosition.y >= input->sprite[1].getPosition().y && localPosition.y <= input->sprite[1].getPosition().y + 64))
	{
		std::cout << "Dedans2" << std::endl;
		*Temp_mouse = true;
		*Temp_tower = 1;
	}
}

void EventController::MouseCreateTower(sf::Texture *texture, sf::Vector2i localPosition, std::vector<Entite*> *entite , bool *Temp_mouse, int *Temp_tower, Money_Controller *money)
{
	if (*Temp_tower == 0 && money->getMoney()>=2)
	{
		money->decrement(2);
		int x = (localPosition.x / 64) * 64;
		int y = (localPosition.y / 64) * 64;
		std::cout << "Pose1" << std::endl;
		*Temp_mouse = false;
		entite->push_back(new Towers(texture, sf::IntRect(0, 0, 64, 64), 2, 1, sf::Vector2f((float)x + 32, (float)y + 32)));
	}
	else if(*Temp_tower == 1 && money->getMoney() >= 5)
	{
		money->decrement(5);
		int x = (localPosition.x / 64) * 64;
		int y = (localPosition.y / 64) * 64;
		std::cout << "Pose2" << std::endl;
		*Temp_mouse = false;
		entite->push_back(new Towers(texture, sf::IntRect(64, 0, 64,64), 5, 2, sf::Vector2f((float)x + 32, (float)y + 32)));
	}
	else
	{
		*Temp_mouse = false;
	}
}

void EventController::Detection_enemi(std::vector<Entite*> *enemi, std::vector<Entite*> *tower, sf::Texture *texture_explosion, std::vector<sf::Sprite> *sprite_destruction, float dt)
{
		for (int i = 0; i < tower->size(); i++)
		{
			for (int j = 0; j < enemi->size(); j++)
			{
					//Haut
					if (enemi->at(j)->getPosition().x == tower->at(i)->getPosition().x && enemi->at(j)->getPosition().y == tower->at(i)->getPosition().y - 128 && !tower->at(i)->getCadence())
					{
						
						tower->at(i)->setCadence(true);
						tower->at(i)->setRotate(0);
						enemi->at(j)->decrementLifeEntite(tower->at(i)->getDegat());
						std::cout << "ToucheHM" << std::endl;
					}
					else if (enemi->at(j)->getPosition().x == tower->at(i)->getPosition().x - 64 && enemi->at(j)->getPosition().y == tower->at(i)->getPosition().y - 128 && !tower->at(i)->getCadence())
					{
						tower->at(i)->setCadence(true);
						tower->at(i)->setRotate(11);
						enemi->at(j)->decrementLifeEntite(tower->at(i)->getDegat());
						std::cout << "ToucheHG" << std::endl;
					}
					else if (enemi->at(j)->getPosition().x == tower->at(i)->getPosition().x + 64 && enemi->at(j)->getPosition().y == tower->at(i)->getPosition().y - 128 && !tower->at(i)->getCadence())
					{
						tower->at(i)->setCadence(true);
						tower->at(i)->setRotate(1);
						enemi->at(j)->decrementLifeEntite(tower->at(i)->getDegat());
						std::cout << "ToucheHD" << std::endl;
					}
					//Gauche
					if (enemi->at(j)->getPosition().x == tower->at(i)->getPosition().x - 128 && enemi->at(j)->getPosition().y == tower->at(i)->getPosition().y && !tower->at(i)->getCadence())
					{
						tower->at(i)->setCadence(true);
						tower->at(i)->setRotate(9);
						enemi->at(j)->decrementLifeEntite(tower->at(i)->getDegat());
						std::cout << "ToucheGM" << std::endl;
					}
					else if (enemi->at(j)->getPosition().x == tower->at(i)->getPosition().x - 128 && enemi->at(j)->getPosition().y == tower->at(i)->getPosition().y - 64 && !tower->at(i)->getCadence())
					{
						tower->at(i)->setCadence(true);
						tower->at(i)->setRotate(10);
						enemi->at(j)->decrementLifeEntite(tower->at(i)->getDegat());
						std::cout << "ToucheGH" << std::endl;
					}
					else if (enemi->at(j)->getPosition().x == tower->at(i)->getPosition().x - 128 && enemi->at(j)->getPosition().y == tower->at(i)->getPosition().y + 64 && !tower->at(i)->getCadence())
					{
						tower->at(i)->setCadence(true);
						tower->at(i)->setRotate(8);
						enemi->at(j)->decrementLifeEntite(tower->at(i)->getDegat());
						std::cout << "ToucheGB" << std::endl;
					}
					//Droite
					if (enemi->at(j)->getPosition().x == tower->at(i)->getPosition().x + 124 && enemi->at(j)->getPosition().y == tower->at(i)->getPosition().y && !tower->at(i)->getCadence())
					{
						tower->at(i)->setCadence(true);
						tower->at(i)->setRotate(3);
						enemi->at(j)->decrementLifeEntite(tower->at(i)->getDegat());
						std::cout << "ToucheDM" << std::endl;
					}
					else if (enemi->at(j)->getPosition().x == tower->at(i)->getPosition().x + 124 && enemi->at(j)->getPosition().y == tower->at(i)->getPosition().y - 64 && !tower->at(i)->getCadence())
					{
						tower->at(i)->setCadence(true);
						tower->at(i)->setRotate(2);
						enemi->at(j)->decrementLifeEntite(tower->at(i)->getDegat());
						std::cout << "ToucheDH" << std::endl;
					}
					else if (enemi->at(j)->getPosition().x == tower->at(i)->getPosition().x + 124 && enemi->at(j)->getPosition().y == tower->at(i)->getPosition().y + 64 && !tower->at(i)->getCadence())
					{
						tower->at(i)->setCadence(true);
						tower->at(i)->setRotate(4);
						enemi->at(j)->decrementLifeEntite(tower->at(i)->getDegat());
						std::cout << "ToucheDB" << std::endl;
					}
					//Bas
					if (enemi->at(j)->getPosition().x == tower->at(i)->getPosition().x && enemi->at(j)->getPosition().y == tower->at(i)->getPosition().y + 124 && !tower->at(i)->getCadence())
					{
						tower->at(i)->setCadence(true);
						tower->at(i)->setRotate(6);
						enemi->at(j)->decrementLifeEntite(tower->at(i)->getDegat());
						std::cout << "ToucheBM" << std::endl;
					}
					else if (enemi->at(j)->getPosition().x == tower->at(i)->getPosition().x - 64 && enemi->at(j)->getPosition().y == tower->at(i)->getPosition().y + 124 && !tower->at(i)->getCadence())
					{
						tower->at(i)->setCadence(true);
						tower->at(i)->setRotate(7);
						enemi->at(j)->decrementLifeEntite(tower->at(i)->getDegat());
						std::cout << "ToucheBG" << std::endl;
					}
					else if (enemi->at(j)->getPosition().x == tower->at(i)->getPosition().x + 64 && enemi->at(j)->getPosition().y == tower->at(i)->getPosition().y + 124 && !tower->at(i)->getCadence())
					{
						tower->at(i)->setCadence(true);
						tower->at(i)->setRotate(5);
						enemi->at(j)->decrementLifeEntite(tower->at(i)->getDegat());
						std::cout << "ToucheBD" << std::endl;
					}
				}
			if (tower->at(i)->getCadence())
			{
				tower->at(i)->setTimeCadence(tower->at(i)->getTimeCadence(), dt);
				if (tower->at(i)->getTimeCadence() > 1.0f)
				{
					tower->at(i)->setTimeCadence(0.0f, 0.0f);
					tower->at(i)->setCadence(false);
				}
			}
			}
}





