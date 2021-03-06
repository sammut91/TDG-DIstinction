#include "LButton.h"
#include "MenuState.h"
#include "PlayState.h"
#include "HelpState.h"

LButton::LButton(std::string path, SDL_Renderer* r, std::string type, int xPos, int yPos)
{
	setPosition(xPos, yPos);
	m_Type = type;
	m_Texture = new LTexture();
	m_Texture->loadFromFile(path.c_str(), r);
	setSize(m_Texture->getHeight(), m_Texture->getWidth());

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
					break;
				}
				else if (m_Type == "quit")
				{
					game->Quit();
					break;
				}
				else if (m_Type == "back")
				{
					game->PopState();
					break;
				}
				else if (m_Type == "help")
				{
					game->PushState(HelpState::Instance(), r);
					break;
				}
				else if (m_Type == "menu")
				{
					game->ChangeState(MenuState::Instance(), r);
					break;
				}
				else if (m_Type == "addBomb")
				{
					if (game->m_Currency >= 150)
					{
						game->AddTower(game->GetTowerFactory()->createTower("", r, (game->m_TimerDisplay.getTicks() / 1000.f)));
						game->m_Currency -= game->m_Towers.back()->GetCost();
					}
					break;
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