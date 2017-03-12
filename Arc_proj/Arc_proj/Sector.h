#pragma once
struct Sector {

public: void ChangeSize(double rad, double ang);
		double Area();
		double ArcLen();
		double CircleLen();
		double CircleD();

		double radius;
		double angle;

};