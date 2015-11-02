#pragma once
#include "LTexture.h"
#include "Vector2D.h"
#include "Minion.h"

class Projectile
{
public:
	Projectile();
	Projectile(int xPos, int yPos, SDL_Renderer* renderer);
	Projectile(int xPos, int yPos, SDL_Renderer* renderer, int range);
	~Projectile();

	void Update(float timeStep);
	void Render(SDL_Renderer* renderer);

	//initialisers
	bool Initialise(SDL_Renderer* renderer, int range);
	bool Initialise(SDL_Renderer* renderer);

	//check whether the bullet is active or not
	bool isActive(){ return m_Active; }
	void setActive(bool active);

	//calculate force only if bullet is not active
	float MaxForce =300.0, MaxSpeed = 300.0;
	Vector2D Calculate(float timeStep);
	Vector2D PredictPosition(Point2D* targetPos, float targetSpeed, Vector2D* targetVel);
	Vector2D PredictPosition(Minion* target);

	//range
	int Range(){ return m_Range; }
	void setRange(int range);

private:
	bool m_Active;
	int m_Range;
	Point2D* m_Position;
	Point2D* m_Source;
	Vector2D* m_Velocity;
	Vector2D* m_Accel;
	LTexture* m_Texture;
};

