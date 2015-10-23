#pragma once
#include "GameObject.h"
class Minion :
	public GameObject
{
public:
	Minion();
	~Minion();

	int GetHeight(){ return m_Height; }
	int GetWidth(){ return m_Width; }
	
	//controlling the minions
	void Update(float timeStep);
	void HandleInput(SDL_Event* event);
	void Render(SDL_Renderer* r);

	bool Initialise();

	//checks for updating minions
	bool isAlive();

private:
	LTexture* m_Texture;
	SDL_Point* m_Position;
	int m_Height, m_Width;
	float m_VelX, m_VelY;
	int m_Health;
};

