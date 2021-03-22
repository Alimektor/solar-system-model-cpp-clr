#include "TBody.h"

TBody::TBody(Coordinate ^ coordinate, TBody ^center, Color color)
{
	m_current_coordinate = coordinate;
	m_center = center;
	m_radius = 0;
	m_rotation_speed = 0;
	m_size = 0;
	m_color = color;
	m_angle = 0;
}

TBody::TBody(Coordinate ^ coordinate, int size, Color color)
{
	m_size = size;
	m_radius = 0;
	m_rotation_speed = 0;
	m_color = color;
	m_center = gcnew TBody(coordinate, this, m_color); // mock object

	m_current_coordinate = gcnew Coordinate(
		coordinate->get_x() + m_radius,
		coordinate->get_y() + m_radius
	);

	m_angle = 0;
}

TBody::TBody(TBody ^center, int radius, float rotation_speed, int size, Color color)
{
	m_center = center;
	m_size = size;
	m_radius = radius + m_size;
	m_rotation_speed = rotation_speed;
	m_color = color;
	m_angle = 0;
	int x = (int) cos(m_angle) * m_radius;
	int y = (int) sin(m_angle) * m_radius;
	m_current_coordinate = gcnew Coordinate(
		m_center->get_current_coordinate()->get_x() + x,
		m_center->get_current_coordinate()->get_y() + y
	);
}

void TBody::add_new_satellite(TBody^ sattelite)
{
	m_satellite_list.push_back(sattelite);
}

Coordinate^ TBody::get_current_coordinate()
{
	return m_current_coordinate;
}

void TBody::draw(Graphics^ graphics)
{
	int size = m_size * m_size_coefficient;
	graphics->FillEllipse(gcnew SolidBrush(m_color),
		m_current_coordinate->get_x() - size / 2,
		m_current_coordinate->get_y() - size / 2,
		size,
		size);

	for each (TBody^ body in m_satellite_list)
	{
		body->draw(graphics);
	}
}

int TBody::get_size()
{
	return m_size;
}

void TBody::rotate()
{

	m_angle += m_rotation_speed * 0.17;

	int x = (int) cos(m_angle) * m_radius * m_radius_coefficient;
	int y = (int) sin(m_angle) * m_radius * m_radius_coefficient;
	m_current_coordinate = gcnew Coordinate(
		m_center->get_current_coordinate()->get_x() + x,
		m_center->get_current_coordinate()->get_y() + y
	);

	for each (TBody^ body in m_satellite_list)
	{
		body->rotate();
	}
}

void TBody::change_size(int coefficient)
{
	m_size_coefficient = coefficient;

	for each (TBody^ body in m_satellite_list)
	{
		body->change_size(coefficient);
	}
}

void TBody::change_radius(int coefficient)
{
	m_radius_coefficient = coefficient;

	for each (TBody^ body in m_satellite_list)
	{
		body->change_radius(coefficient);
	}
}
