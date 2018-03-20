mat <- as.matrix(mtcars)
ind <- seq_len(nrow(mat))
mat_big <- mat[rep(ind, 1000), ]  ## 1000 times bigger dataset
last_row <- mat_big[nrow(mat_big), ]
dim(mat_big)

system.time({
  for (j in 1:ncol(mat_big)) {
    for (i in 1:nrow(mat_big)) {
      mat_big[i, j] <- 10 * mat_big[i, j] * last_row[j]
    }
  }
})

a <- matrix(1:4, 2)
a
sweep(a, 2, 1:2, '*')

mat_big2 <- sweep(10 * mat_big, 2, last_row, '*')
mat_big3 <- sweep(mat_big, 2, 10 * last_row, '*')
all.equal(mat_big2, mat_big3)

microbenchmark::microbenchmark(
  sweep(10 * mat_big, 2, last_row, '*'),
  sweep(mat_big, 2, 10 * last_row, '*')
)
