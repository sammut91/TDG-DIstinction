#include "MinionFactory.h"


MinionFactory::MinionFactory()
{
	m_Position = new Point2D(100.0, 100.0);
}


MinionFactory::~MinionFactory()
{

}

Minion* MinionFactory::createMinion(std::string type, SDL_Renderer* renderer, Path* p)
{
	if (type == "Heavy")
	{
		return new HeavyMinion(m_Position->x,m_Position->y,renderer, p);
	}
	else if (type == "Fast")
	{
		return new FastMinion(m_Position->x, m_Position->y, renderer, p);
	}
	else if (type == "Boss")
	{
		return new BossMinion(m_Position->x, m_Position->y, renderer, p);
	}
	else if (type == "Average")
	{
		return new AverageMinion(m_Position->x, m_Position->y, renderer, p);
	}
	else
	{
		return new Minion(m_Position->x, m_Position->y);
	}
}

void MinionFactory::cleanup()
{

}
