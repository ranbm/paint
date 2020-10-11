#include "Ellipse1.h"
#include "pch.h"
IMPLEMENT_SERIAL(Ellipse1, CObject, 1);
Ellipse1::Ellipse1()
{}
Ellipse1::~Ellipse1()
{}
CPoint Ellipse1::getMiddle()
{
	double x = ((getStartP().x + getEndP().x) / 2);
	double y = ((getStartP().y + getEndP().y) / 2);
	return (CPoint(x, y));
}
void Ellipse1::DrawShape(CDC* dc)
{
	dc->Ellipse(getStartP().x, getStartP().y, getEndP().x, getEndP().y);
}
bool Ellipse1::isInside(CPoint point)
{
	CPoint mid = getMiddle();
	bool whichPoint = WhichPoint();
	double BigRad = 0;
	double smallRad = 0;
	if (whichPoint)
	{
		if (getEndP().x - getStartP().x > getEndP().y - getStartP().y)
		{
			BigRad = abs(getEndP().x - mid.x);
			smallRad = abs(getEndP().y - mid.y);
		}
		else
		{
			smallRad = abs(getEndP().x - mid.x);
			BigRad = abs(getEndP().y - mid.y);
		}
		if (((point.x < BigRad + mid.x) && (point.x > mid.x - BigRad)) && ((point.y < smallRad + mid.y) && (point.y > mid.y - smallRad)))
		{
			return true;
		}
		else {
			return false;
		}
	}
	else
	{
		if (getStartP().x - getEndP().x > getStartP().y - getEndP().y)
		{
			double BigRad = getStartP().x - mid.x;
			double smallRad = getStartP().y - mid.y;
		}
		else
		{
			double smallRad = getStartP().x - mid.x;
			double BigRad = getStartP().y - mid.y;
		}
		if (((point.x < BigRad + mid.x) && (point.x > mid.x - BigRad)) && ((point.y < smallRad + mid.y) && (point.y > mid.y - smallRad)))
		{
			return true;
		}
		else {
			return false;
		}
	}
}


