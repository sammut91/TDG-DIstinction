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
	SetCost(150.0);
	Initialise(renderer);
	//m_FireTimer = timer;
}

Tower::Tower(std::string towerType, float xPos, float yPos, SDL_Renderer* renderer)
{
	this->m_Position = new Point2D(xPos,yPos);
	this->m_BeingPlaced = true;
	this->m_Selected = true;
	this->m_Texture = new LTexture();
	this->m_Placed = false;
	SetCost(150.0);
	Initialise(renderer);
}

Tower::Tower(std::string towerType, float xPos, float yPos, SDL_Renderer* renderer, float timer)
{
	this->m_Position = new Point2D(xPos, yPos);
	this->m_BeingPlaced = true;
	this->m_Selected = true;
	this->m_Texture = new LTexture();
	this->m_Placed = false;
	SetCost(150.0);
	Initialise(renderer);
	//m_FireTimer = timer;
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

	if (m_Position->x <= 0)
	{
		m_Position->x = 0;
	}

	if (m_Position->x >= 1440 - m_Texture->getWidth())
	{
		m_Position->x = 1440 - m_Texture->getWidth();
	}

	if (m_Position->y >= 900 - m_Texture->getHeight())
	{
		m_Position->y = 900 - m_Texture->getHeight();
	}

	if (m_Position->y <= 0)
	{
		m_Position->y = 0;
	}
}


void Tower::Render()
{

}

void Tower::Render(SDL_Renderer* r)
{
	this->m_Texture->render(m_Position->x, m_Position->y, r);
}

//to be used when the tower is upgraded
void Tower::upgrade()
{

}

void Tower::fire(float timeStep, float fireTimeStep, std::vector<Minion*> &targets)
{
	if (!m_Projectiles.empty())
	{
		if (hasFired(fireTimeStep))
		{
			for each (Projectile* p in m_Projectiles)
			{
				if (!p->isActive() && p->GetTarget()!= NULL)
				{
					p->CalculateForce(timeStep);
					p->setActive(true);
					break;
				}
				
			}
		}
		for each (Projectile* p in m_Projectiles)
		{
			p->Update(timeStep, targets);
		}
	}
}

//control how fast the tower fires its projectiles
bool Tower::hasFired(float timeStep)
{
	bool fired = false;
	if (!((m_FireTimer - timeStep) > m_FireRate)) //if the time between is greater than the fire rate return false
	{
		return false;
	}
	//if it is less then set the fire timer to the current time and fire return true
	m_FireTimer = timeStep;
	if (m_FireTimer < m_FireRate)
	{
		//makes sure that the tower resets when the wave resets
		m_FireTimer = 30.0;
	}
	printf("%f", m_FireTimer);
	printf("Time Step %f", timeStep);
	return fired = true;
}

void Tower::getTarget(std::vector<Minion*> &targets)
{
	float distanceTo = 10000000.0;
	if (!targets.empty())
	{
		for each (Minion* target in targets)
		{			
			//if the target is within the range of the tower
			if (this->m_Position->distance(*target->GetPosition()) < Range())
			{
				float distanceToTemp = this->m_Position->distance(*target->GetPosition());
				if (distanceToTemp < distanceTo)
				{
					distanceTo = distanceToTemp;

					//if the projectiles arent empty
					if (!m_Projectiles.empty())
					{
						//printf("Changing target %f", distanceTo);
						for each (Projectile* p in m_Projectiles)
						{
							if (!p->isActive())
							{
								// set the target of the projectiles to the current closest target
								p->SetTarget(target);							
							}

						}
					}
				}
			}
		}
	}
	else 
	for each (Projectile* p in m_Projectiles)
	{
		if (!p->isActive())
		{
			p->SetTarget(NULL);
		}
	}

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

void Tower::AddProjectiles(SDL_Renderer* r)
{
	if (m_Placed)
	{
		for (int i = 0; i < ClipSize; i++)
		{
			m_Projectiles.push_back(new Projectile(this->m_Position->x, this->m_Position->y,
				r, this->Range()));
		}
		loadAmmo = true;
	}
}