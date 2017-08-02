#include "image.h"

Image *CreateImage(int ncols, int nrows)
{
  Image *img=NULL;
  int i;
  
  img = (Image *) calloc(1, sizeof(Image));
  if (img == NULL)
  {
    Error(MSG1, "CreateImage");
  }
  
  img->val = AllocIntArray(nrows*ncols);
  img->tbrow = AllocIntArray(nrows);
  
  img->tbrow[0] = 0;
  for (i=1; i < nrows; i++){
    img->tbrow[i] = img->tbrow[i-1]+ncols;
  }
  
  img->ncols = ncols;
  img->nrows = nrows;
  
  return(img);
}

void DestroyImage(Image **img)
{
  Image *aux;
  
  aux = *img;
  
  if(aux != NULL)
  {
    if (aux->val != NULL){
      free(aux->val);
    }
    if (aux->tbrow != NULL){
      free(aux->tbrow);
    }
    free(aux);
    *img = NULL;
  }
}


Image *CopyImage(Image *img)
{
  Image *imgc;
  
  imgc = CreateImage(img->ncols, img->nrows);
  std::memcpy(imgc->val, img->val, img->ncols*img->nrows*sizeof(int));
  
  return(imgc);
}


int MinimumValue(Image *img)
{
  int i, min, n;
  
  n = img->ncols*img->nrows;
  
  min = img->val[0];
  for (i=1; i < n; i++){
    if (img->val[i] < min){
      min = img->val[i];
    }
  }
  
  return(min);
}


int MaximumValue(Image *img)
{
  unsigned int i, n, r;
  int max;
  
  max = img->val[0];
  n = img->ncols*img->nrows - 1;
  r = n%4;
  n -= r;
  
  for (i=1; i < n; i+=4){
    if (img->val[i] > max){max = img->val[i];}
    if (img->val[i+1] > max){max = img->val[i+1];}
    if (img->val[i+2] > max){max = img->val[i+2];}
    if (img->val[i+3] > max){max = img->val[i+3];}
    
  }
  while (r != 0)
  {
    if (img->val[i+r-1] > max){max = img->val[i+r-1];}
    --r;
  }
  
  return(max);
}

/* Sets all values in the image to the value provided */
void SetImage(Image *img, int value)
{
  int i,n;
  n = img->ncols*img->nrows;
  for(i=0; i < n; i++)
  {
    img->val[i]=value;
  }
}



/* checks to see if a pixel is within the boundaries of the image */
bool ValidPixel(Image *img, int x, int y)
{
  if ((x >= 0) && (x < img->ncols) && (y >= 0) && (y < img->nrows))
  {
    return(true);
  } 
  else {
    return(false);
  }
}

void SetImage2(Image *img, std::vector<int> value, int numPix)
{
  int i,n;
  n = img->ncols*img->nrows;
  if(numPix < n)
  {
    Rcout << "Warning: Less pixels given than image in SetImage2";
  }
  for(i=0; i < n; i++){
    if(i <= numPix)
    {
      img->val[i] = value[i];
    }
  }
}



