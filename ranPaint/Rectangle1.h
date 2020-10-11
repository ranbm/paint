#pragma once
//
//  Rectangle.cpp
//  HM1_204296792
//
//  Created by ran ben melech on 25/05/2020.
//  Copyright © 2020 ran ben melech. All rights reserved.
//

#include "pch.h"
#include "Segment.h"
class Rectangle1 : public Segment
{
public:
	DECLARE_SERIAL(Rectangle1);
	Rectangle1(void);
	~Rectangle1(void);
	void DrawShape(CDC* dc);
	bool isInside(CPoint mouse);
	
};