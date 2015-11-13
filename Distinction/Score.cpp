#include "Score.h"


Score::Score()
{
}


Score::~Score()
{
}


//set the score reward for killing the minions
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

//set the currency reward for killing the minions
void Score::SetValue(int value)
{
	m_Value = value;
}

void Score::IncreaseValue(int value)
{
	m_Value += value;
}


void Score::IncreaseValue()
{
	m_Value++;
}