#pragma once
//
//  Figure2D.h
//  HM1_204296792
//
//  Created by ran ben melech on 10/05/2020.
//  Copyright © 2020 ran ben melech. All rights reserved.
//

#ifndef Figure2D_h
#define Figure2D_h
#include <math.h>
#include "pch.h"
#include "ranPaint.h"
using namespace std;

class Figure2D :public CObject {

public:
    COLORREF bgColor, pColor;
    CPoint startP, endP;
    int penT, penS;
    bool toPaint,transper;

    //constractors:
    Figure2D(void);
    virtual ~Figure2D(void);
    //class functions:
    virtual bool isInside(CPoint) = 0;
    bool WhichPoint();


    //save or load figures:
    void Serialize(CArchive& archive);

    //setters:

    void setPenT(int a)
    {
        penT = a;
    }
    void setPenS(int a)
    {
        penS = a;
    }
    void setBg(COLORREF a)
    {
        bgColor = a;
    }
    void setP(COLORREF a)
    {
        pColor = a;
    }
    void setStartP(CPoint a)
    {
        startP = a;
        return;
    }
    void setEndP(CPoint a)
    {
        endP = a;
        return;
    }
    //getters:
    CPoint getEndP()const
    {
        return (endP);
    }

    COLORREF getBg() const
    {
        return bgColor;
    }
    COLORREF getP() const
    {
        return pColor;
    }
    int getPenT() const
    {
        return penT;
    }
    int Figure2D::getPenS() const
    {
        return penS;
    }
    CPoint getStartP()const
    {
        return (startP);
    }

    //draw:
    void Draw(CDC* dc);
    virtual void DrawShape(CDC* dc) {};
    

};
#endif
