#ifndef __ADJACENCY_H__
#define __ADJACENCY_H__

#include "image.h"

typedef struct _adjrel{
  int *dx;
  int *dy;
  int n;
} AdjRel;

typedef struct _adjpxl{
  int *dp;
  int n;
} AdjPxl;

/*all adjacency relations must place the central pixel at first. The central pixel must be skipped when
 * visiting the neighbors during the IFT. It must be considered in the other operations.
 */

AdjRel *CreateAdjRel(int n);
void DestroyAdjRel(AdjRel **A);
AdjRel *CloneAdjRel(AdjRel *A);

AdjRel *Circular(float r);

AdjPxl *AdjPixels(Image *img, AdjRel *A);

void DestroyAdjPxl(AdjPxl **N);



#endif