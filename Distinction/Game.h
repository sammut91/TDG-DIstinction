#pragma once
#include <SDL.h>
#include <vector>
#include "Vector2D.h"
#include "GameObjectFactory.h"


class GameState;

class Game
{
public:
	Game();
	~Game();

	//game loop
	void Initialise();
	void HandleInput(SDL_Event event);
	void Update();
	void Render(SDL_Surface* surface, SDL_Window* window);

	bool Running(){
		return m_running;
	}
	void Quit(){
		m_running = false;
	}

	//media contol load all media here
	bool LoadMedia();

	//state management
	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

private:
	bool m_running = true;
	GameObjectFactory* m_GameObjectFactory ;
	std::vector<GameState*> m_states;
	
};

