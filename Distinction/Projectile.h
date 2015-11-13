#pragma once
#include "LTexture.h"
#include "Vector2D.h"
#include "Minion.h"
#include "Damage.h"

class Projectile
{
public:
	Projectile();
	Projectile(int xPos, int yPos, SDL_Renderer* renderer);
	Projectile(int xPos, int yPos, SDL_Renderer* renderer, int range);
	~Projectile();

	void Update(float timeStep,std::vector<Minion*> &targets);
	void Render(SDL_Renderer* renderer);

	//initialisers
	bool Initialise(SDL_Renderer* renderer, int range);
	bool Initialise(SDL_Renderer* renderer);

	//check whether the bullet is active or not
	bool isActive(){ return m_Active; }
	void setActive(bool active);

	//calculate force only if bullet is not active
	float MaxForce =700.0, MaxSpeed = 700.0;
	Vector2D Calculate(float timeStep);
	void CalculateForce(float timeStep);
	Vector2D PredictPosition(Minion* target);

	//range
	int Range(){ return m_Range; }
	void setRange(int range);

	//target fucntions
	Minion* GetTarget(){ return m_Target; }
	void SetTarget(Minion* m);

private:
	bool m_Active = false;
	int m_Range;
	Point2D* m_Position;
	Point2D* m_Source;
	Vector2D* m_Velocity;
	Vector2D* m_Accel;
	Vector2D m_Force;
	LTexture* m_Texture;

	Minion* m_Target;
};

