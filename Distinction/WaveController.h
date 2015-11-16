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


private:
	int m_WaveNumber = 1;
	float m_SpawnDelay;
	int m_WaveSize = 15;
	float m_WaveLength = 20.0; 
};

