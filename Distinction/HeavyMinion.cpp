#include "HeavyMinion.h"

HeavyMinion::HeavyMinion()
{
	m_Position = new Point2D(100.0, 100.0);
	m_Velocity = new Vector2D(0.0, 0.0);
	m_Accel = new Vector2D(0.0, 0.0);
	m_Texture = new LTexture();
	this->m_Width = 50;
	this->m_Height = 50;
}

HeavyMinion::HeavyMinion(int xPos, int yPos)
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

bool HeavyMinion::Initialise(SDL_Renderer* renderer)
{
	bool success = true;
	setVelocity(0.0, 0.0);
	if (!m_Texture->loadFromFile("PurpleBlob.png", renderer))
	{
		printf("Failed to load minion sprite texture!\n");
		success = false;
	}

	return success;
}

void HeavyMinion::Update(float timeStep)
{
	float maxForce = 1.0;
	float maxSpeed = 1.0;
	Vector2D force = CalculateForce(timeStep);

	force.Truncate(maxForce);
	this->m_Accel = &force;

	this->m_Velocity->operator+=(m_Accel->operator*(timeStep));

	this->m_Velocity->Truncate(maxSpeed);

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
void HeavyMinion::Render(SDL_Renderer* r)
{
	if (m_Texture != NULL)
	{
		m_Texture->render(m_Position->x, m_Position->y, r);
	}

}

bool HeavyMinion::Initialise()
{
	bool success = true;

	return true;
}

Vector2D HeavyMinion::Seek(Point2D* targetPos)
{
	Vector2D* desired_vel = (&targetPos->operator-(*m_Position));

	return (desired_vel->operator-(*m_Velocity));

}

Vector2D HeavyMinion::FollowPath()
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

Vector2D HeavyMinion::CalculateForce(float timeStep)
{
	Vector2D force;
	Point2D*  test = new Point2D(1300.0, 600.0);
	return force = FollowPath();

}

void HeavyMinion::AddPath(Path* p)
{
	if(p!= NULL)	
		this->m_Path = p;
}
