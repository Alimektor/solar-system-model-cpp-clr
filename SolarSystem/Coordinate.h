#pragma once

ref struct Coordinate
{
private:
	int m_x;
	int m_y;
public:
	Coordinate();
	Coordinate(int x, int y);
	int get_x();
	int get_y();
};