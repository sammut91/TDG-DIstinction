#pragma once
#include <vector>
#include "Vector2D.h"
class Path
{
public:
	Path();
	~Path();

	void createPath(int numberOfPoints, bool looped);
	Vector2D* currentPoint();
	
	bool isFinished();
	void incrementPoint();

	std::vector<Vector2D*> getPoints() {
		return m_Points;
	}

	void addWaypoint(Point2D* point);
	void clear();

private:
	bool m_Looped;
	int m_NumberOfPoints;
	int m_CurrentPtIndex;
	std::vector<Vector2D*> m_Points;

};

