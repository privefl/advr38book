#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector fun_cpp(NumericVector x) {
  
  int n = x.size();
  NumericVector y(n); y[0] = 1;
  
  for (int i = 1; i < n; i++) {
    // y[i] = pow(y[i - 1], 2) + x[i];
    y[i] = y[i - 1] * y[i - 1] + x[i];
  }
  
  return y;
}


/*** R
fun_r <- function(x) {
  n <- length(x)
  y <- numeric(n); y[1] <- 1
  for (i in 2:n) {
    y[i] <- y[i - 1]^2 + x[i]
  }
  y
}

x <- runif(1e6)
all.equal(fun_cpp(x), fun_r(x))

microbenchmark::microbenchmark(
  fun_cpp(x), 
  fun_r(x)
)
*/
