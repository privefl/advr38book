## General

- Make a bookdown and an associated R package

## R base / useful functions


- `sweep()`
- `ifelse` is bad -> `if` for one.
- scoping, environments, `...`
- one expression with `{ }`
- debugging: `browser()`
- lazy evaluation
- classes (at least S3)

## Tidyverse

- importing data with RStudio
- train many models with cross-validation (with **dplyr** and many models)
- [purrr cookbook](http://colinfay.me/purrr-cookbook/)
- `dplyr::case_when()`
- `separate()`
- Not tody: GoT data (seasons), data("VADeaths") -> https://bookdown.org/rdpeng/RProgDA/basic-data-manipulation.html#spreading-and-gathering-data


## Performance

- Use the right data structures, for examples integers instead of characters
- Linear Algebra tricks:
  - `solve(A) %*% B`
  - `t(X) %*% X`
  - `A %*% B %*% c`
- une vectorization (e.g. `runif()`), package **matrixStats**
- deferred evaluation
- accessors: `for` uses `[[`, not `[` -> reimplement lapply()
  
### Parallel

- linear algebra -> use MRO
- bootstrap replicates
  
### Rcpp

- Differences between R and Rcpp
  - R is dynamically typed; C++ is statically typed.
  - indices begins at 1, and 0 for C++
- Rcpp sugar
- Rcout
- beware everything is passed by reference (need to use `clone()`)

  
## Solve problems

- deferred evaluation for loops
- computation of Pi with 2 uniforms in circle
