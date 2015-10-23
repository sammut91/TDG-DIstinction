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
	Tower();

	Tower(std::string towerType);
	~Tower();
	//SDL Draw and update
	void Update();
	void Render();

	//tower target aquisition
	void getTarget();
	bool hasTarget();
	void fire();

	//upgrade the tower
	void upgrade();

	//load the tower sprite and initialisation features
	bool Initialise(std::string objType);

	//checks for the clicks or placements of towers
	bool isSelected();
	bool isBeingPlaced();
	bool isPlaced();


private:
	//member values for each tower
	float m_Cost= 0, m_Range =0;
	std::string objType;
	std::vector<SDL_Surface*> m_Sprites;
};

