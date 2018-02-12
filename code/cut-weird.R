x <- rnorm(100)
a <- cut(x, breaks = quantile(x, 0:10 / 10))
labs <- levels(a)
cbind(lower = as.numeric( sub("\\((.+),.*", "\\1", labs) ),
      upper = as.numeric( sub("[^,]*,([^]]*)\\]", "\\1", labs) ))


b <- cut(x, breaks = quantile(x, 0:10 / 10), labels = 1:10)
b

gtools::quantcut(x, 10, labels = 1:10)


split(x, ind <- sample(rep_len(1:5, length(x))))

