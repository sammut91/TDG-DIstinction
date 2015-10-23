#include "PlayState.h"
#include <SDL_image.h>
//#include "boost\numeric\ublas\vector.hpp"
//using namespace boost::numeric::ublas;

PlayState PlayState::m_PlayState;

static const int SCREEN_WIDTH = 1600;
static const int SCREEN_HEIGHT = 900;

void PlayState::HandleInput(Game* game, SDL_Event event, SDL_Renderer* r)
{
	if (event.type == SDL_QUIT)
	{
		game->Quit();
	}
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_b:
			game->PopState();
			printf("Back to the menu");
			break;
		case SDLK_ESCAPE:
			game->Quit();
			break;
		}
	}
}

void PlayState::Update(Game* game)
{
	//vector<float f, float f2>
}

void PlayState::Render(Game* game, SDL_Surface* surface, SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_FillRect(surface, NULL, 0x0066FF);
	SDL_UpdateWindowSurface(window);
}

void PlayState::Initialise(SDL_Renderer* r)
{

}

bool PlayState::LoadMedia(SDL_Renderer* r)
{
	bool success = true;
	return success;
}