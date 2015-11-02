#include "Projectile.h"

Projectile::Projectile()
{
	this->m_Position = new Point2D(100.0, 100.0);
	this->m_Velocity = new Vector2D(0.0, 0.0);
	this->m_Accel = new Vector2D(0.0, 0.0);
}

Projectile::Projectile(int xPos, int yPos, SDL_Renderer* renderer)
{

	Initialise(renderer);
}

Projectile::Projectile(int xPos, int yPos, SDL_Renderer* renderer, int range)
{
	m_Source = new Point2D(xPos, yPos);
	Initialise(renderer,range);
}


Projectile::~Projectile()
{

}

bool Projectile::Initialise(SDL_Renderer* renderer, int range)
{
	m_Texture = new LTexture();
	m_Range = range;
	this->m_Position = new Point2D(100.0, 100.0);
	this->m_Velocity = new Vector2D(0.0, 0.0);
	this->m_Accel = new Vector2D(0.0, 0.0);
	bool success = true;
	if (!this->m_Texture->loadFromFile("BlueBlob.png", renderer))
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
	this->m_Accel = new Vector2D(0.0, 0.0);
	bool success = true;
	if (!this->m_Texture->loadFromFile("BlueBlob.png", renderer))
	{
		printf("Failed to load projectile sprite texture!\n");
		success = false;
	}
	return success;
}

Vector2D Projectile::Calculate(float timeStep)
{
	Vector2D vec;

	return vec;
}

void Projectile::Update(float timeStep)
{
	if (!m_Active)
	{

		Vector2D force = Calculate(timeStep);

		force.Truncate(MaxForce);
		this->m_Accel = &force;

		this->m_Velocity->operator+=(m_Accel->operator*(timeStep));

		this->m_Velocity->Truncate(MaxSpeed);
		

		if (this->m_Source->distance(*m_Position) > m_Range)
		{

		}
	}
}
void Projectile::Render(SDL_Renderer* renderer)
{

}

void Projectile::setActive(bool active)
{
	m_Active = active;
}

void Projectile::setRange(int range)
{
	m_Range = range;
}

Vector2D Projectile::PredictPosition(Point2D* targetPos, float targetSpeed, Vector2D* targetVel)
{
	Vector2D toTarget = targetPos->operator-=(*this->m_Position);

	float lookAhead = toTarget.Length() / (this->MaxSpeed + targetSpeed);

	return targetVel->operator*(lookAhead)+*targetPos;
}

Vector2D Projectile::PredictPosition(Minion* target)
{
	Vector2D toTarget = target->GetPosition()->operator-=(*this->m_Position);

	float lookAhead = toTarget.Length() / (this->MaxSpeed + target->MaxSpeed);

	return target->GetVelocity()->operator*(lookAhead)+*target->GetPosition();
}
