#include "stdafx.h"
#include "Sector.h"

void Sector::ChangeSize(double rad, double ang)
{
	radius = radius*rad;
	angle = ang*angle;
}

double Sector::Area()
{
	double sq = 3.14*radius*radius*angle / 360;
	return sq;
}

double Sector::ArcLen()
{
	double len = 3.14*radius*angle / 180;
	return len;
}

double Sector::CircleLen()
{
	double len = 2 * 3.14*radius;
	return len;
}

double Sector::CircleD()
{
	return 2 * radius;
}