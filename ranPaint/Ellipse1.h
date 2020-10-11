#pragma once
#ifndef Ellipse1_h
#define Ellipse1_h
#include "Figure2D.h"
#include "pch.h"
class Ellipse1 :public Figure2D
{
public:
	DECLARE_SERIAL(Ellipse1);
	Ellipse1(void);
	~Ellipse1(void);
	void DrawShape(CDC* dc);
	bool isInside(CPoint point);
	CPoint getMiddle();
};
#endif