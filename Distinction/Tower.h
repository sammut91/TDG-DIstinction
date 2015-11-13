/*
The Tower class
- contians a sprite that it refers to 
- is able to be upgraded 
- fires at a target using a certain projectile
*/

#pragma once
#include "GameObject.h"
#include <SDL.h>
#include "Cost.h"
#include <vector>
#include "Projectile.h"

class Tower :
	public GameObject, public Cost
{
public:
	Tower(SDL_Renderer* renderer);
	Tower(SDL_Renderer* renderer, float timer);
	Tower(std::string towerType, float xPos, float yPos, SDL_Renderer* renderer);
	Tower(std::string towerType, float xPos, float yPos,SDL_Renderer* renderer, float timer);
	~Tower();

	//SDL Draw and update
	void Update();
	void Update(int mouseX, int mouseY);
	void HandleInput(SDL_Event* event);
	void Render();
	void Render(SDL_Renderer* r);

	//tower target aquisition
	void getTarget(std::vector<Minion*> &targets);
	Minion* gTarget(std::vector<Minion*> targets);
	bool hasTarget = false;
	void fire(float timeStep, float fireTimeStep, std::vector<Minion*> &targets);
	bool hasFired(float timeStep);
	std::vector<Projectile*> GetProjectiles(){ return m_Projectiles; }
	void AddProjectiles(SDL_Renderer* renderer);
	bool isLoaded(){ return loadAmmo; }

	//upgrade the tower
	void upgrade();

	//load the tower sprite and initialisation features
	bool Initialise();
	//init with renderer
	bool Initialise(SDL_Renderer* renderer);
	int ClipSize = 5;
	//checks for the clicks or placements of towers
	bool isSelected() { return m_Selected; };
	bool isBeingPlaced(){ return m_BeingPlaced; };
	bool isPlaced(){ return m_Placed; };

	void setSelected(bool selected);
	void setBeingPlaced(bool beingPlaced);
	void setPlaced(bool placed);

	//position of tower
	void SetPosition(int xPos, int yPos);

	//get and set the range and cost
	float Range(){ return m_Range; }
	void SetRange(float range);
	float FireRate(){ return m_FireRate; }

	float m_FireTimer = 31.0;
private:
	//member values for each tower
	float m_Range = 300.0, m_FireRate = 0.25;
	//ammo clip
	std::vector<Projectile*> m_Projectiles;
	std::string objType;
	Point2D* m_Position;
	bool m_BeingPlaced;
	bool m_Selected;
	bool m_Placed;
	bool loadAmmo = false;
	LTexture* m_Texture;
};

