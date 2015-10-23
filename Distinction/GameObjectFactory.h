#pragma once
#include "Tower.h"

class GameObjectFactory
{
public:
	GameObjectFactory();
	~GameObjectFactory();

	void createTower();
	void createMinion();

	void cleanup();
};

