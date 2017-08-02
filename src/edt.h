#ifndef _EDT_H_
#define _EDT_H_

#include "cift.h"
#include "image.h"
#include "adjacency.h"
#include "gqueue.h"

typedef struct _forest {
  Image *P; // predecessor map
  Image *R; // root map
  Image *V; // distance (cost or connectivity) map
} Forest;

Forest *CreateForest(int ncols, int nrows);

void DestroyForest(Forest **F);

Forest *DistTrans(Image *I);


#endif
