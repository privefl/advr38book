#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix to_col_cumsum(const NumericVector& step1,
                            const NumericVector& A,
                            int n) {
  
  int m = step1.length();
  NumericMatrix tau(n + 1, m);
  int i, j;
  
  // precomputing this is important
  NumericVector pows(n + 1);
  for (i = 1; i < (n + 1); i++) pows[i] = pow(1.0025, i - 1);
  
  for (j = 0; j < m; j++) {
    tau(0, j) = A[j];
    for (i = 1; i < (n + 1); i++) {
      tau(i, j) = tau(i - 1, j) + step1[j] * pows[i];
    }
  }
  
  return tau;
}

/*** R
# https://stackoverflow.com/questions/47542725/calculate-a-matrix-with-sequencing-without-a-nested-for-loop-for-faster-calculat/47547943#47547943
M <- 50
step1 <- runif(M)
A <- rnorm(M)
N <- 1e4

system.time({
  tau <- matrix(0, N + 1, M)
  tau[1, ] <- A
  for (j in 1:M) {
    for (i in 2:nrow(tau)) {
      tau[i, j] <- tau[i - 1, j] + step1[j] * 1.0025^(i - 2)
    }
  } 
})

# Can we reverse loops?
system.time({
  tau2 <- matrix(0, N + 1, M)
  tau2[1, ] <- A
  for (i in 2:nrow(tau2)) {
    for (j in 1:M) {
      tau2[i, j] <- tau2[i - 1, j] + step1[j] * 1.0025^(i - 2)
    }
  } 
})
all.equal(tau2, tau)

# Easy to vectorize previous inner loop
system.time({
  tau3 <- matrix(0, N + 1, M)
  tau3[1, ] <- A
  for (i in 2:nrow(tau3)) {
    tau3[i, ] <- tau3[i - 1, ] + step1 * 1.0025^(i - 2)
  } 
})
all.equal(tau3, tau)

# Or, spot the cumsum() for each column
system.time({
  adds <- outer(c(0, 1.0025^(0:(N - 1))), step1)
  adds[1, ] <- A
  tau4 <- matrixStats::colCumsums(adds)
})
all.equal(tau4, tau)

system.time(
  tau5 <- to_col_cumsum(step1, A, N)
)
all.equal(tau5, tau)
*/
