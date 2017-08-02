#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector matrixDim(NumericMatrix data) {
  int h = data.nrow();
  int w = data.ncol();
  int totalPixels = h*w;
  NumericVector lin(totalPixels);
  int i;
  int currentVal;
  int curY;
  int curX;
  lin = seq_len(totalPixels);
  for(i=0; i<totalPixels; i++)
  {
    curY = i / w;
    curX = i % w;
    currentVal = data(curY, curX);
    lin(i) = currentVal;
  }
  return lin;
}

/*I wanted to make a function here that makes a call to an external library I make that has it's own Cpp and Hp
 * Files
 */
StringVector testLibrary(StringVector entry){

  return "hello";
}

