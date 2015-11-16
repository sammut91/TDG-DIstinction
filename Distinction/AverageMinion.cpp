#include "AverageMinion.h"

AverageMinion::AverageMinion()
{
	m_Position = new Point2D(100.0, 100.0);
	m_Velocity = new Vector2D(0.0, 0.0);
	m_Accel = new Vector2D(0.0, 0.0);
	m_Texture = new LTexture();
	this->m_Width = 50;
	this->m_Height = 50;
}

AverageMinion::AverageMinion(int xPos, int yPos)
{
	m_Position->x = xPos;
	m_Position->y = yPos;
	m_Velocity = new Vector2D(0.0, 0.0);
	m_Accel = new Vector2D(0.0, 0.0);
	this->m_Width = 50;
	this->m_Height = 50;
	m_Texture = new LTexture();
	m_Path = new Path();
}

AverageMinion::AverageMinion(int xPos, int yPos, SDL_Renderer* renderer, Path* p)
{
	m_Position = new Point2D(xPos, yPos);
	m_Velocity = new Vector2D(0.0, 0.0);
	m_Accel = new Vector2D(0.0, 0.0);
	this->m_Width = 50;
	this->m_Height = 50;
	m_Texture = new LTexture();

	//creates a new path for each minion that is the same as the main path
	//so they dont all follow the same path
	m_Path = new Path(*p);
	Initialise(renderer);
}

AverageMinion::AverageMinion(int xPos, int yPos, SDL_Renderer* renderer, Path* p, int damage, int health)
{
	m_Position = new Point2D(xPos, yPos);
	m_Velocity = new Vector2D(0.0, 0.0);
	m_Accel = new Vector2D(0.0, 0.0);
	this->m_Width = 40;
	this->m_Height = 40;
	m_Texture = new LTexture();
	//creates a new path for each minion that is the same as the main path
	//so they dont all follow the same path
	m_Path = new Path(*p);
	Initialise(renderer);

	SetHealth(health);
	SetDamage(damage);
}

bool AverageMinion::Initialise(SDL_Renderer* renderer)
{
	bool success = true;
	this->setVelocity(0.0, 0.0);
	if (!m_Texture->loadFromFile("BlueBlob.png", renderer))
	{
		printf("Failed to load minion sprite texture!\n");
		success = false;
	}
	SetScore(25);
	SetValue(4);
	return success;
}

void AverageMinion::Update(float timeStep)
{
	Vector2D force = CalculateForce(timeStep);

	force.Truncate(MaxForce);
	this->m_Accel = &force;

	this->m_Velocity->operator+=(m_Accel->operator*(timeStep));

	this->m_Velocity->Truncate(MaxSpeed);

	if (!(this->m_Accel->operator==(Point2D(0.0, 0.0))))
	{
		this->m_Position->operator+=(this->m_Velocity->operator*(timeStep));
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

//render with renderer
void AverageMinion::Render(SDL_Renderer* r)
{
	if (m_Texture != NULL)
	{
		m_Texture->render(m_Position->x, m_Position->y, r);
	}

}

bool AverageMinion::Initialise()
{
	bool success = true;

	return true;
}

Vector2D AverageMinion::Seek(Point2D* targetPos)
{
	Vector2D* desired_vel = (&targetPos->operator-(*m_Position));
	desired_vel->operator*(600.0);
	return (desired_vel->operator-(*m_Velocity));

}

Vector2D AverageMinion::FollowPath()
{
	Vector2D force;
	if (m_Path->isFinished())
	{
		if (m_Position->distance(*m_Path->currentPoint())>30)
		{
			return force = Seek(m_Path->currentPoint());
		}
		force.operator&=(Point2D(0.0, 0.0));

		return force;
	}
	else
	{
		if (m_Position->distance(*m_Path->currentPoint())<40)
		{
			m_Path->incrementPoint();
		}
		return force = Seek(m_Path->currentPoint());
	}
}

Vector2D AverageMinion::CalculateForce(float timeStep)
{
	Vector2D force;
	Point2D*  test = new Point2D(1300.0, 600.0);
	return force = FollowPath();

}

void AverageMinion::AddPath(Path* p)
{
	if (p != NULL)
		this->m_Path = p;
}

bool AverageMinion::AtDestination()
{
	bool atDest = false;
	if (this->m_Position->distance(*this->m_Path->getDestination())<30)
	{
		atDest = true;
	}

	return atDest;
}

