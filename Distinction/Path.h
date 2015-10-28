#pragma once
#include <vector>
#include "Vector2D.h"
#include <random>
#include <SDL.h>
class Path
{
public:
	Path();
	~Path();

	void createPath(int numberOfPoints, bool looped);
	Point2D* currentPoint();
	
	bool isFinished();
	void incrementPoint();
	Point2D* getDestination();
	std::vector<Point2D*> getPoints() {
		return m_Points;
	}

	void addWaypoint(Point2D* point);
	void clear();

	void Render(SDL_Renderer* renderer);

private:
	bool m_Looped = false;
	int m_NumberOfPoints;
	int m_CurrentPtIndex;
	std::vector<Point2D*> m_Points;

};

