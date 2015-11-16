#pragma once
class WaveController
{
public:
	WaveController();
	~WaveController();

	float CalculateSpawnDelay();

	int WaveNumber(){ return m_WaveNumber; }
	float SpawnDelay(){ return CalculateSpawnDelay(); }

	void IncreaseWaveNumber();
	void IncreaseWaveSize();
	void IncreaseWaveSize(int amount);
	void IncreaseWaveDifficultyHealth();
	void IncreaseWaveDifficultyDamage();

	int GetHeavyHealth = 5, GetFastHealth = 2, GetAverageHealth = 3, GetBossHealth = 100;
	int GetHeavyDamage = 5, GetFastDamage = 2, GetAverageDamage = 3, GetBossDamage = 75;

private:
	int m_WaveNumber = 1;
	float m_SpawnDelay;
	int m_WaveSize = 15;
	float m_WaveLength = 20.0; 

	
};

