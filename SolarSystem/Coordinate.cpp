#include "Coordinate.h"

Coordinate::Coordinate()
{
	m_x = 0;
	m_y = 0;
}

Coordinate::Coordinate(int x, int y)
{
	m_x = x;
	m_y = y;
}

int Coordinate::get_x()
{
	return m_x;
}

int Coordinate::get_y()
{
	return m_y;
}