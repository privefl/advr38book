#include <RcppArmadillo.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
sp_mat sqrt_(SEXP X_) {
  
  Rcout << Rf_inherits(X_, "dgCMatrix") << std::endl;
  
  sp_mat X = as<arma::sp_mat>(X_);
  
  Rcout << X(0, 1) << std::endl;
  
  return sqrt(X);
}

/*** R
library(Matrix)
i <- c(1,3:8); j <- c(2,9,6:10); x <- 7 * (1:7)
A <- sparseMatrix(i, j, x = x)
sqrt_(A)
*/
