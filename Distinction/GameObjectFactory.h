#pragma once
#include "Tower.h"
#include "Minion.h"

class GameObjectFactory
{
public:
	GameObjectFactory();
	~GameObjectFactory();

	void createTower();
	void createMinion();

	void cleanup();
};

