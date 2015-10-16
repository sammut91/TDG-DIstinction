#include "MenuState.h"
#include "PlayState.h"

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
	SDL_UpdateWindowSurface(window);
}

void MenuState::Initialise()
{

}

