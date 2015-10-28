#pragma once
#include "Path.h"
#include "GameObject.h"
class Minion :
	public GameObject
{
public:
	Minion();
	~Minion();

	Minion(int xPos, int yPos);
	Minion(int xPos, int yPos, SDL_Renderer* renderer);

	int GetHeight(){ return m_Height; }
	int GetWidth(){ return m_Width; }

	void setPosition(int x, int y);
	void setSize(int x, int y);
	void setVelocity(float xVel, float yVel);
	void setAcceleration(float xAcc, float yAcc);
	
	//controlling the minions
	virtual void Update();
	virtual void Update(float timeStep);
	virtual void HandleInput(SDL_Event* event);
	virtual void Render();
	virtual void Render(SDL_Renderer* r);

	virtual bool Initialise();
	//init with renderer
	virtual bool Initialise(SDL_Renderer* renderer);


	//path control
	virtual void AddPath(Path* p);
	virtual Vector2D FollowPath();
	virtual bool AtDestination();
	virtual Path* GetPath(){
		return this->m_Path;
	}

	//checks for updating minions
	bool isAlive();

	//force calculations
	virtual Vector2D CalculateForce(float timeStep);
	virtual Vector2D Seek(Point2D* targetPos);

private:
	LTexture* m_Texture;
	Point2D* m_Position;
	int m_Height, m_Width;
	int m_Health;
	Vector2D* m_Velocity;
	Vector2D* m_Accel;
	Path* m_Path;
};

