/*
The Tower class
- contians a sprite that it refers to 
- is able to be upgraded 
- fires at a target using a certain projectile
*/

#pragma once
#include "GameObject.h"
#include <SDL.h>
#include <vector>

class Tower :
	public GameObject
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
	void getTarget();
	bool hasTarget();
	void fire();
	bool hasFired(float timeStep);

	//upgrade the tower
	void upgrade();

	//load the tower sprite and initialisation features
	bool Initialise();
	//init with renderer
	bool Initialise(SDL_Renderer* renderer);

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
	float Cost(){ return m_Cost; }
	void SetCost(float cost);
	float FireRate(){ return m_FireRate; }

	float m_FireTimer = 0.0;
private:
	//member values for each tower
	float m_Cost= 0.0, m_Range =0.0, m_FireRate = 0.0;
	std::string objType;
	Point2D* m_Position;
	bool m_BeingPlaced;
	bool m_Selected;
	bool m_Placed;
	LTexture* m_Texture;
};

