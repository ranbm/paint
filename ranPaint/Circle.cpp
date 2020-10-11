//
//  Circle.cpp
//  HM1_204296792
//
//  Created by ran ben melech on 25/05/2020.
//  Copyright © 2020 ran ben melech. All rights reserved.
//

#include <iomanip>
#include "pch.h"
#include "Circle.h"
IMPLEMENT_SERIAL(Circle, CObject, 1);
Circle::Circle()
{}
Circle::~Circle()
{}

void Circle::DrawShape(CDC* dc)
{
	double rad = getRadius();
	if (WhichPoint())
		dc->Ellipse(getStartP().x, getStartP().y, getStartP().x + rad * 2, rad * 2 + getStartP().y);
	else
	{
		dc->Ellipse(getEndP().x, getEndP().y, getEndP().x + rad * 2, rad * 2 + getEndP().y);
	}
}
bool Circle::isInside(CPoint point)
{
	CPoint mid = getMiddle();
	double r = getRadius();
	r *= r;
	int  x = point.x;

	x-=mid.x;
	x *= x;
	int y = point.y;
	y -= mid.y;
	y *= y;
	if (x + y < r)
	{
		return (true);
	}
	else
	{
		return (false);
	}
}
double Circle::getRadius()
{
	CPoint mid = getMiddle();
	bool r = WhichPoint();
	double radius = 0;
	radius = sqrt((((getStartP().x- mid.x) * (getStartP().x-mid.x ))) + ((getStartP().y-mid.y) * (getStartP().y-mid.y)));
	return (radius);
}