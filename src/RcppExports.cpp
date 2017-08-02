// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// matrixDim
NumericVector matrixDim(NumericMatrix data);
RcppExport SEXP _eggcount_matrixDim(SEXP dataSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericMatrix >::type data(dataSEXP);
    rcpp_result_gen = Rcpp::wrap(matrixDim(data));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_hello_world
StringVector rcpp_hello_world(StringVector inputT);
RcppExport SEXP _eggcount_rcpp_hello_world(SEXP inputTSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< StringVector >::type inputT(inputTSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_hello_world(inputT));
    return rcpp_result_gen;
END_RCPP
}
// CreateDistImage
std::vector<int> CreateDistImage(std::vector<int> values, int ncols, int nrows);
RcppExport SEXP _eggcount_CreateDistImage(SEXP valuesSEXP, SEXP ncolsSEXP, SEXP nrowsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type values(valuesSEXP);
    Rcpp::traits::input_parameter< int >::type ncols(ncolsSEXP);
    Rcpp::traits::input_parameter< int >::type nrows(nrowsSEXP);
    rcpp_result_gen = Rcpp::wrap(CreateDistImage(values, ncols, nrows));
    return rcpp_result_gen;
END_RCPP
}
// FindEdgePoints
std::vector<int> FindEdgePoints(std::vector<int> distance, int ncols, int nrows, int centX, int centY);
RcppExport SEXP _eggcount_FindEdgePoints(SEXP distanceSEXP, SEXP ncolsSEXP, SEXP nrowsSEXP, SEXP centXSEXP, SEXP centYSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type distance(distanceSEXP);
    Rcpp::traits::input_parameter< int >::type ncols(ncolsSEXP);
    Rcpp::traits::input_parameter< int >::type nrows(nrowsSEXP);
    Rcpp::traits::input_parameter< int >::type centX(centXSEXP);
    Rcpp::traits::input_parameter< int >::type centY(centYSEXP);
    rcpp_result_gen = Rcpp::wrap(FindEdgePoints(distance, ncols, nrows, centX, centY));
    return rcpp_result_gen;
END_RCPP
}
// FindOrientationE
float FindOrientationE(std::vector<int> distance, int ncols, int nrows, int centX, int centY);
RcppExport SEXP _eggcount_FindOrientationE(SEXP distanceSEXP, SEXP ncolsSEXP, SEXP nrowsSEXP, SEXP centXSEXP, SEXP centYSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type distance(distanceSEXP);
    Rcpp::traits::input_parameter< int >::type ncols(ncolsSEXP);
    Rcpp::traits::input_parameter< int >::type nrows(nrowsSEXP);
    Rcpp::traits::input_parameter< int >::type centX(centXSEXP);
    Rcpp::traits::input_parameter< int >::type centY(centYSEXP);
    rcpp_result_gen = Rcpp::wrap(FindOrientationE(distance, ncols, nrows, centX, centY));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_eggcount_matrixDim", (DL_FUNC) &_eggcount_matrixDim, 1},
    {"_eggcount_rcpp_hello_world", (DL_FUNC) &_eggcount_rcpp_hello_world, 1},
    {"_eggcount_CreateDistImage", (DL_FUNC) &_eggcount_CreateDistImage, 3},
    {"_eggcount_FindEdgePoints", (DL_FUNC) &_eggcount_FindEdgePoints, 5},
    {"_eggcount_FindOrientationE", (DL_FUNC) &_eggcount_FindOrientationE, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_eggcount(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
