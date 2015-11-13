#pragma once
class Score
{
public:
	Score();
	~Score();

	int GetScore(){ return m_Score; }
	void SetScore(int score);

	int GetValue(){ return m_Value; }
	void SetValue(int value);

	void IncreaseValue();
	void IncreaseValue(int amount);


	void IncreaseScore();
	void IncreaseScore(int amount);

private:
	int m_Score;
	int m_Value;
};

