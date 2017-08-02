#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "cift.h"

typedef struct _pixel{
  int x,y;
} Pixel;

typedef struct _image{
  int *val;
  int ncols, nrows;
  int *tbrow;
} Image;

Image *CreateImage(int ncols, int nrows);
void DestroyImage(Image **img);
Image *CopyImage(Image *img);
void SetImage2(Image *img, std::vector<int> value, int numPix);

int MinimumValue(Image *img);
int MaximumValue(Image *img);
void SetImage(Image *img, int value);
bool ValidPixel(Image *img, int x, int y);

#endif