// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>
using namespace Rcpp;

double transfo(double x) {
  return 1.358 / (1 + exp( (1000 * x - 129000) / 120300 ));
}

// [[Rcpp::export]]
arma::cube getArray(const DataFrame& mydf) {
  
  IntegerVector ID = mydf["ID"];
  NumericVector Energy = mydf["Energy"];
  IntegerVector Volume = mydf["Volume"];
  
  // QRA_3Dmatrix <- array(0, dim = c(max(mydf$ID), max(mydf$Volume), 2))
  arma::cube QRA_3Dmatrix(max(ID), max(Volume), 2, arma::fill::zeros);
  int row, col;
  
  int n = ID.size();
  for (int i = 0; i < n; i++) {
    row = ID[i] - 1;
    col = Volume[i] - 1;
    QRA_3Dmatrix(row, col, 0)++; 
    QRA_3Dmatrix(row, col, 1) += 1 - transfo(Energy[i]);
  }
  
  return QRA_3Dmatrix;
}

/*** R
tmp <- getArray(mydf)
dim(tmp)
*/
