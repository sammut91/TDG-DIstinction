#include "HelpState.h"

HelpState HelpState::m_HelpState;

static const int SCREEN_WIDTH = 1600;
static const int SCREEN_HEIGHT = 900;

void HelpState::HandleInput(Game* game, SDL_Event event, SDL_Renderer* r)
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
		case SDLK_b:
			game->PopState();
			printf("Back to the menu");
			break;
		case SDLK_ESCAPE:
			game->PopState();
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

void HelpState::Update(Game* game)
{

}

void HelpState::Render(Game* game, SDL_Surface* surface, SDL_Window* window, SDL_Renderer* r)
{
	SDL_Color textColor = { 1, 1, 1 };
	SDL_Rect bGround = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	m_Background->render(0, 0, r, &bGround);
	SDL_FillRect(surface, NULL, 0xFDD7E4);
	for each (LButton* button in m_Buttons)
	{
		button->render(r);
	}
	SDL_RenderPresent(r);
}

void HelpState::Initialise(SDL_Renderer* r)
{
	int imfFlags = IMG_INIT_PNG;
	m_Background = new LTexture();
	addButton(new LButton("xButton.png", r, "back", 1508, 25));
	LoadMedia(r);

}

void HelpState::Initialise(SDL_Renderer* r, Game* game)
{
	int imfFlags = IMG_INIT_PNG;
	m_Background = new LTexture();
	addButton(new LButton("xButton.png", r, "back", 1508, 25));
	LoadMedia(r);
}

bool HelpState::LoadMedia(SDL_Renderer* r)
{
	bool success = true;
	if (!m_Background->loadFromFile("HelpScreen.png", r))
	{
		printf("Failed to load button sprite texture!\n");
		success = false;
	}

	return success;
}

void HelpState::addButton(LButton* b)
{
	m_Buttons.push_back(b);
}

void HelpState::RenderText(LTexture* texture, Game* game, SDL_Color color, std::string text, int xPos, int yPos)
{
	if (!texture->loadFromRenderedText(text, color, game->GetRenderer(), game->getFont()))
	{
		printf("Failed to render text texture!\n");
	}
	if (texture != NULL)
	{
		texture->render(xPos, yPos, game->GetRenderer());
	}
}