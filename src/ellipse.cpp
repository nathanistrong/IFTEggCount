#include "ellipse.h"

Ellipse *CreateEllipse(int centerX, int centerY)
{
  Ellipse *elp = NULL;
  
  elp = (Ellipse *) calloc(1, sizeof(Ellipse));
  if (elp == NULL)
  {
    Error(MSG1, "CreateEllipse");
  }
  
  elp->cx = centerX;
  elp->cy = centerY;
  
  return(elp);
}

void DestroyEllipse(Ellipse **elp)
{
  Ellipse *aux;
  
  aux = *elp;
  
  if(aux != NULL)
  {
    free(aux);
    *elp = NULL;
  }
}

std::vector<int> FillEdgeSet(Ellipse *elp, Image *dCost, int numLines)
{
  
  int xp, yp, dxi, dyi, li, pixNum, ncols;
  int lim;
  int posnum, negnum, posCost, negCost;
  float ang, equalD, d, a1, a2, v;
  
  lim = numLines;
  
  std::vector<int> result(numLines*4);
  
  xp = elp->cx;
  yp = elp->cy;
  ncols = dCost->ncols;
  
  Rcout << "dCost of (153, 330): " << dCost->val[153] << "\n";
  //if things don't work right, i'd double check this but it should be good.
  pixNum = yp*ncols+xp;
  
  equalD = PI/numLines;
  //Rcout << "Setting common angle: " << equalD << "\n";
  
  int j = 0;
  
  for(li = 1; li <= lim; li++){
    ang = li*equalD;
    //Rcout << "Current angle is: " << ang << "\n";
    v = dCost->val[pixNum];
    v = sqrt(v);

    //Rcout << "Initial cost is: " << v << "\n";
    a1 = -1;
    a2 = -1;
    do{
      dxi = (int) round(v*(std::cos(ang)));
      dyi = (int) round(v*(std::sin(ang)));
      
      /*Rcout << "dxi is: " << dxi << "\n";
      Rcout << "dyi is: " << dyi << "\n";
      Rcout << "Total distance away is: " << d << "\n";*/
      d = std::min(a1, a2);
      if(d == a1){
        posnum = (yp+dyi)*ncols+(xp+dxi);
        posCost = dCost->val[posnum];
        a1 = sqrt(posCost);
        //Rcout << "New Cost of a1 is: " << a1 << "\n";
      }
      if(d == a2){
        negnum = (yp-dyi)*ncols+(xp-dxi);
        negCost = dCost->val[negnum];
        a2 = sqrt(negCost);
        //Rcout << "New Cost of a2 is: " << a2 << "\n";
      }
      d=std::min(a1,a2);
      v = v+d;
      
    } while (abs(a1*a2) > 0);
    Rcout << "For Line: " << li << ", the angle is: " << ang << ", dxi is: " << dxi << ", and dyi is: " << dyi << ". The total distance is: " << v << "\n";
    result[j] =dxi;
    result[j+1] = dyi;
    j+=2;
  }
  return result;
}

void SetOrientation(Ellipse *elp, Image *dCost, int numLines)
{
  
  int i, F, G, H, xi, yi;
  float gamma;
  
  int lines = numLines;
  int lines2 = numLines;
  int twoLines = lines*2;
  
  std::vector<int> edges;
  std::vector<int> edgesx(twoLines);
  std::vector<int> edgesy(twoLines);
  
  edges = FillEdgeSet(elp, dCost, lines);
  Rcout << "Orientation exectued \n";
  for(i=0; i < lines; i++)
  {
    edgesx[i] = edges[i];
    edgesx[i+lines2] = -1*edges[i];
    edgesy[i] = edges[i+lines2];
    edgesy[i+lines2] = -1*edges[i+lines2];
  }
  /* set up F, G, and H to calculate gamma (orientation of the ellipse) */
  Rcout << "shortened computation... executing....\n";
  F=0; G=0; H=0;
  for(i=0; i < lines; i++)
  {
    xi = edgesx[i];
    yi = edgesy[i];
    
    F += (xi*yi);
    G += yi^2;
    H += xi^2;
  }
  F = 2*F;
  G = 2*G;
  H = 2*H;
  
  gamma = (std::atan((2*F)/(G-H)))/2;
  
  if(F < 0.0 && gamma < 0.0){
    gamma = gamma + PI/2;
  } else if(F > 0.0 && gamma > 0.0){
    gamma = gamma - PI/2;
  }
  
  elp->orientation = gamma;
}
















