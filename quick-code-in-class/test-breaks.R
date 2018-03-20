x <- sample(10, size = 1e4, replace = TRUE)
breaks <- c(1, 3, 9, 9.5, 10)


K <- length(breaks) - 1
res <- integer(K)
for (x_i in x) {
  for (k in seq_len(K)) {
    if (breaks[k] < x_i && x_i <= breaks[k + 1]) {
      res[k] = res[k] + 1
      break
    }
  }
}
table(cut(x, breaks))
res

outer(x, breaks, '>')[1:6, ]
table(colSums(outer(x, breaks, '>')))
x[1:6]
breaks

count_breaks(x, breaks)
