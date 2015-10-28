#pragma once
#include "Minion.h"

class HeavyMinion :
	public Minion
{
public:
	HeavyMinion();
	~HeavyMinion();
	
	HeavyMinion(int xPos, int yPos);

	//Update and rendering for Heavy Minion
	void Update(float timeStep);
	void Render(SDL_Renderer* r);	

	//path
	void AddPath(Path* p);
	bool AtDestination();
	Path* GetPath() {
		return this->m_Path;
	}

	//calculations
	Vector2D CalculateForce(float timeStep);
	Vector2D Seek(Point2D* targetPos);
	Vector2D FollowPath();

	bool Initialise(SDL_Renderer* renderer);
	bool Initialise();

private:
	LTexture* m_Texture;
	Point2D* m_Position;
	int m_Height, m_Width;
	int m_Health;
	Vector2D* m_Velocity;
	Vector2D* m_Accel;
	Path* m_Path;
};
