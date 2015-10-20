#pragma once
#include <string>
#include <SDL.h>
#include "LTexture.h"

class GameObject
{
public:
	//update the game object
	virtual void Update() = 0;

	//draw the game object onto the screen
	virtual void Render() = 0;
	
	//load the objects sprite
	virtual bool Initialise() = 0;
	
protected:
	GameObject() {}
};

