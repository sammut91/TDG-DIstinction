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


private:
	int m_Damage;
};

