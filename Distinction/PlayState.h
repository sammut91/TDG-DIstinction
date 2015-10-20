#pragma once
#include "GameState.h"

class PlayState :
	public GameState
{
public:
	//game loop
	void Initialise(SDL_Renderer* r);
	void HandleInput(Game* game, SDL_Event event, SDL_Renderer* r);
	void Update(Game* game);
	void Render(Game* game, SDL_Surface* surface, SDL_Window* window, SDL_Renderer* renderer);

	bool LoadMedia(SDL_Renderer* r);

	//singleton
	static PlayState* Instance(){
		return &m_PlayState;
	}

protected:
	PlayState() {}

private:
	static PlayState m_PlayState;

};