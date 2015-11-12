#include "QuitState.h"

QuitState QuitState::m_QuitState;

static const int SCREEN_WIDTH = 1600;
static const int SCREEN_HEIGHT = 900;

void QuitState::HandleInput(Game* game, SDL_Event event, SDL_Renderer* r)
{
	if (event.type == SDL_QUIT)
	{
		game->Quit();
	}
	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		for each (LButton* button in m_Buttons)
		{
			button->handleEvent(&event, game, r);
		}
	}
}

void QuitState::Update(Game* game)
{

}

void QuitState::Render(Game* game, SDL_Surface* surface, SDL_Window* window, SDL_Renderer* r)
{
	SDL_Rect bGround = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	m_Background->render(0, 0, r, &bGround);
	SDL_FillRect(surface, NULL, 0xFDD7E4);
	for each (LButton* button in m_Buttons)
	{
		button->render(r);
	}

	SDL_RenderPresent(r);
}

void QuitState::Initialise(SDL_Renderer* r)
{
	int imfFlags = IMG_INIT_PNG;
	m_Background = new LTexture();
	addButton(new LButton("YesButton.bmp", r, "quit", 650,500));
	addButton(new LButton("NoButton.bmp", r, "back", 800,500));
	LoadMedia(r);

}

void QuitState::Initialise(SDL_Renderer* r, Game* game)
{
	int imfFlags = IMG_INIT_PNG;
	m_Background = new LTexture();
	addButton(new LButton("YesButton.png", r, "quit", 650, 500));
	addButton(new LButton("NoButton.png", r, "back", 800, 500));
	LoadMedia(r);
}

bool QuitState::LoadMedia(SDL_Renderer* r)
{
	bool success = true;
	if (!m_Background->loadFromFile("QuitScreen.png", r))
	{
		printf("Failed to load button sprite texture!\n");
		success = false;
	}

	return success;
}

void QuitState::addButton(LButton* b)
{
	m_Buttons.push_back(b);
}