# https://support.rstudio.com/hc/en-us/articles/205612627-Debugging-with-RStudio

test_debug <- function(x = 2, y = 3) {
  c <- 4
  browser()
  x + y + c
}

test_debug(2)
