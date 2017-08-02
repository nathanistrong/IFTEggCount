#include "edt.h"

Forest *CreateForest(int ncols, int nrows)
{
  Forest *F=(Forest *)calloc(1,sizeof(Forest));
  
  F->P = CreateImage(ncols,nrows);
  F->R = CreateImage(ncols,nrows);
  F->V = CreateImage(ncols,nrows);
  
  return(F);
}

void DestroyForest(Forest **F)
{
  Forest *tmp=*F;
  
  if (tmp != NULL) {
    DestroyImage(&(tmp->P));
    DestroyImage(&(tmp->R));
    DestroyImage(&(tmp->V));
    free(tmp);
    *F = NULL;
  }
}

Forest *DistTrans(Image *I)
{
  int p,q,n=I->ncols*I->nrows,i,tmp;
  Pixel u,v,w;
  AdjRel *A=Circular(1.5),*A4=Circular(1.0);
  Forest *F=CreateForest(I->ncols,I->nrows);
  GQueue *Q=CreateGQueue(1024,n,F->V->val);
  
  // Trivial path initialization
  
  for (p=0; p < n; p++) {
    u.x = p % I->ncols;
    u.y = p / I->ncols;
    F->V->val[p]=INT_MAX; F->R->val[p]=p; F->P->val[p]=NIL;
    if (I->val[p]!=0){ // p belongs to an object's border
      F->V->val[p]=0;
      InsertGQueue(&Q,p);
    }
  }
  
  // Path propagation
  
  while(!EmptyGQueue(Q)){
    p = RemoveGQueue(Q);
    u.x = p % I->ncols;
    u.y = p / I->ncols;
    w.x = F->R->val[p] % I->ncols;
    w.y = F->R->val[p] / I->ncols;
    for (i=1; i < A->n; i++) {
      v.x = u.x + A->dx[i];
      v.y = u.y + A->dy[i];
      if (ValidPixel(I,v.x,v.y)){
        q   = v.x + I->tbrow[v.y];
        if (F->V->val[q]>F->V->val[p]){
          tmp = (v.x-w.x)*(v.x-w.x)+(v.y-w.y)*(v.y-w.y);
          if (tmp < F->V->val[q]){
            if (F->V->val[q]!=INT_MAX) RemoveGQueueElem(Q, q);
            F->V->val[q]=tmp; F->R->val[q]=F->R->val[p]; F->P->val[q]=p;
            InsertGQueue(&Q,q);
          }
        }
      }
    }
  }
  
  DestroyGQueue(&Q);
  DestroyAdjRel(&A);
  DestroyAdjRel(&A4);
  
  return(F);
}