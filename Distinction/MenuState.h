#pragma once
#include "GameState.h"
#include <vector>


class MenuState :
	public GameState
{
public:
	//game loop
	void Initialise(SDL_Renderer* r);
	void HandleInput(Game* game, SDL_Event event, SDL_Renderer* r);
	void Update(Game* game);
	void Render(Game* game, SDL_Surface* surface, SDL_Window* window, SDL_Renderer* r);

	//load the interface
	//add buttons
	bool LoadMedia(SDL_Renderer* r);
	bool loadFromFile(std::string path);
	void addButton(LButton* b);
	//singleton
	static MenuState* Instance(){
		return &m_MenuState;
	}


	

protected:
	MenuState() {}

private:
	static MenuState m_MenuState;
	SDL_Surface* m_BackgroundPNG;
	LTexture* m_Background;

	std::vector<LButton*> m_Buttons;
};