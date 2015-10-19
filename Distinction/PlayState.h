#pragma once
#include "GameState.h"

class PlayState :
	public GameState
{
public:
	//game loop
	void Initialise();
	void HandleInput(Game* game, SDL_Event event);
	void Update(Game* game);
	void Render(Game* game, SDL_Surface* surface, SDL_Window* window);

	bool LoadMedia();

	//singleton
	static PlayState* Instance(){
		return &m_PlayState;
	}

protected:
	PlayState() {}

private:
	static PlayState m_PlayState;

};