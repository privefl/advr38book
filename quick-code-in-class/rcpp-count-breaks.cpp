#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
IntegerVector count_breaks(const NumericVector& x,
                           const NumericVector& breaks) {
  
  int K = breaks.size() - 1;
  IntegerVector res(K);
  
  int n = x.size();
  
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < K; k++) {
      if (breaks[k] < x[i] && x[i] <= breaks[k + 1]) {
        res[k]++;
        break;
      }
    }
  }
  
  return res;
}
