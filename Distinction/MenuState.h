#pragma once
#include "GameState.h"
#include "StateButton.h"

class MenuState :
	public GameState
{
public:
	//game loop
	void Initialise();
	void HandleInput(Game* game, SDL_Event event);
	void Update(Game* game);
	void Render(Game* game, SDL_Surface* surface, SDL_Window* window);

	//load the interface
	//add buttons
	bool LoadMedia();
	void AddButton(std::string type);
	
	//singleton
	static MenuState* Instance(){
		return &m_MenuState;
	}

	

protected:
	MenuState() {}

private:
	static MenuState m_MenuState;
	SDL_Surface* m_BackgroundPNG;
	SDL_Surface* m_PlayButton;
	std::vector<LButton*> m_Buttons;
};