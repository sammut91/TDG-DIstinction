#include "Path.h"


Path::Path()
{
	m_CurrentPtIndex = 0;
}


Path::~Path()
{
}

void Path::createPath(int numberOfPoints, bool looped)
{
	m_NumberOfPoints = numberOfPoints;
	m_Looped = looped;
	for (int i = 0; i < numberOfPoints; i++)
	{
		m_Points.push_back(new Point2D(50 * i + i + 120.0, 90 * i + i + 120.0));
	}


}

Point2D* Path::currentPoint()
{
	if (!m_Points.empty())
	{
		return m_Points.at(m_CurrentPtIndex);
	}
}

bool Path::isFinished()
{
	if (m_CurrentPtIndex == m_Points.size())
	{
		return true;
	}
	return false;
}

void Path::incrementPoint()
{
	if (!m_Points.empty())
	{
		m_CurrentPtIndex += 1;
		if (isFinished())
		{
			m_CurrentPtIndex = m_Points.size()-1;
		}			
	}
}

void Path::addWaypoint(Point2D* p)
{

}

void Path::clear()
{
	if (!m_Points.empty())
	{
		m_Points.clear();
	}
}
