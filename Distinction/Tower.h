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

	Tower(std::string towerType, float xPos, float yPos);
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

	//upgrade the tower
	void upgrade();

	//load the tower sprite and initialisation features
	bool Initialise();
	bool Initialise(std::string objType);
	//init with renderer
	bool Initialise(std::string objType, SDL_Renderer* renderer);

	//checks for the clicks or placements of towers
	bool isSelected();	
	bool isBeingPlaced();
	bool isPlaced();

	void setSelected(bool selected);
	void setBeingPlaced(bool beingPlaced);
	void setPlaced(bool placed);

	//position of tower
	void SetPosition(int xPos, int yPos);

private:
	//member values for each tower
	float m_Cost= 0, m_Range =0;
	std::string objType;
	Point2D* m_Position;
	bool m_BeingPlaced;
	bool m_Selected;
	bool m_Placed;
	LTexture* m_Texture;
};

