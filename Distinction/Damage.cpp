#include "Damage.h"


Damage::Damage()
{
}


Damage::~Damage()
{
}

void Damage::SetDamage(int damage)
{
	m_Damage = damage;
}

void Damage::IncreaseDamage()
{
	m_Damage++;
}

void Damage::IncreaseDamage(int amount)
{
	m_Damage += amount;
}

void Damage::DecreaseDamage()
{
	m_Damage--;
}

void Damage::DecreaseDamage(int amount)
{
	m_Damage -= amount;
}
