#pragma once
#include <vector>
#include "Entite.h"
#include "Life_Controller.h"
#include "Money_Controller.h"
#include "Infanterie.h"
#include "InputController.h"
#include "Towers.h"
#include "Game.h"

class EventController
{
private:
	sf::Font font;
	sf::Texture fond_pause_gameover;

	bool paused=false;
	bool gameover = false;

public:
	sf::Sprite back__pause_gameover;
	sf::Text text_pause;
	sf::Text text_game_over;

	EventController();
	EventController(char p, sf::Font *font, sf::Texture *texture);
	
	~EventController();

	static void Detection_enemi(std::vector<Entite*> *enemi, std::vector<Entite*> *tower, sf::Texture *texture_explosion, std::vector<sf::Sprite> *sprite_destruction, float dt);

	static void Appariton_Disparition(char a, std::vector<Entite*> *entite, Life_Controller *life, Money_Controller *money, sf::Clock *clock, sf::Texture *texture_map, sf::Texture *texture_life, sf::Vector2f position, float vitesse_apparition, sf::Texture *texture_explosion, std::vector<sf::Sprite> *sprite_destruction);
	static void Nuclear_Destruction(char n, std::vector<Entite*> *entite, Money_Controller *money, sf::Texture *texture_map, sf::Texture *texture_explosion, std::vector<sf::Sprite> *sprite_destruction);

	static void Heal_Full(char h, Life_Controller *life);

	static int EventDestroyEntite(std::vector<Entite*> *entite, sf::Texture *texture_explosion, std::vector<sf::Sprite> *sprite_destruction, Money_Controller *money);
	static void AnimeDestruction(sf::Texture *texture_explosion, sf::Vector2f position, std::vector<sf::Sprite> *sprite_destruction);

	static void MouseChoiceTower(sf::Vector2i localPosition, InputController *input, bool *Temp_mouse, int *Temp_tower, Game *game);
	static void MouseCreateTower(sf::Texture *texture, sf::Texture *texture_feu, sf::Vector2i localPosition, std::vector<Entite*> *entite, bool *Temp_mouse, int *Temp_tower, Money_Controller *money, Game *game);

	void Paused(bool paused);
	bool Paused();

	void GameOver(bool gameover);
	bool GameOver();
};

