#ifndef __ELLIPSE_H__
#define __ELLIPSE_H__

#include "cift.h"
#include "image.h"

typedef struct _ellipse{
  int cx;
  int cy;
  float orientation;
  float t1;
  float t2;
  
} Ellipse;

Ellipse *CreateEllipse(int centerX, int centerY);

void DestroyEllipse(Ellipse **elp);

void CalcMaxEllipse(Image *dCost, Ellipse *elp);

std::vector<int> FillEdgeSet(Ellipse *elp, Image *dCost, int numLines);


#endif