#pragma once
class Health
{
public:
	Health();
	~Health();

	//checks if the objects health is greater than 0
	bool IsAlive();

	void IncreaseHealth();
	void IncreaseHealth(int amount);

	void DecreaseHealth();
	void DecreaseHealth(int amount);

	void SetHealth(int health);
	int GetHealth(){ return m_Health; }

private:
	int m_Health;
};

