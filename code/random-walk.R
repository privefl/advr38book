# https://stackoverflow.com/questions/47953580/rapidly-generating-109-steps-of-a-random-process-in-r

x <- c(0, 0)
z <- 0
N <- 10^6
for (i in 2:N) {
  x[1] <- x[2]
  x[2] <- x[1] + rnorm(1, 0, 1)
  if (x[2] < 0) {
    z <- z + 1
  }
}
z / N


try <- numeric(1e8)


randomWalkR <- function(N) {
  mean(cumsum(rnorm(N)) < 0)
}
set.seed(1)
randomWalkR(N)
Rcpp::sourceCpp('code/random-walk.cpp')
microbenchmark::microbenchmark(
  randomWalkR(N),
  randomWalk(N)
)


system.time(
  randomWalkR(1e8)
)
system.time(
  randomWalk(1e8)
)
