#pragma once
class Damage
{
public:
	Damage();
	~Damage();

	int GetDamage(){ return m_Damage; }
	void SetDamage(int damage);

	void IncreaseDamage();
	void IncreaseDamage(int amount);

	void DecreaseDamage();
	void DecreaseDamage(int amount);

	//deal the damage 
	//change this to incorporate the ability to damage minions
	void DealDamage();

private:
	int m_Damage;
};

