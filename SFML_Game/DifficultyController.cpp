#include "DifficultyController.h"



DifficultyController::DifficultyController()
{
}


DifficultyController::~DifficultyController()
{
}

float DifficultyController::setDifficulty(sf::Clock *clock)
{
	if (clock->getElapsedTime().asSeconds() < 10.f)
	{
		return 6.0f;
	}
	else if (clock->getElapsedTime().asSeconds() < 20.f)
	{
		return 5.0f;
	}
	else if (clock->getElapsedTime().asSeconds() < 30.f)
	{
		return 4.0f;
	}
	else if (clock->getElapsedTime().asSeconds() < 40.f)
	{
		return 3.0f;
	}
	else if (clock->getElapsedTime().asSeconds() < 50.f)
	{
		return 2.0f;
	}
	else if (clock->getElapsedTime().asSeconds() < 60.f)
	{
		return 1.0f;
	}
	else if (clock->getElapsedTime().asSeconds() > 65.f)
	{
		return 0.5f;
	}
}
