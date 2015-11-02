#include "Minion.h"


Minion::Minion()
{
	this->m_Position = new Point2D(100.0, 100.0);
	this->m_Velocity = new Vector2D(0.0, 0.0);
	this->m_Accel = new Vector2D(0.0, 0.0);
	this->m_Texture = new LTexture();
}


Minion::~Minion()
{
}

Minion::Minion(int xPos, int yPos)
{
	this->m_Position = new Point2D(xPos, yPos);
	this->m_Velocity = new Vector2D(0.0, 0.0);
	this->m_Accel = new Vector2D(0.0, 0.0);
}
Minion::Minion(int xPos, int yPos, SDL_Renderer* renderer)
{
	this->m_Position = new Point2D(xPos, yPos);
	this->m_Velocity = new Vector2D(0.0, 0.0);
	this->m_Accel = new Vector2D(0.0, 0.0);
	Initialise(renderer);
}


bool Minion::Initialise(SDL_Renderer* renderer)
{
	bool success = true; 	
	setVelocity(0.0, 0.0);
	if (!this->m_Texture->loadFromFile("BlueBlob.png", renderer))
	{
		printf("Failed to load minion sprite texture!\n");
		success = false;
	}	
	return success;
}

void Minion::Update(float timeStep)
{

	Vector2D force = CalculateForce(timeStep);

	force.Truncate(MaxForce);
	this->m_Accel = &force;

	this->m_Velocity->operator+=(m_Accel->operator*(timeStep));

	this->m_Velocity->Truncate(MaxSpeed);

	if (!(this->m_Accel->operator==(Point2D(0.0, 0.0))))
	{
		this->m_Position->operator+=(m_Velocity->operator*(timeStep));
	}	

	//move the minion left or right based on velocity and time
	//m_Position->x += m_VelX * timeStep;

	if (this->m_Position->x < 0) //if the minion is outside on the left
	{
		this->m_Position->x = 0;
	}
	else if (this->m_Position->x > 1600 - this->m_Width) // if the minion is outside on the right
	{
		this->m_Position->x = 1600 - this->m_Width;
	}

	//move the minion up or down based on velocity and time
	//m_Position->y += m_VelY * timeStep;

	if (this->m_Position->y < 0) // if the minion is outside top border
	{
		this->m_Position->y = 0;
	}
	else if (this->m_Position->y > 900 - this->m_Height) //if the minion is outside the bottom border
	{
		this->m_Position->y = 900 - this->m_Height;
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
	if (this->m_Texture != NULL)
	{
		this->m_Texture->render(this->m_Position->x, this->m_Position->y, r);
	}
	
}

bool Minion::isAlive()
{
	bool alive = true;

	return alive;
}

void Minion::setPosition(int x, int y)
{
	this->m_Position->x = x;
	this->m_Position->y = y;
}

void Minion::setSize(int width, int height)
{
	this->m_Width = width;
	this->m_Height = height;
}

void Minion::setVelocity(float xVel, float yVel)
{
	this->m_Velocity->x = xVel;
	this->m_Velocity->y = yVel;
}

void Minion::setAcceleration(float xAcc, float yAcc)
{
	this->m_Accel->x = xAcc;
	this->m_Accel->y = yAcc;
}

Vector2D Minion::Seek(Point2D* targetPos)
{
	Vector2D* desired_vel = (&targetPos->operator-(*this->m_Position));
	desired_vel->Normalize().operator*(23.6);

	return (desired_vel->operator-(*this->m_Velocity));

}
Vector2D Minion::FollowPath()
{
	Vector2D force;
	if (m_Path->isFinished())
	{
		if (this->m_Position->distance(*this->m_Path->currentPoint())>10)
		{
			return force = Seek(this->m_Path->currentPoint());
		}
		force.operator&=(Point2D(0.0, 0.0));

		return force;
	}
	else
	{
		if (this->m_Position->distance(*this->m_Path->currentPoint())<30)
		{
			this->m_Path->incrementPoint();
		}
		return force = Seek(this->m_Path->currentPoint());
	}
}


Vector2D Minion::CalculateForce(float timeStep)
{
	Vector2D force;
	Point2D*  test = new Point2D(1300.0, 600.0);
	if (this->m_Position->distance(*test)>10)
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
		this->m_Path = p;
}

bool Minion::AtDestination()
{
	bool atDest = false;
	if (m_Position->distance(*this->m_Path->getDestination())<20)
	{
		atDest = true;
	}

	return atDest;
}

