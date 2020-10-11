#pragma once
//
//  Circle.h
//  HM1_204296792
//
//  Created by ran ben melech on 25/05/2020.
//  Copyright © 2020 ran ben melech. All rights reserved.

#ifndef Circle_h
#define Circle_h
#include "Ellipse1.h"
class Circle : public Ellipse1
{
public:
    DECLARE_SERIAL(Circle);
    Circle(void);
    ~Circle(void);
    void DrawShape(CDC* dc);
    bool isInside(CPoint point);
    double getRadius();

};
#endif

