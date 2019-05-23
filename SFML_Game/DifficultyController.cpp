#include "DifficultyController.h"



DifficultyController::DifficultyController()
{
}


DifficultyController::~DifficultyController()
{
}

float DifficultyController::setDifficulty(float *clock)
{
	if (*clock < 10.f)
	{
		return 10.0f;
	}
	else if (*clock < 15.f)
	{
		return 9.0f;
	}
	else if (*clock < 20.f)
	{
		return 8.0f;
	}
	else if (*clock < 25.f)
	{
		return 7.0f;
	}
	else if (*clock < 30.f)
	{
		return 6.0f;
	}
	else if (*clock < 35.f)
	{
		return 5.0f;
	}
	else if (*clock > 40.f)
	{
		return 4.0f;
	}
	else if (*clock < 45.f)
	{
		return 3.0f;
	}
	else if (*clock < 50.f)
	{
		return 2.0f;
	}
	else if (*clock > 55.f)
	{
		return 1.0f;
	}
	else if (*clock < 60.f)
	{
		return 0.75f;
	}
	else if (*clock < 65.f)
	{
		return 0.5f;
	}
	else if (*clock > 70.f)
	{
		return 0.25f;
	}
}
