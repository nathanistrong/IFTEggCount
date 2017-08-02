#include "adjacency.h"

AdjRel *CreateAdjRel(int n)
{
  AdjRel *A = NULL;
  
  A = (AdjRel *) calloc(1, sizeof(AdjRel));
  if (A != NULL)
  {
    A->dx = AllocIntArray(n);
    A->dy = AllocIntArray(n);
    A->n = n;
  } else {
    Error(MSG1, "CreateAdjRel");
  }
  
  return(A);
}

void DestroyAdjRel(AdjRel **A)
{
  AdjRel *aux;
  
  aux = *A;
  
  if (aux != NULL){
    if (aux->dx != NULL){ free(aux->dx); }
    if (aux->dy != NULL){ free(aux->dy); }
    free(aux);
    *A = NULL;
  }
}

AdjRel *CloneAdjRel(AdjRel *A)
{
  AdjRel *C;
  int i;
  
  C = CreateAdjRel(A->n);
  for(i=0; i < A->n; i++){
    C->dx[i] = A->dx[i];
    C->dy[i] = A->dy[i];
  }
  
  return(C);
}

AdjRel *Circular(float r)
{
  AdjRel *A=NULL;
  int i,j,k,n,dx,dy,r0,r2,d,i0=0;
  float *da,*dr,aux;
  
  n=0;
  
  r0 = (int)r;
  r2 = (int)(r*r);
  
  for(dy=-r0; dy <= r0; dy++){
    for(dx=-r0; dx <= r0; dx++){
      if(((dx*dx)+(dy*dy)) <= r2){
        n++;
      }
    }
  }
  
  A = CreateAdjRel(n);
  
  i=0;
  for(dy=-r0; dy <= r0; dy++){
    for(dx=-r0; dx <= r0; dx++){
      if(((dx*dx)+(dy*dy)) <= r2){
        A->dx[i]=dx;
        A->dy[i]=dy;
        if ((dx==0)&&(dy==0)){
          i0 = i;
        }
        i++;
      }
    }
  }
  
  da = AllocFloatArray(A->n);
  dr = AllocFloatArray(A->n);
  
  for (i=0; i < A->n; i++)
  {
    dx = A->dx[i];
    dy = A->dy[i];
    dr[i] = (float)sqrt((dx*dx) + (dy*dy));
    if (i != i0){
      da[i] = atan2(-dy,-dx)*180.0/PI;
      if (da[i] < 0.0){
        da[i] += 360.0;
      }
    }
  }
  da[i0] = 0.0;
  dr[i0] = 0.0;
  
  /* Place central pixel at first position */
  
  aux = da[i0];
  da[i0] = da[0];
  da[0] = aux;
  
  aux = dr[i0];
  dr[i0] = dr[0];
  dr[0] = aux;
  
  d = A->dx[i0];
  A->dx[i0] = A->dx[0];
  A->dx[0] = d;
  d = A->dy[i0];
  A->dy[i0] = A->dy[0];
  A->dy[0] = d;
  
  /* sort by angle */
  
  for (i=1; i < A->n-1; i++){
    k = i;
    for(j=i+1; j < A->n; j++){
      if (da[j] < da[k]){
        k = j;
      }
    }
    
    aux = da[i];
    da[i] = da[k];
    da[k] = aux;
    aux = dr[i];
    dr[i] = dr[k];
    dr[k] = aux;
    d = A->dx[i];
    A->dx[i] = A->dx[k];
    A->dx[k] = d;
    
    d = A->dy[i];
    A->dy[i] = A->dy[k];
    A->dy[k] = d;
  }
  
  /* sort by radius for each angle */
  
  for (i=1; i < A->n-1; i++){
    k = i;
    for(j=i+1; j < A->n; j++){
      if ((dr[j] < dr[k])&&(da[j]==da[k])){
        k = j;
      }
    }
    
    aux = dr[i];
    dr[i] = dr[k];
    dr[k] = aux;
    d = A->dx[i];
    A->dx[i] = A->dx[k];
    A->dx[k] = d;
    
    d = A->dy[i];
    A->dy[i] = A->dy[k];
    A->dy[k] = d;
  }
  
  free(dr);
  free(da);
  
  return(A);
  
}

AdjPxl *AdjPixels(Image *img, AdjRel *A)
{
  AdjPxl *N;
  int i;
  
  N = (AdjPxl *) calloc(1, sizeof(AdjPxl));
  
  if(N != NULL){
    N->dp = AllocIntArray(A->n);
    N->n = A->n;
    for (i=0; i < N->n; i++){
      N->dp[i] = A->dx[i]+img->ncols*A->dy[i];
    }
  } else {
    Error(MSG1, "AdjPixels");
  }
  
  return(N);
}

void DestroyAdjPxl(AdjPxl **N)
{
  AdjPxl *aux;
  
  aux = *N;
  if (aux != NULL)
  {
    if(aux->dp != NULL){ free(aux->dp); }
    free(aux);
    *N = NULL;
  }
}


