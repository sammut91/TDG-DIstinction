#pragma once
class WaveController
{
public:
	WaveController();
	~WaveController();

	float CalculateSpawnDelay();

private:
	int m_WaveNumber = 1;
	float m_SpawnDelay;
	int m_WaveSize = 0;
	int m_WaveLength; 
};

