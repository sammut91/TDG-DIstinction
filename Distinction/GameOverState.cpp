#include "GameOverState.h"

GameOverState GameOverState::m_GameOverState;

static const int SCREEN_WIDTH = 1600;
static const int SCREEN_HEIGHT = 900;

void GameOverState::HandleInput(Game* game, SDL_Event event, SDL_Renderer* r)
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

void GameOverState::Update(Game* game)
{

}

void GameOverState::Render(Game* game, SDL_Surface* surface, SDL_Window* window, SDL_Renderer* r)
{
	SDL_Color textColor = { 1,1,1};
	SDL_Rect bGround = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	m_Background->render(0, 0, r, &bGround);
	SDL_FillRect(surface, NULL, 0xFDD7E4);
	for each (LButton* button in m_Buttons)
	{
		button->render(r);
	}

	RenderText(m_HighScore, game, textColor, game->m_HighScoreText.str(), 800, 410);

	SDL_RenderPresent(r);
}

void GameOverState::Initialise(SDL_Renderer* r)
{
	int imfFlags = IMG_INIT_PNG;
	m_Background = new LTexture();
	m_HighScore = new LTexture();
	addButton(new LButton("MenuButton.png", r, "menu", 650, 500));
	LoadMedia(r);

}

void GameOverState::Initialise(SDL_Renderer* r, Game* game)
{
	int imfFlags = IMG_INIT_PNG;
	m_Background = new LTexture();
	m_HighScore = new LTexture();
	addButton(new LButton("MenuButton.png", r, "menu", 650, 500));
	LoadMedia(r);
}

bool GameOverState::LoadMedia(SDL_Renderer* r)
{
	bool success = true;
	if (!m_Background->loadFromFile("GameOverScreen.png", r))
	{
		printf("Failed to load button sprite texture!\n");
		success = false;
	}

	return success;
}

void GameOverState::addButton(LButton* b)
{
	m_Buttons.push_back(b);
}

void GameOverState::RenderText(LTexture* texture, Game* game, SDL_Color color, std::string text, int xPos, int yPos)
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