#include "MenuState.h"
#include "PlayState.h"
#include <SDL_image.h>

MenuState MenuState::m_MenuState;

static const int SCREEN_WIDTH = 1600;
static const int SCREEN_HEIGHT = 900;

void MenuState::HandleInput(Game* game, SDL_Event event, SDL_Renderer* r)
{
	if (event.type == SDL_QUIT)
	{
		game->Quit();
	}
	if (event.type == SDL_KEYDOWN)
	{
		std::stringstream timeText;
		switch (event.key.keysym.sym)
		{
		case SDLK_p:
			game->PushState(PlayState::Instance(),r);
			printf("Time to play");
			break;
		case SDLK_t:
			
			timeText.str("");
			timeText << (game->m_Timer.getTicks() / 1000.f);
			std::cout << timeText.str() << std::endl;
			break;
		case SDLK_ESCAPE:
			game->Quit();
			break;
		}
	}
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		for each (LButton* button in m_Buttons)
		{
			button->handleEvent(&event, game, r);
		}
	}
}

void MenuState::Update(Game* game)
{

}

void MenuState::Render(Game* game, SDL_Surface* surface, SDL_Window* window, SDL_Renderer* r)
{
	SDL_Rect bGround = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };	
	m_Background->render(0, 0,r,&bGround);
	SDL_FillRect(surface, NULL, 0xFDD7E4);
	for each (LButton* button in m_Buttons)
	{
		button->render(r);
	}
	//surface = m_BackgroundPNG; 
	//SDL_BlitSurface(m_BackgroundPNG, NULL, surface, NULL);
	//SDL_UpdateWindowSurface(window);
	SDL_RenderPresent(r);
	
}

void MenuState::Initialise(SDL_Renderer* r)
{
	int imfFlags = IMG_INIT_PNG;
	m_Background = new LTexture();
	addButton(new LButton("PlayButton.bmp", r, "play",200,500));
	addButton(new LButton("HelpButton.bmp", r, "help",800,500));
	LoadMedia(r);

}

void MenuState::Initialise(SDL_Renderer* r, Game* game)
{
	int imfFlags = IMG_INIT_PNG;
	m_Background = new LTexture();
	addButton(new LButton("PlayButton.bmp", r, "play", 200, 500));
	addButton(new LButton("HelpButton.bmp", r, "help", 800, 500));
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

void MenuState::addButton(LButton* b)
{
	m_Buttons.push_back(b);
}



