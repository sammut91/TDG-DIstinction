#include "Minion.h"


Minion::Minion()
{
}


Minion::~Minion()
{
}

bool Minion::Initialise()
{
	bool success = true; 

	return success;
}

void Minion::Update(float timeStep)
{

	//move the minion left or right based on velocity and time
	m_Position->x += m_VelX * timeStep;

	if (m_Position->x < 0) //if the minion is outside on the left
	{
		m_Position->x = 0;
	}
	else if (m_Position->x > 1600 - m_Width) // if the minion is outside on the right
	{
		m_Position->x = 1600 - m_Width;
	}

	//move the minion up or down based on velocity and time
	m_Position->y += m_VelY * timeStep;

	if (m_Position->y < 0) // if the minion is outside top border
	{
		m_Position->y = 0;
	}
	else if (m_Position->y > 900 - m_Height) //if the minion is outside the bottom border
	{
		m_Position->y = 900 - m_Height;
	}
}

void Minion::HandleInput(SDL_Event* event)
{

}

void Minion::Render(SDL_Renderer* r)
{
	m_Texture->render(m_Position->x, m_Position->y, r);
}