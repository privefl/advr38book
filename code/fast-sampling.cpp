#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
IntegerMatrix sample2(int N) {
  
  IntegerMatrix res(2 * N, 2);
  int j, ind1, ind2;
  
  for (j = 0; j < N; j++) {
    
    res(2 * j, 0) = res(2 * j + 1, 0) = j + 1;
    
    // sample first one
    do {
      ind1 = N * unif_rand();
    } while (ind1 == j);
    res(2 * j, 1) = ind1 + 1;
    
    // sample second one
    do {
      ind2 = N * unif_rand();
    } while (ind2 == j || ind2 == ind1);
    res(2 * j + 1, 1) = ind2 + 1;
  }
  
  return res;
}

/*** R
# https://stackoverflow.com/questions/45794563/vectorise-r-code-to-randomly-select-2-columns-from-each-row/45796424#45796424

table(replicate(1e5, sample2(5)))  # Verify that the sampling is OK
library(Matrix)
N <- 1000

microbenchmark::microbenchmark(
  OP = {
    desired_output <- Matrix(0, nrow = N, ncol = N)
    for(j in 1:N) {
      cols <- sample((1:N)[-j], 2) #Choose 2 columns not equal to the 
      desired_output[j, cols] <- 1
    }
  },
  Aurele = {
    res <- Matrix(0, nrow = N, ncol = N)
    ind <- cbind(rep(1:N, each = 2), c(sapply(1:N, function(j) sample((1:N)[-j], 2))))
    res[ind] <- 1
  },
  privefl = {
    m <- Matrix(0, nrow = N, ncol = N)
    m[sample2(N)] <- 1
  },
  times = 20
)
*/
