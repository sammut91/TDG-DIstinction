#include "TowerFactory.h"


TowerFactory::TowerFactory()
{
}


TowerFactory::~TowerFactory()
{
}

Tower* TowerFactory::createTower(std::string type, SDL_Renderer* renderer)
{
	return new Tower(renderer);
}

void TowerFactory::cleanup()
{

}