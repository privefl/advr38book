#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix change_mat(const NumericMatrix& x,
                         const NumericVector& last_row) {
  
  NumericMatrix res = clone(x);
  int n = x.nrow();
  int m = x.ncol();
  
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      res(i, j) = 10 * x(i, j) * last_row[j];
    }
  }
  
  return res;
}


/*** R
tmp <- change_mat(mat_big, last_row)
mat_big[1:5, 1:5]
tmp[1:5, 1:5]
*/
