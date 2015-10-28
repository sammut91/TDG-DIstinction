#pragma once
#include <vector>
#include "Vector2D.h"
#include <random>
class Path
{
public:
	Path();
	~Path();

	void createPath(int numberOfPoints, bool looped);
	Point2D* currentPoint();
	
	bool isFinished();
	void incrementPoint();

	std::vector<Point2D*> getPoints() {
		return m_Points;
	}

	void addWaypoint(Point2D* point);
	void clear();

private:
	bool m_Looped = false;
	int m_NumberOfPoints;
	int m_CurrentPtIndex;
	std::vector<Point2D*> m_Points;

};

