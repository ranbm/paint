//
//  Figure2D.cpp
//  HM1_204296792
//
//  Created by ran ben melech on 10/05/2020.
//  Copyright © 2020 ran ben melech. All rights reserved.
//

#include "Figure2D.h"
#include "pch.h"
#include "afx.h"
#include <iostream>
using namespace std;

Figure2D::Figure2D(void)
{}
Figure2D::~Figure2D(void)
{}

bool Figure2D::WhichPoint()
{
    CPoint s = getStartP();
    CPoint e = getEndP();
    if (s.x < e.x)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Figure2D::Serialize(CArchive& archive) {
    CObject::Serialize(archive); // calling the base class

    
    if (archive.IsStoring()) {
        archive << startP << endP << bgColor << pColor << penS << penT<<toPaint<<transper;
    }
    else
    {
        archive >> startP >> endP >>bgColor >> pColor >>penS >> penT>>toPaint>>transper;
    }

}
void Figure2D::Draw(CDC* dc) {
    CPen pen(penT, penS, pColor);
    CBrush brush(bgColor);
    CBrush* oldBrush = dc->SelectObject(&brush); // saving
    CPen* oldPen = dc->SelectObject(&pen); // saving
    DrawShape(dc);
}