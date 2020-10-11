#pragma once
//
//  Segment.h
//  HM1_204296792
//
//  Created by ran ben melech on 25/05/2020.
//  Copyright © 2020 ran ben melech. All rights reserved.
//

#ifndef Segment_h
#define Segment_h
#include "Figure2D.h"
class Segment : public Figure2D
{
public:
	DECLARE_SERIAL(Segment);
	Segment(void);
	~Segment(void);
	void DrawShape(CDC* dc);
	bool isInside(CPoint);
};
#endif /* Segment_h */