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
	void Update();
	void Render(SDL_Renderer* r);
	bool Initialise();

private:
	LTexture* m_Texture;
	SDL_Point* m_Position;
	int m_Height, m_Width;
};

