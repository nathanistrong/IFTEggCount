#include "cift.h"

/* This is just to make sure that the file is still working as I build it */
std::string youTyped(std::string& entry){
  return std::string("You entered: ")+entry;
}

void Error(std::string msg, std::string func){
  Rcout << "Error: " << MSG1 << " in " << func << "\n";
  stop("Aborting Program...");
}

int *AllocIntArray(int n){
  int *v=NULL;
  v = (int *) calloc(n,sizeof(int));
  if (v == NULL){
    Error(MSG1, "AllocIntArray");
  }
  return(v);
}

float *AllocFloatArray(int n){
  float *v = NULL;
  v = (float *) calloc(n, sizeof(float));
  if (v == NULL){
    Error(MSG1, "AllocFloatArray");
  }
  return(v);
}


