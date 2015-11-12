#pragma once
#include "GameState.h"
class QuitState :
	public GameState
{
public:
	//game loop
	void Initialise(SDL_Renderer* r);
	void Initialise(SDL_Renderer* r, Game* game);
	void HandleInput(Game* game, SDL_Event event, SDL_Renderer* r);
	void Update(Game* game);
	void Render(Game* game, SDL_Surface* surface, SDL_Window* window, SDL_Renderer* r);

	//load the interface
	//add buttons
	bool LoadMedia(SDL_Renderer* r);
	bool loadFromFile(std::string path);
	void addButton(LButton* b);
	//singleton
	static QuitState* Instance(){
		return &m_QuitState;
	}




protected:
	QuitState() {}

private:
	static QuitState m_QuitState;
	SDL_Surface* m_BackgroundPNG;
	LTexture* m_Background;

	std::vector<LButton*> m_Buttons;
};
