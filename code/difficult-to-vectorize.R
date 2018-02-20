# https://stackoverflow.com/questions/48695732/iterate-through-data-frame-where-each-iteration-is-dependent-on-the-previous-ite

x <- seq_len(1e3)
y <- rep(0, length(x))
df <- data.frame(x, y)
z <- 3e5

for (i in seq(2, nrow(df))) {
  if (df$x[i] %% 2 == 0) {
    df$y[i] <- df$y[i-1] + z
    z <- z - df$x[i]
  } else{
    df$y[i] <- df$y[i-1]
  }
}

x
y
df
z

x <- seq_len(1e3)
y <- rep(0, length(x))
df <- data.frame(x, y)
z <- 3e5

vec_fun <- function(x, z) {
  L <- length(x)
  
  vec_z <- rep(0, L)
  I <- seq(2, L, by=2)
  vec_z[I] <- head(z-c(0, cumsum(I)), length(I))
  
  cumsum(vec_z)
}

df$y <- vec_fun(x, z)

x
y
df
z