#include "TowerFactory.h"


TowerFactory::TowerFactory()
{
}


TowerFactory::~TowerFactory()
{
}

Tower* TowerFactory::createTower(std::string type, SDL_Renderer* renderer, float timeStep)
{
	return new Tower(renderer,timeStep);
}

void TowerFactory::cleanup()
{

}