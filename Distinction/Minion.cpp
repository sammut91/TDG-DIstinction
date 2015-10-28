#include "Minion.h"


Minion::Minion()
{
	m_Position = new Point2D(100.0, 100.0);
	m_Velocity = new Vector2D(0.0, 0.0);
	m_Accel = new Vector2D(0.0, 0.0);
	m_Texture = new LTexture();
}


Minion::~Minion()
{
}

Minion::Minion(int xPos, int yPos)
{
	m_Position = new Point2D(xPos, yPos);
	m_Velocity = new Vector2D(0.0, 0.0);
	m_Accel = new Vector2D(0.0, 0.0);
}

bool Minion::Initialise(SDL_Renderer* renderer)
{
	bool success = true; 	
	setVelocity(0.0, 0.0);
	if (!m_Texture->loadFromFile("BlueBlob.png", renderer))
	{
		printf("Failed to load minion sprite texture!\n");
		success = false;
	}	
	return success;
}

void Minion::Update(float timeStep)
{
	float maxForce = 1.0;
	float maxSpeed = 1.0;
	Vector2D force = CalculateForce(timeStep);

	force.Truncate(maxForce);
	m_Accel = &force;

	m_Velocity->operator+=(m_Accel->operator*(timeStep));

	m_Velocity->Truncate(maxSpeed);

	if (!(m_Accel->operator==(Point2D(0.0, 0.0))))
	{
		m_Position->operator+=(m_Velocity->operator*(timeStep));
	}	

	//move the minion left or right based on velocity and time
	//m_Position->x += m_VelX * timeStep;

	if (m_Position->x < 0) //if the minion is outside on the left
	{
		m_Position->x = 0;
	}
	else if (m_Position->x > 1600 - m_Width) // if the minion is outside on the right
	{
		m_Position->x = 1600 - m_Width;
	}

	//move the minion up or down based on velocity and time
	//m_Position->y += m_VelY * timeStep;

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
	switch (event->key.keysym.sym)
	{
	case SDLK_w:
		m_Position->y -= m_Velocity->y;
		break;
	case SDLK_UP: m_Velocity->y -= 2.0; break;
	case SDLK_DOWN: m_Velocity->y += 2.0; break;
	case SDLK_LEFT: m_Velocity->x -= 2.0; break;
	case SDLK_RIGHT: m_Velocity->x += 2.0; break;
	}
}

void Minion::Render()
{

}

//render with renderer
void Minion::Render(SDL_Renderer* r)
{
	if (m_Texture != NULL)
	{
		m_Texture->render(m_Position->x, m_Position->y, r);
	}
	
}

bool Minion::isAlive()
{
	bool alive = true;

	return alive;
}

void Minion::setPosition(int x, int y)
{
	m_Position->x = x;
	m_Position->y = y;
}

void Minion::setSize(int width, int height)
{
	m_Width = width;
	m_Height = height;
}

void Minion::setVelocity(float xVel, float yVel)
{
	m_Velocity->x = xVel;
	m_Velocity->y = yVel;
}

void Minion::setAcceleration(float xAcc, float yAcc)
{
	m_Accel->x = xAcc;
	m_Accel->y = yAcc;
}

Vector2D Minion::Seek(Point2D* targetPos)
{
	Vector2D* desired_vel = (&targetPos->operator-(*m_Position));
	desired_vel->Normalize().operator*(23.6);

	return (desired_vel->operator-(*m_Velocity));

}
Vector2D Minion::FollowPath()
{
	Vector2D force;
	if (m_Path->isFinished())
	{
		if (m_Position->distance(*m_Path->currentPoint())>10)
		{
			return force = Seek(m_Path->currentPoint());
		}
		force.operator&=(Point2D(0.0, 0.0));

		return force;
	}
	else
	{
		if (m_Position->distance(*m_Path->currentPoint())<30)
		{
			m_Path->incrementPoint();
		}
		return force = Seek(m_Path->currentPoint());
	}
}


Vector2D Minion::CalculateForce(float timeStep)
{
	Vector2D force;
	Point2D*  test = new Point2D(1300.0, 600.0);
	if (m_Position->distance(*test)>10)
	{
		return force = Seek(test);
	}
	force.operator&=(Point2D(0.0, 0.0));

	return force;
}

void Minion::Update()
{

}


bool Minion::Initialise()
{
	bool success = true;

	return true;
}

void Minion::AddPath(Path* p)
{
	if (p != NULL)
		m_Path = p;
}

