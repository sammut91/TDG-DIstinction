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

	if (event.type == SDL_MOUSEMOTION)
	{
		Uint32 mouse = SDL_GetMouseState(&mouseXPos, &mouseYPos);

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
		case SDLK_p:
			game->Pause();
			break;
		case SDLK_ESCAPE:
			game->Quit();
		case SDLK_t:
			timeText.str("");
			timeText << (game->m_Timer.getTicks() / 1000.f);
			std::cout << timeText.str() << std::endl;
			break;
		case SDLK_a:
			game->AddTower(game->GetTowerFactory()->createTower("", r, (game->m_TimerDisplay.getTicks() / 1000.f)));
		}
	}
	if (event.type == SDL_KEYUP)
	{

	}

	if (event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (!game->m_Towers.empty())
		{
			for each (Tower* t in game->m_Towers)
			{
				if (t->isBeingPlaced() && t->isSelected())
				{
					t->setPlaced(true);
					t->setBeingPlaced(false);
					t->setSelected(false);
				}
			}
		}
	}
}

void PlayState::Update(Game* game)
{
	UpdateTime(game);
	float time = (abs(30 - (game->m_TimerDisplay.getTicks() / 1000.0f)));
	if (game->HasSpawned(time))
	{
		game->AddMinion(game->GetSpawner()->createMinion("Heavy", game->GetRenderer(), game->GetPath()));
	}

	//update the minions
	if (!game->GetMinions().empty())
	{
		for (int i = 0; i < game->GetMinions().size(); i++)
		{
			game->GetMinions()[i]->Update(game->GetTimeStep());
			if (game->GetMinions()[i]->AtDestination() && game->GetMinions()[i]->GetPath()->isFinished())
			{
				game->m_Minions.erase(game->m_Minions.begin() + i);
			}
		}
	}

	//update the towers
	if (!game->m_Towers.empty())
	{
		for each (Tower* tower in game->m_Towers)
		{
			if (tower->isBeingPlaced())
			{
				tower->Update(mouseXPos-25, mouseYPos-25);
			}
			else
			{
				tower->Update();
			}

			if (tower->isPlaced())
			{
				//update the projectiles
				if (!tower->isLoaded())
				{
					tower->AddProjectiles(game->GetRenderer());
				}
				tower->getTarget(game->GetMinions());
				if (!tower->GetProjectiles().empty())
				{
					for each (Projectile* p in tower->GetProjectiles())
					{
						p->Update(game->GetTimeStep());
					}
				}
			}
		}
	}
}

void PlayState::Render(Game* game, SDL_Surface* surface, SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_Color textColor = { 0, 0, 0 };
	SDL_Rect bGround = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	m_Background->render(0, 0, renderer, &bGround);
	SDL_FillRect(surface, NULL, 0x0066FF);
	//SDL_UpdateWindowSurface(window);

	if (!game->GetMinions().empty())
	{
		for each (Minion* m in game->GetMinions())
		{
			m->Render(renderer);
		}
	}
	if (game->GetPath() != NULL)
	{
		//game->GetPath()->Render(renderer);
	}

	if (!m_TimeDisplay->loadFromRenderedText(m_Time.str(), textColor, renderer, game->getFont()))
	{
		printf("Failed to render text texture!\n");
	}
	if (m_TimeDisplay != NULL)
	{
		m_TimeDisplay->render(800, 870, renderer);
	}

	if (!game->m_Towers.empty())
	{
		for each (Tower* tower in game->m_Towers)
		{
			tower->Render(renderer);
			if (!tower->GetProjectiles().empty())
			{
				for each (Projectile* projectile in tower->GetProjectiles())
				{
					if (projectile->isActive())
					{
						projectile->Render(renderer);
					}					
				}
			}
		}
	}

	SDL_RenderPresent(renderer);
}

void PlayState::Initialise(SDL_Renderer* r, Game* game)
{
	SDL_RenderClear(r);
	m_Background = new LTexture();
	m_TimeDisplay = new LTexture();
	LoadMedia(r);
}


void PlayState::Initialise(SDL_Renderer* r)
{
	SDL_RenderClear(r);
	m_Path = new Path();
	m_Path->createPath(false);
	m_Background = new LTexture();
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

void PlayState::UpdateTime(Game* game)
{
	if ((game->m_TimerDisplay.getTicks() / 1000.f) > 30.0)
	{
		game->m_TimerDisplay.start();
		//add a wave incrementer here (in game), pass it into the minion factory have
		//have it increase the health or spawn types
	}
	m_Time.str("");
	float time = abs(31-(game->m_TimerDisplay.getTicks() / 1000.f));
	m_Time << time;
}