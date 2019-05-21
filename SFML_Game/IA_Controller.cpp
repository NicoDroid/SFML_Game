#include "IA_Controller.h"
#include <iostream>


IA_Controller::IA_Controller()
{
}


IA_Controller::~IA_Controller()
{
}

void IA_Controller::road(std::vector<Entite*> *entite)
{
	std::cout << entite->size() << std::endl;
	for (int i = 0; i < entite->size(); i++)
	{
		entite->at(i)->deplacement();
		if (entite->at(i)->getPosition().x == 0 && entite->at(i)->getPosition().y == 672)
		{
			//std::cout << i << std::endl;
			entite->at(i)->setMouvement(6);
		}
		else if (entite->at(i)->getPosition().x == 670 && entite->at(i)->getPosition().y == 672)
		{
			entite->at(i)->rotation(-90);
			entite->at(i)->setMouvement(8);

		}
		else if (entite->at(i)->getPosition().x == 670 && entite->at(i)->getPosition().y == 287)
		{
			entite->at(i)->rotation(90);
			entite->at(i)->setMouvement(6);
		}
		else if (entite->at(i)->getPosition().x == 865 && entite->at(i)->getPosition().y == 287)
		{
			entite->at(i)->rotation(90);
			entite->at(i)->setMouvement(2);
		}
		else if (entite->at(i)->getPosition().x == 865 && entite->at(i)->getPosition().y == 672)
		{
			entite->at(i)->rotation(-90);
			entite->at(i)->setMouvement(6);
		}
		else if (entite->at(i)->getPosition().x == 1630 && entite->at(i)->getPosition().y == 672)
		{
			entite->at(i)->rotation(90);
			entite->at(i)->setMouvement(2);
		}
		else if (entite->at(i)->getPosition().x == 1630 && entite->at(i)->getPosition().y == 1017)
		{
			entite->at(i)->setMouvement(-1);
			std::cout << "Game Over" << std::endl;
			delete entite->at(i);
			entite->erase(entite->begin() + i);
		}
	}
}


