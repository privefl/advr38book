// https://stackoverflow.com/questions/45298869/vectorized-method-instead-of-using-for-loop/45299014#45299014

#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
void rcppSweep(NumericMatrix& x, const NumericVector& lastRow) {
  
  double coef;
  
  for (int j = 0; j < x.ncol(); j++) {
    coef = 10 * lastRow[j];
    for (int i = 0; i < x.nrow(); i++) {
      x(i, j) *= coef;
    }
  }
}

/*** R
mat <- as.matrix(mtcars)
ind <- seq_len(nrow(mat))
dim(mat_big <- mat[rep(ind, 1000), ])
last_row <- mat_big[nrow(mat_big), ]

system.time(
  mat_big2 <- sweep(10 * mat_big, 2, last_row, '*')
)

system.time(
  rcppSweep(mat_big, last_row)
)
all.equal(mat_big2, mat_big)
*/
