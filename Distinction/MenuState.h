#pragma once
#include "GameState.h"
class MenuState :
	public GameState
{
public:
	//game loop
	void Initialise();
	void HandleInput(Game* game, SDL_Event event);
	void Update(Game* game);
	void Render(Game* game, SDL_Surface* surface, SDL_Window* window);

	//singleton
	static MenuState* Instance(){
		return &m_MenuState;
	}

protected:
	MenuState() {}

private:
	static MenuState m_MenuState;

};