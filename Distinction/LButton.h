#pragma once
#include <SDL.h>
#include "LTexture.h"
#include "Game.h"

class LButton
{
public:
	//Initializes internal variables
	LButton(std::string path, SDL_Renderer* r, std::string type);

	//Sets top left position
	void setPosition(int x, int y);
	void setSize(int x, int y);
	//Handles mouse event
	void handleEvent(SDL_Event* e, Game* game, SDL_Renderer* r);

	//Shows button sprite
	void render(SDL_Renderer* r);
	LTexture* GetTexture(){ return m_Texture; }

private:
	//Top left position
	SDL_Point mPosition;
	int m_Height;
	int m_Width;
	std::string m_Type;

	LTexture* m_Texture;
};

