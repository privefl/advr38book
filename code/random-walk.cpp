#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double randomWalk(int N) {
  
  double x = 0;
  int count = 0;
  for (int i = 0; i < N; i++) {
    x += norm_rand();
    if (x < 0) count++;
  }
  
  return (double)count / N;
}


/*** R
set.seed(1)
randomWalk(1e6)
*/
