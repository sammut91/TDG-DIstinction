/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Game.h"
#include "MenuState.h"
//Screen dimension constants
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;


int main(int argc, char* args[])
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	Game game;
	game.m_TimerDisplay.start();
	//game.m_Timer.start();
	//event handler
	SDL_Event event;

	//initialise the timer


	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			SDL_Renderer* m_Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (m_Renderer == NULL)
			{
				printf("Failed to load Renderer");
			}
			game.SetRenderer(m_Renderer);
			if (!game.LoadMedia())
			{
				printf("Failed to load media");
			}
			if (TTF_Init() == -1)
			{
				printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
			}
			else
			{
				game.Initialise();
				game.ChangeState(MenuState::Instance(),m_Renderer);

				//Get window surface
				screenSurface = SDL_GetWindowSurface(window);

				//Fill the surface white
				//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

				while (game.Running())
				{
					
					while (SDL_PollEvent(&event) != 0)
					{
						game.HandleInput(event,m_Renderer);
					}
					//check of the game is paused or not
					if (!game.isPaused()) 
					{
						game.Update();
					}		
					game.m_Timer.start();
					game.Render(screenSurface,window,m_Renderer);					
				}
			}

		}
	}

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}