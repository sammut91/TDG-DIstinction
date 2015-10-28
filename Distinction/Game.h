#pragma once
#include <SDL.h>
#include <vector>
#include "Vector2D.h"
#include "Timer.h"
#include <sstream>
#include "Minion.h"
#include "MinionFactory.h"
#include "Tower.h"
#include "TowerFactory.h"
#include "Path.h"

class GameState;

class Game
{
public:
	Game();
	~Game();

	//game loop
	void Initialise();
	void HandleInput(SDL_Event event, SDL_Renderer* r);
	void Update();
	void Render(SDL_Surface* surface, SDL_Window* window, SDL_Renderer* renderer);

	bool Running(){
		return m_running;
	}
	void Quit(){
		m_running = false;
	}

	//timing for the game
	Timer m_Timer;

	//media contol load all media here
	bool LoadMedia();
	void SetRenderer(SDL_Renderer* renderer);

	//state management
	void ChangeState(GameState* state, SDL_Renderer* r);
	void PushState(GameState* state, SDL_Renderer* r);
	void PopState();
	
	//getters
	std::vector<Minion*> GetMinions(){return m_Minions;}
	Path* GetPath();
	float GetTimeStep();
	TowerFactory* GetTowerFactory(){ return m_TowerFactory; }
	MinionFactory* GetSpawner(){ return m_Spawner; }

	void AddMinion(Minion* m);

	std::vector<Minion*> m_Minions;
	std::vector<Tower*> m_Towers;

private:
	bool m_running = true;
	std::vector<GameState*> m_states;
	
	Path* m_Path;
	TowerFactory* m_TowerFactory;
	MinionFactory* m_Spawner;

};

