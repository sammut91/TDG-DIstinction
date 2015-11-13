#pragma once
class Score
{
public:
	Score();
	~Score();

	int GetScore(){ return m_Score; }
	void SetScore(int score);

	void IncreaseScore();
	void IncreaseScore(int amount);

private:
	int m_Score;
};

