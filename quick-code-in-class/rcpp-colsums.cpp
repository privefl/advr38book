#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector myColSums(const NumericMatrix& x,
                        const IntegerVector& ind) {
  
  int m = ind.size();
  int n = x.nrow();
  NumericVector res(m);
  double sum;
  int j2;
  
  for (int j = 0; j < m; j++) {
    j2 = ind[j] - 1;
    sum = 0;
    for (int i = 0; i < n; i++) {
      sum += x(i, j2);
    }
    res[j] = sum;
  }
  
  return res;
}
