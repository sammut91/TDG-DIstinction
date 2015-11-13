#include "Score.h"


Score::Score()
{
}


Score::~Score()
{
}

void Score::SetScore(int score)
{
	m_Score = score;
}

void Score::IncreaseScore()
{
	m_Score++;
}

void Score::IncreaseScore(int amount)
{
	m_Score += amount;
}

