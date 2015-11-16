#pragma once
#include "Minion.h"
#include "HeavyMinion.h"
#include "FastMinion.h"
#include "BossMinion.h"
#include "AverageMinion.h"

class MinionFactory
{
public:
	MinionFactory();
	~MinionFactory();

	Minion* createMinion(std::string type, SDL_Renderer* renderer, Path* p);


	void cleanup();
private:
	Point2D* m_Position;
};

