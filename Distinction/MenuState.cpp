#include "MenuState.h"
#include "PlayState.h"
#include <SDL_image.h>


MenuState MenuState::m_MenuState;

void MenuState::HandleInput(Game* game, SDL_Event event, SDL_Renderer* r)
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
			game->PushState(PlayState::Instance(),r);
			printf("Time to play");
			break;
		case SDLK_ESCAPE:
			game->Quit();
			break;
		}
	}
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		m_PlayButton->handleEvent(&event, game, r);
	}
}

void MenuState::Update(Game* game)
{

}

void MenuState::Render(Game* game, SDL_Surface* surface, SDL_Window* window, SDL_Renderer* r)
{
	SDL_Rect bGround = { 0, 0, 1600, 900 };	
	m_Background->render(0, 0,r,&bGround);
	SDL_FillRect(surface, NULL, 0xFDD7E4);
	m_PlayButton->render(r);
	//surface = m_BackgroundPNG; 
	//SDL_BlitSurface(m_BackgroundPNG, NULL, surface, NULL);
	//SDL_UpdateWindowSurface(window);
	SDL_RenderPresent(r);
	
}

void MenuState::Initialise(SDL_Renderer* r)
{
	int imfFlags = IMG_INIT_PNG;
	m_Background = new LTexture();
	m_PlayButton = new LButton("PlayButton.bmp", r, "play");
	m_PlayButton->setPosition(200, 500);
	LoadMedia(r);

}

bool MenuState::LoadMedia(SDL_Renderer* r)
{
	bool success = true;
	if (!m_Background->loadFromFile("MenuScreen.bmp", r))
	{
		printf("Failed to load button sprite texture!\n");
		success = false;
	}

	return success;
}



