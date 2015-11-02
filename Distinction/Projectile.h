#pragma once
#include "LTexture.h"
#include "Vector2D.h"

class Projectile
{
public:
	Projectile();
	Projectile(int xPos, int yPos, SDL_Renderer* renderer);
	Projectile(int xPos, int yPos, SDL_Renderer* renderer, int range);
	~Projectile();

	void Update();
	void Render(SDL_Renderer* renderer);

	//initialisers
	bool Initialise(SDL_Renderer* renderer, int range);
	bool Initialise(SDL_Renderer* renderer);

	//check whether the bullet is active or not
	bool isActive(){ return m_Active; }
	void setActive(bool active);

	//calculate force only if bullet is not active
	Vector2D* Calculate();

	//range
	int Range(){ return m_Range; }
	void setRange(int range);

private:
	bool m_Active;
	int m_Range;
	Point2D* m_Position;
	Vector2D* m_Velocity;
	Vector2D* m_Accel;
	LTexture* m_Texture;
};

