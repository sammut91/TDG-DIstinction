#include "LButton.h"


LButton::LButton()
{
	m_Position.x = 0;
	m_Position.y = 0;


}

void LButton::setSize(int height, int width)
{
	m_Height = height;
	m_Width = width;
}

void LButton::setPosition(int x, int y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void LButton::handleEvent(SDL_Event* event)
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

				break;
			default:
				break;
			}
		}
	}
}

