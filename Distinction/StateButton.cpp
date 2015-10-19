#include "StateButton.h"


StateButton::StateButton(std::string state)
{
	m_StateType = state;
	m_Position.x = 0;
	m_Position.y = 0;
}


void StateButton::setSize(int height, int width)
{
	m_Height = height;
	m_Width = width;
}

void StateButton::setPosition(int x, int y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void StateButton::render()
{
	SDL_Rect renderQuad = { m_Position.x, m_Position.y, m_Width, m_Height };
	if (m_Sprite != NULL)
	{

	}
}

void StateButton::handleEvent(SDL_Event* event, Game* game)
{
	//If mouse event happened
	if (event->type == SDL_MOUSEMOTION || event->type == SDL_MOUSEBUTTONDOWN || event->type == SDL_MOUSEBUTTONUP)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if (x < m_Position.x)
		{
			inside = false;
		}
		//Mouse is right of the button
		else if (x > m_Position.x + m_Width)
		{
			inside = false;
		}
		//Mouse above the button
		else if (y < m_Position.y)
		{
			inside = false;
		}
		//Mouse below the button
		else if (y > m_Position.y + m_Height)
		{
			inside = false;
		}
		//Mouse is inside button
		else
		{
			//Handle what the button does here
			switch (event->type)
			{
			case SDL_MOUSEBUTTONDOWN:
				if (m_StateType == "play")
				{
					game->PushState(PlayState::Instance());
					break;
				}
				if (m_StateType == "about")
				{
					break;
				}
				if (m_StateType == "menu")
				{
					game->PopState();
				}
				break;
			default:
				break;
			}
		}
	}
}

bool StateButton::loadMedia()
{
	bool success = true;
	if (m_StateType != "")
	{
		if (m_StateType == "play")
		{
			bool success = true;
			m_Sprite = SDL_LoadBMP("PlayButton.bmp");
			if (m_Sprite == NULL)
			{
				printf("IMG_Load: %s\n", SDL_GetError());
				return false;
			}
		}
	}
	return success;
}
