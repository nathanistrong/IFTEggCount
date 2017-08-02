
#include <Rcpp.h>
#include "cift.h"
#include "image.h"
#include "adjacency.h"
#include "gqueue.h"
#include "edt.h"
#include "ellipse.h"
using namespace Rcpp;

// [[Rcpp::export]]
StringVector rcpp_hello_world(StringVector inputT) {

    std::string cppIn = as<std::string>(inputT);
    std::string testv = youTyped(cppIn);

    return wrap(testv);
}

/*// [[Rcpp::export]]
NumericVector CreateNewImage(NumericVector values, NumericVector ncols, NumericVector nrows){
  int i, cols, rows, n = values.size();
  int *values2;
  int aux;
  NumericVector result(n);
  cols = as<int>(ncols);
  rows = as<int>(nrows);
  Image *img;
  for(i=0; i < n; i++)
  {
    aux = values[i];
    values2[i] = aux;
  }
  img = CreateImage(cols, rows);
  SetImage2(img, values2, n);
  for(i=0; i < img->ncols*img->nrows; i++)
  {
    result[i] = img->val[i];
  }
  DestroyImage(&img);
  return (result);
} */

/*typedef struct _happy{
  Image *P;
} Happy;*/

// [[Rcpp::export]]
std::vector<int> CreateDistImage(std::vector<int> values, int ncols, int nrows){
  Image *img = (Image *)calloc(1,sizeof(Image));
  Forest *F = (Forest *)calloc(1,sizeof(Forest));
  img = CreateImage(ncols, nrows);
  int n = ncols*nrows;
  std::vector<int> result(n);
  SetImage2(img, values, ncols*nrows);
  
  F = DistTrans(img);
  for(int i=0; i < n; i++){
    result[i] = F->V->val[i];
  }
  return result;
}

// [[Rcpp::export]]
std::vector<int> FindEdgePoints(std::vector<int> distance, int ncols, int nrows, int centX, int centY){
  Image *dCost = (Image *)calloc(1,sizeof(Image));
  Ellipse *elp = (Ellipse *)calloc(1,sizeof(Ellipse));
  
  int n = nrows*ncols;
  std::vector<int> result;
  
  dCost = CreateImage(ncols, nrows);
  
  SetImage2(dCost, distance, n);
  
  elp = CreateEllipse(centX,centY);
  
  SetOrientation(elp, dCost, 10);
  
  Rcout << "why oh why did I swallow the fly\n";
  result = FillEdgeSet(elp, dCost, 10);
  
  return result;
  
}


float FindOrientationE(std::vector<int> distance, int ncols, int nrows, int centX, int centY){
  Image *dCost = (Image *)calloc(1,sizeof(Image));
  Ellipse *elp = (Ellipse *)calloc(1,sizeof(Ellipse));
  
  int n = nrows*ncols;
  float result;
  
  dCost = CreateImage(ncols, nrows);
  
  SetImage2(dCost, distance, n);
  
  elp = CreateEllipse(centX,centY);
  
  SetOrientation(elp, dCost, 10);
  
  result = elp->orientation;
  
  return result;
 
}