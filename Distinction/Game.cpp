#include "Game.h"
#include "GameState.h"


Game::Game()
{
}


Game::~Game()
{
}

void Game::Initialise()
{
	m_running = true;
	m_Path = new Path();
	m_Path->createPath(false);
	m_Spawner = new MinionFactory();
	m_TowerFactory = new TowerFactory();
	LoadMedia();

}

void Game::HandleInput(SDL_Event event, SDL_Renderer* r)
{
	m_states.back()->HandleInput(this, event,r);
}

void Game::Update()
{
	m_states.back()->Update(this);
}

void Game::Render(SDL_Surface* surface, SDL_Window* window, SDL_Renderer* renderer)
{
	m_states.back()->Render(this,surface, window,renderer);
}

void Game::PushState(GameState* state, SDL_Renderer* r)
{
	m_states.push_back(state);
	m_states.back()->Initialise(r,this);
}

//pop the last state that was used and push the state that is passed to ChangeState onto the back
void Game::ChangeState(GameState* state, SDL_Renderer* r)
{
	if (!m_states.empty())
	{
		m_states.pop_back();
	}
	m_states.push_back(state);
	m_states.back()->Initialise(r,this);
}

//if the state vector isn't empty pop the last state from the back.
void Game::PopState()
{
	if (!m_states.empty())
	{
		m_states.pop_back();
	}
}

void Game::Pause()
{
	if (m_Paused == true)
	{
		m_Paused = false;
	}
	else
		m_Paused = true;
}


bool Game::LoadMedia()
{
	bool success = true;

	//load media files here
	m_Font = TTF_OpenFont("AlexandriaFLF.ttf", 25);
	if (m_Font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}

	return success;
}

float Game::GetTimeStep()
{
	float timeStep = 0.0;
	timeStep = m_Timer.getTicks() / 1000.0;
	return timeStep;
}

float Game::GetTimeDisplayStep()
{
	float timeStep = 0.0;
	timeStep = (m_Timer.getTicks() / 1000.0);
	return timeStep;
}

void Game::AddMinion(Minion* m)
{
	if (m != NULL)
	{
		m_Minions.push_back(m);
	}
}

void Game::AddTower(Tower* t)
{
	if (t != NULL)
	{
		m_Towers.push_back(t);
	}
}

std::vector<Minion*> Game::SpawnWave(int minionAmount)
{
	std::vector<Minion*> wave;
	for (int i = 0; i < minionAmount; i++)
	{
		wave.push_back(m_Spawner->createMinion("Heavy", m_Renderer, GetPath()));
	}	
	return wave;
}


//finish the math behind spawning at intervals of 1 or 2 seconds
void Game::SpawnMinion(std::vector<Minion*> wave)
{
	for (int i = 0; i < wave.size(); i++)
	{

	}
}

bool Game::HasSpawned(float timeStep)
{
	bool spawned = false;
	//upper and lower limit of spawning 
	if (!(timeStep <= 5.0 || timeStep >= 25.0))
	{
		//if (!((m_SpawnTimer - timeStep) > m_SpawnDelay))
		if (!((m_SpawnTimer - timeStep) > CalculateSpawnDelay()))
		{
			return spawned = false;
		}
		m_SpawnTimer = timeStep;
		//if (m_SpawnTimer < m_SpawnDelay)
		if (m_SpawnTimer < CalculateSpawnDelay())

		{
			m_SpawnTimer = timeStep;
		}
		return spawned = true;
	}
	else if (timeStep <=5.0)
	{
		m_SpawnTimer = 30.0;
	}
	return spawned;
	
}

void Game::SetSpawnDelay(float spawnDelay)
{
	m_SpawnDelay = spawnDelay;
}

Path* Game::GetPath()
{
	Path* p = new Path(*m_Path);
	return p;
}

void Game::SetRenderer(SDL_Renderer* r)
{
	m_Renderer = r;
}

void Game::DecreaseSpawnDelay(float amount)
{
	m_SpawnDelay -= amount;
}

void Game::AddMinion(Game* game)
{
	int xRan;
	srand(time(0)); // This will ensure a really randomized number by help of time.

	xRan = rand() % 20 + 1; // Randomizing the number between 1-15.
	switch (xRan)
	{
	case 1: case 2: case 3: case 4: case 5:
		m_Minions.push_back(game->GetSpawner()->createMinion("Fast", game->GetRenderer(), game->GetPath()));
		break;
	case 6: case 7: case 8: case 9:
		m_Minions.push_back(game->GetSpawner()->createMinion("Heavy", game->GetRenderer(), game->GetPath()));
		break;
	case 10:
		m_Minions.push_back(game->GetSpawner()->createMinion("Boss", game->GetRenderer(), game->GetPath()));
		break;
	default:
		m_Minions.push_back(game->GetSpawner()->createMinion("Average", game->GetRenderer(), game->GetPath()));
		break;
	}
}


