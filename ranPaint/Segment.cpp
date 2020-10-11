//
//  Segment.cpp
//  HM1_204296792
//
//  Created by ran ben melech on 25/05/2020.
//  Copyright © 2020 ran ben melech. All rights reserved.
//

#include "Segment.h"
#include "pch.h"
IMPLEMENT_SERIAL(Segment, CObject, 1);
Segment::Segment() {}
Segment::~Segment() {}
void Segment::DrawShape(CDC* dc)
{
	bool whichP = WhichPoint();
	if (whichP)
	{
		dc->MoveTo(getStartP());
		dc->LineTo(getEndP());
	}
	else
	{
		dc->MoveTo(getEndP());
		dc->LineTo(getStartP());
	}
}
bool Segment::isInside(CPoint mouse)
{
	CPoint start = getStartP();
	CPoint end = getEndP();
	bool whichPoint = WhichPoint();
	if (whichPoint)
	{
		double acclivity = (end.y - start.y) / (end.x - start.x);
		if (mouse.y - start.y == acclivity * (mouse.x - start.x))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		double acclivity = (start.y - end.y) / (start.x - end.x+0.0000000000000001);
		if (mouse.y - start.y == acclivity * (mouse.x - start.x))
		{
			return true;
		}
		else
		{
			return false;
		}
	}


}

