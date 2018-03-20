m0 <- matrix(rnorm(1e6), 1e3, 1e3)
m0_half <- m0[, 1:500]
microbenchmark::microbenchmark(
  colSums(m0[, 1:500]), 
  colSums(m0_half),
  m0[, 1:500],
  colSums(m0),
  colSums(m0)[1:500],
  myColSums(m0, 1:500)
)

all.equal(colSums(m0[, 1:500]), myColSums(m0, 1:500))
