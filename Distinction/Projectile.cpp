#include "Projectile.h"

Projectile::Projectile()
{
	this->m_Position = new Point2D(100.0, 100.0);
	this->m_Velocity = new Vector2D(0.0, 0.0);
	this->m_Accel = new Vector2D(0.0, 0.0);
	m_Target = NULL;
}

Projectile::Projectile(int xPos, int yPos, SDL_Renderer* renderer)
{

	Initialise(renderer);
}

Projectile::Projectile(int xPos, int yPos, SDL_Renderer* renderer, int range)
{
	m_Source = new Point2D(xPos, yPos);
	Initialise(renderer,range);
	m_Position = m_Source;
}


Projectile::~Projectile()
{

}

bool Projectile::Initialise(SDL_Renderer* renderer, int range)
{
	
	m_Texture = new LTexture();
	m_Target = NULL;
	m_Range = range;
	this->m_Position = new Point2D(100.0, 100.0);
	this->m_Velocity = new Vector2D(0.0, 0.0);
	this->m_Force = Vector2D(0.0, 0.0);
	this->m_Accel = new Vector2D(0.0, 0.0);
	bool success = true;
	if (!this->m_Texture->loadFromFile("GreenBullet.png", renderer))
	{
		printf("Failed to load projectile sprite texture!\n");
		success = false;
	}
	return success;
}

bool Projectile::Initialise(SDL_Renderer* renderer)
{
	m_Texture = new LTexture();
	this->m_Position = new Point2D(100.0, 100.0);
	this->m_Velocity = new Vector2D(0.0, 0.0);
	this->m_Force = Vector2D(0.0, 0.0);
	this->m_Accel = new Vector2D(0.0, 0.0);
	bool success = true;
	if (!this->m_Texture->loadFromFile("GreenBullet.png", renderer))
	{
		printf("Failed to load projectile sprite texture!\n");
		success = false;
	}
	return success;
}

Vector2D Projectile::Calculate(float timeStep)
{
	if (m_Target != NULL)
	{
		Vector2D targetPos = PredictPosition(m_Target);
		float distance = targetPos.Length();
		if (distance > 0)
		{
			return targetPos.operator-(*this->m_Position);
		}
	}
}

void Projectile::Update(float timeStep)
{
	if (m_Active)
	{

		this->m_Accel = &m_Force;

		this->m_Velocity->operator+=(*m_Accel);

		this->m_Position->operator+=(this->m_Velocity->operator*(timeStep));

		if (this->m_Source->distance(*m_Position) > m_Range)
		{
			m_Active = false;
		}
	}
	if (!m_Active)
	{

		this->m_Force = Calculate(timeStep);

		this->m_Force.Truncate(MaxForce);
		this->m_Accel = &m_Force;

		this->m_Velocity->operator+=(m_Accel->operator*(timeStep));

		this->m_Velocity->Truncate(MaxSpeed);

		m_Active = true;

		if (this->m_Source->distance(*m_Position) <20)
		{
			m_Active = false;
		}
	}
}

void Projectile::Render(SDL_Renderer* renderer)
{
	if (m_Texture != NULL)
	{
		m_Texture->render(m_Position->x, m_Position->y, renderer);
	}
}

void Projectile::setActive(bool active)
{
	m_Active = active;
}

void Projectile::setRange(int range)
{
	m_Range = range;
}

Vector2D Projectile::PredictPosition(Minion* target)
{
	if (target != NULL)
	{
		Point2D* pos = new Point2D(*target->GetPosition());
		Vector2D* vel = new Vector2D(*target->GetVelocity());
		Vector2D toTarget = pos->operator-(*this->m_Source);

		float lookAhead = toTarget.Length() / (this->MaxSpeed + target->MaxSpeed);

		return vel->operator*(lookAhead)+*pos;
	}
}
