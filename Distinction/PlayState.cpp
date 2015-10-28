#include "PlayState.h"
#include <SDL_image.h>


PlayState PlayState::m_PlayState;

static const int SCREEN_WIDTH = 1600;
static const int SCREEN_HEIGHT = 900;

void PlayState::HandleInput(Game* game, SDL_Event event, SDL_Renderer* r)
{
	if (event.type == SDL_QUIT)
	{
		game->Quit();
	}
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_b:
			game->PopState();
			printf("Back to the menu");
			break;
		case SDLK_ESCAPE:
			game->Quit();
			break;
		}

		if (!m_Minions.empty())
		{
			for each (Minion* m in m_Minions)
			{
				m->HandleInput(&event);
			}
		}
	}
	if (event.type == SDL_KEYUP)
	{
		if (!m_Minions.empty())
		{
			for each (Minion* m in m_Minions)
			{
				m->HandleInput(&event);
			}
		}
	}
}

void PlayState::Update(Game* game)
{
	if (!m_Minions.empty())
	{
		for (int i = 0; i < m_Minions.size(); i++)
		{
			m_Minions[i]->Update(game->GetTimeStep());
			if (m_Minions[i]->AtDestination() && m_Minions[i]->GetPath()->isFinished())
			{
				m_Minions.erase(m_Minions.begin() + i);
			}
		}
	}
}

void PlayState::Render(Game* game, SDL_Surface* surface, SDL_Window* window, SDL_Renderer* renderer)
{
	
	SDL_Rect bGround = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	m_Background->render(0, 0, renderer, &bGround);
	SDL_FillRect(surface, NULL, 0x0066FF);
	//SDL_UpdateWindowSurface(window);
	if (!m_Minions.empty())
	{
		for each (Minion* m in m_Minions)
		{
			m->Render(renderer);
		}
	}
	if (game->GetPath() != NULL)
	{
		game->GetPath()->Render(renderer);
	}

	SDL_RenderPresent(renderer);
}

void PlayState::Initialise(SDL_Renderer* r, Game* game)
{
	SDL_RenderClear(r);
	m_Background = new LTexture();
	AddMinion();
	for each (Minion* m in m_Minions)
	{
		m->Initialise(r);
		m->AddPath(game->GetPath());
	}
	LoadMedia(r);
}


void PlayState::Initialise(SDL_Renderer* r)
{
	SDL_RenderClear(r);
	m_Path = new Path();
	m_Path->createPath(false);
	m_Background = new LTexture();
	AddMinion();
	for each (Minion* m in m_Minions)
	{
		m->Initialise(r);
		m->AddPath(m_Path);
	}
	LoadMedia(r);
}

bool PlayState::LoadMedia(SDL_Renderer* r)
{
	bool success = true;
	if (!m_Background->loadFromFile("PlayScreen.bmp", r))
	{
		printf("Failed to load background sprite texture!\n");
		success = false;
	}
	return success;
}

void PlayState::AddMinion()
{
	m_Minions.push_back(new HeavyMinion());
}