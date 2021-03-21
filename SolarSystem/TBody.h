#pragma once
#include "Coordinate.h"
#include <cliext/vector>
using namespace System::Drawing;



ref class TBody
{
protected:
	Coordinate^ m_current_coordinate;
	TBody^ m_center;
	int m_radius;
	cliext::vector<TBody^> m_satellite_list;
	double m_rotation_speed;
	int m_size;
	Color m_color;
	double m_angle;
	int m_size_ñoefficient = 1;
	int m_radius_ñoefficient = 1;
public:
	TBody::TBody(Coordinate ^ coordinate, TBody ^center, Color color);
	TBody(Coordinate^ coordinate, int size, Color color);
	TBody::TBody(TBody ^center, int radius, float rotation_speed, int size, Color color);
	void add_new_satellite(TBody^ sattelite);
	Coordinate^ get_current_coordinate();
	int get_size();
	void draw(Graphics^ graphics);
	void rotate();
	void change_size(int ñoefficient);
	void change_radius(int ñoefficient);
};

