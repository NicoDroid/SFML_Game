#include "EventController.h"
#include <iostream>


EventController::EventController()
{
}


EventController::~EventController()
{
}

void EventController::EventDestroyEntite(std::vector<Entite*> *entite)
{
	for (int i = 0; i < entite->size(); i++)
	{
		std::cout << entite->at(i)->getMouvement() << std::endl;
		if (entite->at(i)->getMouvement() == -1)
		{
			
			delete entite->at(i);
			entite->erase(entite->begin() + i);
		}
	}
}
