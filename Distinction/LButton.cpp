#include "LButton.h"
#include "Game.h"
#include "PlayState.h"

LButton::LButton(std::string path, SDL_Renderer* r, std::string type, int xPos, int yPos)
{
	setPosition(xPos, yPos);
	setSize(200, 400);
	m_Type = type;
	m_Texture = new LTexture();
	m_Texture->loadFromFile(path.c_str(), r);

}

void LButton::setPosition(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}

void LButton::setSize(int height, int width)
{
	m_Height = height;
	m_Width = width;
}

void LButton::handleEvent(SDL_Event* e, Game* game, SDL_Renderer* r)
{
	//If mouse event happened
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if (x < mPosition.x)
		{
			inside = false;
		}
		//Mouse is right of the button
		else if (x > mPosition.x +m_Width)
		{
			inside = false;
		}
		//Mouse above the button
		else if (y < mPosition.y)
		{
			inside = false;
		}
		//Mouse below the button
		else if (y > mPosition.y + m_Height)
		{
			inside = false;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch (e->type)
			{
			case SDL_MOUSEBUTTONDOWN:
				if (m_Type == "play")
				{
					game->PushState(PlayState::Instance(), r);
				}
				break;
			}
		}
	}
}

void LButton::render(SDL_Renderer* r)
{
	//Show current button sprite
	m_Texture->render(mPosition.x, mPosition.y,r);
}