#include "Path.h"


Path::Path()
{
	m_CurrentPtIndex = 0;
}


Path::~Path()
{
}

void Path::createRandomPath(int numberOfPoints, bool looped)
{
	clear();
	m_NumberOfPoints = numberOfPoints;
	m_Looped = looped;
	int randX = 0;
	int randY = 0;
	for (int i = 0; i < numberOfPoints; i++)
	{
		randY = rand() % 70;
		randX = rand() % 100;
		m_Points.push_back(new Point2D(100.0+ 5*randX, 100.0+5*randY));
	}
}

void Path::createPath(bool looped)
{
	clear();
	m_Looped = looped;

	m_Points.push_back(new Point2D(100, 100));
	m_Points.push_back(new Point2D(100, 600));
	m_Points.push_back(new Point2D(500, 600));
	m_Points.push_back(new Point2D(500, 200));
	m_Points.push_back(new Point2D(900, 200));
	m_Points.push_back(new Point2D(900, 600));
	m_Points.push_back(new Point2D(1300, 600));
	m_Points.push_back(new Point2D(1300, 200));

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
	if (m_CurrentPtIndex == m_Points.size()-1)
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

Point2D* Path::getDestination()
{
	if (!m_Points.empty())
	{
		return m_Points.back();
	}
}

void Path::clear()
{
	if (!m_Points.empty())
	{
		m_Points.clear();
	}
}

void Path::Render(SDL_Renderer* renderer)
{
	if (!m_Points.empty())
	{
		if (m_Points.size() > 1)
		{
			for (int i = 0; i < m_Points.size(); i++)
			{
				if (m_Points[i] != m_Points.back())
				{
					SDL_RenderDrawLine(renderer, m_Points[i]->x, m_Points[i]->y, m_Points[i + 1]->x, m_Points[i + 1]->y);
				}
				
			}
			
		}
	}
}
