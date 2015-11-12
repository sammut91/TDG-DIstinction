#include "Health.h"


Health::Health()
{
}


Health::~Health()
{
}

void Health::IncreaseHealth()
{
	m_Health++;
}

void Health::IncreaseHealth(int amount)
{
	m_Health += amount;
}

void Health::DecreaseHealth()
{
	m_Health--;
}

void Health::DecreaseHealth(int amount )
{
	m_Health -= amount;
}

bool Health::IsAlive()
{
	bool isalive = true;
	if (m_Health <= 0)
		isalive = false;
	return isalive;
}
