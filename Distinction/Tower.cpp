#include "Tower.h"


Tower::Tower()
{
	this->m_Position = new Point2D(100.0, 100.0);
}

Tower::Tower(std::string towerType, float xPos, float yPos)
{
	this->m_Position = new Point2D(xPos,yPos);
	m_BeingPlaced = true;
	m_Selected = true;
	m_Placed = false;
}

Tower::~Tower()
{
}

void Tower::HandleInput(SDL_Event* event)
{

}


void Tower::Update()
{

}

void Tower::Update(int mouseX, int mouseY)
{
	m_Position->x = mouseX;
	m_Position->y = mouseY;
}


void Tower::Render()
{

}

void Tower::Render(SDL_Renderer* r)
{
	this->m_Texture->render(m_Position->x, m_Position->y, r);
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

bool Tower::Initialise(std::string objType, SDL_Renderer* renderer)
{
	bool success = true;
	//load the towers sprite from the file
	m_Texture = new LTexture();
	if (!m_Texture->loadFromFile("BombIcon.png", renderer))
	{
		printf("Failed to load minion sprite texture!\n");
		success = false;
	}
	return success;
}

bool Tower::Initialise()
{
	return true;
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

bool Tower::Initialise(std::string objType)
{
	bool success = true;

	return success;
}

void Tower::setBeingPlaced(bool beingPlaced)
{
	m_BeingPlaced = beingPlaced;
}

void Tower::setPlaced(bool setPlaced)
{
	m_Placed = setPlaced;
}

void Tower::setSelected(bool selected)
{
	m_Selected = selected;
}

void Tower::SetPosition(int xPos, int yPos)
{
	m_Position->x = xPos;
	m_Position->y = yPos;
}