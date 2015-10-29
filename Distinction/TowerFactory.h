#pragma once
#include "Tower.h"
class TowerFactory
{
public:
	TowerFactory();
	~TowerFactory();

	Tower* createTower(std::string type, SDL_Renderer* renderer);

	void cleanup();
};

