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
	m_states.back()->Initialise(r);
}

//pop the last state that was used and push the state that is passed to ChangeState onto the back
void Game::ChangeState(GameState* state, SDL_Renderer* r)
{
	if (!m_states.empty())
	{
		m_states.pop_back();
	}
	m_states.push_back(state);
	m_states.back()->Initialise(r);
}

//if the state vector isn't empty pop the last state from the back.
void Game::PopState()
{
	if (!m_states.empty())
	{
		m_states.pop_back();
	}
}


bool Game::LoadMedia()
{
	bool success = true;

	//load media files here
	Vector2D *loc = new Vector2D();

	return success;
}
