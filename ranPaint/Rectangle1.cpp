//
//  Rectangle.cpp
//  HM1_204296792
//
//  Created by ran ben melech on 25/05/2020.
//  Copyright © 2020 ran ben melech. All rights reserved.
//

#include "Rectangle1.h"
#include "pch.h"
#include "Figure2D.h"
IMPLEMENT_SERIAL(Rectangle1, CObject, 1);
Rectangle1::Rectangle1()
{}
Rectangle1::~Rectangle1()
{}
void Rectangle1::DrawShape(CDC* dc)
{
	CPoint start = getStartP();
	CPoint end = getEndP();
	dc->Rectangle(start.x, start.y, end.x, end.y);
}

bool Rectangle1::isInside(CPoint mouse)
{
	CPoint start = getStartP();
	CPoint end = getEndP();
	bool whichPoint = WhichPoint();
	if (whichPoint)
	{
		if ((mouse.x<end.x && mouse.x>start.x) && (mouse.y<end.y && mouse.y>start.y))
			return true;
		else
			return false;
	}
	else
	{
		if ((mouse.x<start.x && mouse.x>end.x) && (mouse.y<start.y && mouse.y>end.y))
			return true;
		else
			return false;
	}
}