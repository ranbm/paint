//
//  Square.cpp
//  HM1_204296792
//
//  Created by ran ben melech on 25/05/2020.
//  Copyright © 2020 ran ben melech. All rights reserved.
//

#include "Square.h"
#include "pch.h"
IMPLEMENT_SERIAL(Square, CObject, 1);
Square::Square()
{}
Square::~Square()
{}
void Square::DrawShape(CDC* dc)
{
	double xLen, yLen;
	CPoint start = getStartP();
	CPoint end = getEndP();
	xLen = (end.x - start.x);
	yLen = (start.y - end.y);
	int midX = ((start.x + end.x) / 2);
	int midY = ((start.y + end.y) / 2);
	CPoint mid = (midX,midY);
	if (abs(yLen) > abs(xLen))
	{
		if (WhichPoint())
		{
			dc->Rectangle(start.x, start.y, start.x +xLen, start.y + xLen);
		}
		else
		{
			dc->Rectangle(start.x, start.y, start.x - xLen, start.y - xLen);
		}
	}
	else
	{
		if (WhichPoint())
		{
			dc->Rectangle(start.x, start.y, start.x + yLen, start.y + yLen);
		}
		else
		{
			dc->Rectangle(start.x, start.y, start.x - yLen, start.y - yLen);
		}
	}
	


}
bool Square::isInside(CPoint mouse)
{
	if (WhichPoint())
	{
		if (mouse.x > getStartP().x && mouse.x < getEndP().x)
		{
			if (mouse.y > getStartP().y && mouse.y < getEndP().y)
				return true;
			return false;
		}
		else
		{
			return false;
		}

	}
	else
	{
		if (mouse.x < getStartP().x && mouse.x >getEndP().x)
		{
			if (mouse.y < getStartP().y && mouse.y > getEndP().y)
				return true;
			return false;
		}
		else
		{
			return false;
		}
	}
}