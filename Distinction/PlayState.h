#pragma once
#include "GameState.h"
#include "Path.h" 
#include "HeavyMinion.h"

class PlayState :
	public GameState
{
public:
	//game loop
	void Initialise(SDL_Renderer* r);
	//init with game
	void Initialise(SDL_Renderer* r, Game* game);
	void HandleInput(Game* game, SDL_Event event, SDL_Renderer* r);
	void Update(Game* game);
	void Update(Game* game, SDL_Renderer* renderer);
	void Render(Game* game, SDL_Surface* surface, SDL_Window* window, SDL_Renderer* renderer);

	bool LoadMedia(SDL_Renderer* r);
	void UpdateTime(Game* game);
	//singleton
	static PlayState* Instance(){
		return &m_PlayState;
	}

protected:
	PlayState() {}

private:
	static PlayState m_PlayState;
	LTexture* m_Background;
	Path* m_Path;
	LTexture* m_TimeDisplay;
	std::stringstream m_Time;
	int mouseXPos = 0;
	int mouseYPos = 0;
	
};