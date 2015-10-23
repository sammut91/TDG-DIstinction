#include "Tower.h"


Tower::Tower()
{
}

Tower::Tower(std::string towerType)
{
	
}

Tower::~Tower()
{
}

void Tower::Update()
{

}

void Tower::Render()
{

}

void Tower::upgrade()
{

}

void Tower::fire()
{

}

void Tower::getTarget()
{

}

bool Tower::hasTarget()
{
	return false;
}

bool Tower::Initialise(std::string objType)
{
	bool success = true;
	//load the towers sprite from the file
	m_Sprites.front() =  SDL_LoadBMP("sdkf");
	if (m_Sprites.front() == NULL)
		return false;
	return success;
}

bool Tower::isBeingPlaced()
{
	bool selected = true;

	return selected;
}

bool Tower::isSelected()
{
	bool selected = true;

	return selected;
}

bool Tower::isPlaced()
{
	bool placed = true;

	return placed;
}