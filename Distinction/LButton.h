#pragma once
#include <SDL.h>
#include "Game.h"

class LButton
{
public:
	LButton();
	
	//sets the top left position
	void setPosition(int x, int y);
	void setSize(int width, int height);
	//handles the events for the mouse
	void handleEvent(SDL_Event* event);

	void render();

	bool loadMedia();

private:
	SDL_Point m_Position;
	//sprite for button
	SDL_Surface* m_Sprite;
	int m_Width = 0, m_Height = 0;
};

