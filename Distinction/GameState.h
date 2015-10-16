#pragma once
#include "Game.h"

class GameState
{
public:
	virtual void Initialise() = 0;
	virtual void HandleInput(Game* game, SDL_Event event) = 0;
	virtual void Update(Game* game) = 0;
	virtual void Render(Game* game, SDL_Surface* surface, SDL_Window* window) = 0;
protected:
	GameState() {}
};


