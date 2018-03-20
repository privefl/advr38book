#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector testArray(NumericVector x) {
  
  int n = x.size();
  NumericVector array(Dimension(n, n, 2));
  
  return array;
}

/*** R
x <- runif(5)
testArray(x)
*/
