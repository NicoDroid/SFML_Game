#pragma once
#include "Entite.h"

class IA_Controller
{
public:
	IA_Controller();
	~IA_Controller();

	static void road(std::vector<Entite*> *entite);
};

