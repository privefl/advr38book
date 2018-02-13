x <- runif(1e6)
y <- runif(1e6)
z <- sample(c(TRUE, FALSE), 1e6, replace = TRUE)
sum((x + y)[z])