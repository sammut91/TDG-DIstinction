#pragma once
#include "Minion.h"

class MinionFactory
{
public:
	MinionFactory();
	~MinionFactory();

	void createMinion();

	void cleanup();
};

