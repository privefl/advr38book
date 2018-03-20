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
mat <- as.matrix(mtcars)
ind <- seq_len(nrow(mat))
mat_big <- mat[rep(ind, 1000), ]  ## 1000 times bigger dataset
last_row <- mat_big[nrow(mat_big), ]
dim(mat_big)

mat_big3 <- sweep(mat_big, 2, 10 * last_row, '*')
tmp <- change_mat(mat_big, last_row)
mat_big[1:5, 1:5]
tmp[1:5, 1:5]
mat_big3[1:5, 1:5]

microbenchmark::microbenchmark(
  sweep(10 * mat_big, 2, last_row, '*'),
  sweep(mat_big, 2, 10 * last_row, '*'),
  change_mat(mat_big, last_row)
)
*/
