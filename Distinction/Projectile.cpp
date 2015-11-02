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

Vector2D* Projectile::Calculate()
{
	Vector2D* vec = new Vector2D();

	return vec;
}

void Projectile::Update()
{
	if (!m_Active)
	{
		Calculate();
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
