#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double neg_prop_cpp(int N) {
  
  double x = 0;
  int count = 0;
  for (int i = 0; i < N; i++) {
    x += R::rnorm(0, 1);
    if (x < 0) count++;
  }
  
  return (double)count / N;
}

/*** R
set.seed(1)
N <- 1e4
neg_prop_r <- function(N) {
  y <- rnorm(N)
  x <- cumsum(y)
  mean(x < 0)
}
neg_prop_r(N)
# hist(replicate(1e4, test_rnorm()))
# hist(rnorm(1e5))

set.seed(1)
N <- 1e7
neg_prop_cpp(N)

N <- 1e5
microbenchmark::microbenchmark(
  neg_prop_r(N),
  neg_prop_cpp(N)
)
*/
