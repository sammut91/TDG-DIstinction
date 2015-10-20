#pragma once
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "LTexture.h"
#include "LButton.h"
#include <sstream>
#include <iostream>

class GameState
{
public:
	virtual void Initialise(SDL_Renderer* r) = 0;
	virtual void HandleInput(Game* game, SDL_Event event, SDL_Renderer* r) = 0;
	virtual void Update(Game* game) = 0;
	virtual void Render(Game* game, SDL_Surface* surface, SDL_Window* window, SDL_Renderer* renderer) = 0;
	virtual bool LoadMedia(SDL_Renderer* r) = 0;
protected:
	GameState() {}
};


