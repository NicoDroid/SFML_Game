#pragma once
#include <vector>
#include "Entite.h"

class EventController
{
public:
	EventController();
	~EventController();

	static void EventDestroyEntite(std::vector<Entite*> *entite);
};

