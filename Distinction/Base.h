#pragma once
#include "LTexture.h"
#include "Health.h"
#include "Vector2D.h"
class Base:
	public Health
{
public:
	Base();
	Base(SDL_Renderer* r);

	~Base();

	void Update();
	void HandleInput(SDL_Event* event);
	void Render(SDL_Renderer* r);

	bool Initialise(SDL_Renderer* r);

private:
	LTexture* m_Texture;
	LTexture* m_HealthBarBorder;

	LTexture* m_HealthBar;
	Point2D* m_Position;
};

