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

	//running and pause controls
	bool Running(){ return m_running; }
	void Quit(){ m_running = false; }
	bool isPaused() { return m_Paused; }
	void Pause();

	TTF_Font* getFont(){ return m_Font; }

	//timing for the game
	Timer m_Timer;
	Timer m_TimerDisplay;

	//media contol load all media here
	bool LoadMedia();
	SDL_Renderer* GetRenderer(){ return m_Renderer;}
	void SetRenderer(SDL_Renderer* renderer);

	//state management
	void ChangeState(GameState* state, SDL_Renderer* r);
	void PushState(GameState* state, SDL_Renderer* r);
	void PopState();
	
	//getters
	std::vector<Minion*> GetMinions(){return m_Minions;}
	Path* GetPath();
	float GetTimeStep();
	float GetTimeDisplayStep();
	TowerFactory* GetTowerFactory(){ return m_TowerFactory; }
	MinionFactory* GetSpawner(){ return m_Spawner; }

	//wave control
	std::vector<Minion*> SpawnWave(int minionAmount);
	void SpawnMinion(std::vector<Minion*>);
	void AddMinion(Minion* m);
	bool HasSpawned(float timeStep);
	float SpawnDelay(){ return m_SpawnDelay; }
	void SetSpawnDelay(float spawnDelay);

	//tower control
	void AddTower(Tower* t);

	std::vector<Minion*> m_Minions;
	std::vector<Tower*> m_Towers;

	std::stringstream m_ScoreText, m_CurrencyText;
	float m_Score = 0.0;
	float m_Currency = 200.0;

private:
	bool m_running = true, m_Paused = false;
	std::vector<GameState*> m_states;
	
	Path* m_Path;
	TowerFactory* m_TowerFactory;
	MinionFactory* m_Spawner;
	TTF_Font* m_Font;
	SDL_Renderer* m_Renderer;
	
	float m_SpawnDelay= 1.0, m_SpawnTimer = 31.0;
	

};

