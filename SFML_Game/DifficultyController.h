#pragma once
#include "SFML/Graphics.hpp"

class DifficultyController
{
public:
	DifficultyController();
	~DifficultyController();

	static float setDifficulty(float clock);
};

