#include "MenuState.h"
#include "PlayState.h"
#include <SDL_image.h>


MenuState MenuState::m_MenuState;

void MenuState::HandleInput(Game* game, SDL_Event event)
{
	if (event.type == SDL_QUIT)
	{
		game->Quit();
	}
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_p:
			game->PushState(PlayState::Instance());
			printf("Time to play");
			break;
		case SDLK_ESCAPE:
			game->Quit();
			break;
		}
	}
}

void MenuState::Update(Game* game)
{

}

void MenuState::Render(Game* game, SDL_Surface* surface, SDL_Window* window)
{
	SDL_FillRect(surface, NULL, 0xFDD7E4);
	//surface = m_BackgroundPNG; 
	SDL_BlitSurface(m_BackgroundPNG, NULL, surface, NULL);
	if (m_Buttons.size() != 0)
	{
		for each (LButton* button in m_Buttons)
		{
			m_PlayButton = button->render();
		}
	}
	SDL_UpdateWindowSurface(window);
	
}

void MenuState::Initialise()
{
	int imfFlags = IMG_INIT_PNG;
	AddButton("play");
	LoadMedia();

}

bool MenuState::LoadMedia()
{
	bool success = true;
	m_BackgroundPNG = SDL_LoadBMP("MenuScreen.bmp");
	if (m_BackgroundPNG == NULL)
	{
		printf("IMG_Load: %s\n", SDL_GetError());
		return false;
	}

	for each (LButton* button in m_Buttons)
	{
		if (button->loadMedia())
		{
			button->setPosition(200, 600);
			button->setSize(200, 100);
		}
	}
	return success;
}

void MenuState::AddButton(std::string type)
{
	if (type != "")
	{
		if (type == "menu" || type == "play")
		{
			m_Buttons.push_back(new StateButton(type));
		}
	}
}

