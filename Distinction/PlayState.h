#pragma once
#include "GameState.h"
#include "Path.h" 
#include "QuitState.h"
#include "Base.h"
#include "HeavyMinion.h"
#include "GameOverState.h"

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

	void RenderText(LTexture* texture, Game* game, SDL_Color colour, std::string text, int xPos, int yPos);

	bool LoadMedia(SDL_Renderer* r);
	void UpdateTime(Game* game);
	void addButton(LButton* b);
	//singleton
	static PlayState* Instance(){
		return &m_PlayState;
	}

protected:
	PlayState() {}

private:
	static PlayState m_PlayState;
	std::vector<LButton*> m_Buttons;
	LTexture* m_Background;
	Path* m_Path;
	LTexture* m_TimeDisplay;
	LTexture* m_Score;
	LTexture* m_Currency;
	LTexture* m_Wave;
	int m_WaveNumber = 1;
	std::stringstream m_Time, m_WaveText;
	int mouseXPos = 0;
	int mouseYPos = 0;	
	bool m_PlacingTower = false;

	Base* m_Base;
};