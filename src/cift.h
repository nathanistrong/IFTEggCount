#ifndef __COMMON_IFT__
#define __COMMON_IFT__

#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <float.h>
#include <time.h>
#include <Rcpp.h>
using namespace Rcpp;

/* Error Messages */

#define MSG1 "Cannot allocate memory space"
#define MSG2 "Cannot open file"
#define MSG3 "Invalid option"

/* Common data types to all programs */

#ifndef __cplusplus
typedef enum boolean {false, true} bool;
#endif
typedef unsigned short ushort;
typedef unsigned int uint;

typedef struct timeval timer;
typedef unsigned char uchar;

typedef int* ap_int;

typedef double* ap_double;

typedef float real;
#define REAL_MAX FLT_MAX
#define REAL_MIN FLT_MIN

#define INTERIOR 0
#define EXTERIOR 1
#define BOTH 2
#define WHITE 0
#define GREY 1
#define BLACK 2
#define NIL -1
#define INCREASING 1
#define DECREASINE 0
#define Epsilon 1E-05

/* memory allocation functions defined in cift */

int *AllocIntArray(int n); /* Allocates a 1D array of n integers */
float *AllocFloatArray(int n); /* Allocates a 1D array of n floats */

/* This function is modified from the original C code to print an error to the R console */
void Error(std::string msg, std::string func);

std::string youTyped(std::string& entry);

#endif