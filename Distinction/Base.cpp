#include "Base.h"


Base::Base()
{
	m_Texture = new LTexture();
	m_Position = new Point2D(1240, 540);
	SetHealth(200);
}

Base::Base(SDL_Renderer* r)
{
	m_Texture = new LTexture();
	m_HealthBar = new LTexture();
	m_HealthBarBorder = new LTexture();
	m_Position = new Point2D(1100, 480);
	SetHealth(2);
	Initialise(r);
}


Base::~Base()
{
}

void Base::HandleInput(SDL_Event* event)
{

}

void Base::Update()
{
	//update the health bar to display minion damage
	if (GetHealth() > 0)
	{
		m_HealthBar->setWidth(GetHealth());
	}
	
}


void Base::Render(SDL_Renderer* r)
{
	m_Texture->render(m_Position->x, m_Position->y, r);
	m_HealthBarBorder->render(m_Position->x + 25, m_Position->y + m_Texture->getHeight()+5, r);
	m_HealthBar->render(m_Position->x + 25, m_Position->y + m_Texture->getHeight()+5, r);

}

bool Base::Initialise(SDL_Renderer* r)
{
	bool success = true;
	if (!this->m_Texture->loadFromFile("base.png", r))
	{
		printf("Failed to load minion sprite texture!\n");
		success = false;
	}
	if (!this->m_HealthBar->loadFromFile("healthBar.png", r))
	{
		printf("Failed to load minion sprite texture!\n");
		success = false;
	}

	if (!this->m_HealthBarBorder->loadFromFile("healthBarBorder.png", r))
	{
		printf("Failed to load minion sprite texture!\n");
		success = false;
	}

	return success;
}

