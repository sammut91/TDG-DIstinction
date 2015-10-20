#pragma once
#include "LButton.h"
#include "PlayState.h"
#include "MenuState.h"

class StateButton :
	public LButton
{
public:
	StateButton(std::string state);

	//sets the top left position
	void setPosition(int x, int y);
	void setSize(int width, int height);
	//handles the events for the mouse
	void handleEvent(SDL_Event* event, Game* game);

	void render(SDL_Renderer* renderer, SDL_Rect rect);
	bool loadMedia();
	void SetImage(SDL_Texture* texture);
	SDL_Texture* GetImage(){ return m_Image; }
	SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
	
private:
	SDL_Point m_Position;

	//string for id
	std::string m_StateType;

	//sprite for button
	//SDL_Surface* m_Sprite;
	SDL_Texture* m_Image;
	int m_Width = 0, m_Height = 0;
};

