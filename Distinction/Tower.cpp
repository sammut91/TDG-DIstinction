#include "Tower.h"

Tower::Tower(SDL_Renderer* renderer)
{
	this->m_Position = new Point2D(100.0, 100.0);
	this->m_BeingPlaced = true;
	this->m_Selected = true;
	this->m_Texture = new LTexture();
	this->m_Placed = false;
	Initialise(renderer);
}

Tower::Tower(SDL_Renderer* renderer, float timer)
{
	this->m_Position = new Point2D(100.0, 100.0);
	this->m_BeingPlaced = true;
	this->m_Selected = true;
	this->m_Texture = new LTexture();
	this->m_Placed = false;
	Initialise(renderer);
	m_FireTimer = timer;
}

Tower::Tower(std::string towerType, float xPos, float yPos, SDL_Renderer* renderer)
{
	this->m_Position = new Point2D(xPos,yPos);
	this->m_BeingPlaced = true;
	this->m_Selected = true;
	this->m_Texture = new LTexture();
	this->m_Placed = false;
	Initialise(renderer);
}

Tower::Tower(std::string towerType, float xPos, float yPos, SDL_Renderer* renderer, float timer)
{
	this->m_Position = new Point2D(xPos, yPos);
	this->m_BeingPlaced = true;
	this->m_Selected = true;
	this->m_Texture = new LTexture();
	this->m_Placed = false;
	Initialise(renderer);
	m_FireTimer = timer;
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

//control how fast the tower fires its projectiles
bool Tower::hasFired(float timeStep)
{
	bool fired = true;
	if (!((m_FireTimer - timeStep) > m_FireRate)) //if the time between is greater than the fire rate return false
	{
		return fired = false;
	}
	//if it is less then set the fire timer to the current time and fire return true
	m_FireTimer = timeStep;
	return fired;

}

void Tower::getTarget()
{

}

bool Tower::hasTarget()
{
	return false;
}

bool Tower::Initialise(SDL_Renderer* renderer)
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

void Tower::SetRange(float range)
{
	m_Range = range;
}