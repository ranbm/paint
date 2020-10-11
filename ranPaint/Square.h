#pragma once
//
//  Square.h
//  HM1_204296792
//
//  Created by ran ben melech on 25/05/2020.
//  Copyright © 2020 ran ben melech. All rights reserved.
//

#ifndef Square_h
#define Square_h
#include "Circle.h"
class Square : public Circle
{
public:
    DECLARE_SERIAL(Square);
    Square(void);
    ~Square(void);
    void DrawShape(CDC* dc);
    bool isInside(CPoint);
};

#endif 

