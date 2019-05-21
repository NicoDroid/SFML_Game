#pragma once
#include <vector>
#include "Entite.h"
#include "Life_Controller.h"
#include "Money_Controller.h"
#include "Infanterie.h"

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

	static void Appariton_Disparition(char a, std::vector<Entite*> *entite, Life_Controller *life, Money_Controller *money, sf::Clock *clock, sf::Texture *texture_map, sf::Vector2f position, float vitesse_apparition, sf::Texture *texture_explosion, std::vector<sf::Sprite> *sprite_destruction);
	static void Nuclear_Destruction(char n, std::vector<Entite*> *entite, Money_Controller *money, sf::Texture *texture_map, sf::Texture *texture_explosion, std::vector<sf::Sprite> *sprite_destruction);

	static int EventDestroyEntite(std::vector<Entite*> *entite, sf::Texture *texture_explosion, std::vector<sf::Sprite> *sprite_destruction);
	static void AnimeDestruction(sf::Texture *texture_explosion, sf::Vector2f position, std::vector<sf::Sprite> *sprite_destruction);

	void Paused(bool paused);
	bool Paused();
};

