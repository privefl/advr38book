## General

- Make a bookdown and an associated R package

## Instructions

- always ask questions
- next time if can't answer now
- tell if something missing

## R base / useful functions


- `...`
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
- Not tidy: GoT data (seasons), data("VADeaths") -> https://bookdown.org/rdpeng/RProgDA/basic-data-manipulation.html#spreading-and-gathering-data


## Performance

- Use the right data structures, for examples integers instead of characters
- deferred evaluation
- Rule of thumb: if compile faster then your code is bad
  
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
