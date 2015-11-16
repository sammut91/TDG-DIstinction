#pragma once
#include "Minion.h"
class AverageMinion :
	public Minion
{
public:
	AverageMinion();
	~AverageMinion();
	AverageMinion(int xPos, int yPos);
	AverageMinion(int xPos, int yPos, SDL_Renderer* renderer, Path* p);

	//Update and rendering for Heavy Minion
	void Update(float timeStep);
	void Render(SDL_Renderer* r);

	//path
	void AddPath(Path* p);
	bool AtDestination();
	Path* GetPath() {
		return m_Path;
	}

	Point2D* GetPosition(){ return this->m_Position; }

	//calculations
	float MaxForce = 150.0, MaxSpeed = 150.0;
	Vector2D CalculateForce(float timeStep);
	Vector2D Seek(Point2D* targetPos);
	Vector2D FollowPath();

	bool Initialise(SDL_Renderer* renderer);
	bool Initialise();

	Health Health;

private:
	LTexture* m_Texture;
	Point2D* m_Position;
	int m_Height, m_Width;
	int m_Health;
	Vector2D* m_Velocity;
	Vector2D* m_Accel;
	Path* m_Path;
};
