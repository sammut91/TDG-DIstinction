#pragma once
#include "GameState.h"
class HelpState :
	public GameState
{
public:
	//game loop
	void Initialise(SDL_Renderer* r);
	void Initialise(SDL_Renderer* r, Game* game);
	void HandleInput(Game* game, SDL_Event event, SDL_Renderer* r);
	void Update(Game* game);
	void Render(Game* game, SDL_Surface* surface, SDL_Window* window, SDL_Renderer* r);
	void RenderText(LTexture* texture, Game* game, SDL_Color color, std::string text, int xPos, int yPos);

	//load the interface
	//add buttons
	bool LoadMedia(SDL_Renderer* r);
	bool loadFromFile(std::string path);
	void addButton(LButton* b);
	//singleton
	static HelpState* Instance(){
		return &m_HelpState;
	}

protected:
	HelpState() {}

private:
	static HelpState m_HelpState;
	SDL_Surface* m_BackgroundPNG;
	LTexture* m_Background;

	std::vector<LButton*> m_Buttons;
};

