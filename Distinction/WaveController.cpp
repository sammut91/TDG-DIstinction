#include "WaveController.h"


WaveController::WaveController()
{
}


WaveController::~WaveController()
{
}

float WaveController::CalculateSpawnDelay()
{
	m_SpawnDelay = m_WaveLength / m_WaveSize;
	return m_SpawnDelay;
}

void WaveController::IncreaseWaveNumber()
{
	m_WaveNumber++;
}

void WaveController::IncreaseWaveSize()
{
	m_WaveSize++;
}

void WaveController::IncreaseWaveSize(int amount)
{
	m_WaveSize += amount;
}