#pragma once
#include "LButton.h"
#include "PlayState.h"
#include "MenuState.h"

class StateButton :
	public LButton
{
public:
	StateButton(std::string state);

	//sets the top left position
	void setPosition(int x, int y);
	void setSize(int width, int height);
	//handles the events for the mouse
	void handleEvent(SDL_Event* event, Game* game);

	void render();

	bool loadMedia();
	
private:
	SDL_Point m_Position;

	//string for id
	std::string m_StateType;

	//sprite for button
	SDL_Surface* m_Sprite;
	int m_Width = 0, m_Height = 0;
};

