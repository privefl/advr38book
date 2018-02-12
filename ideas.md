## General

- Make a bookdown and an associated R package

## R base / useful functions

- `rle()`
- `match()` -> search from corresponding table
- accessors: `for` uses `[[`, not `[`
- paste and sprintf
- `order()`, `rank()` -> arrange with multiple columns
- Package **glue**
- `outer()`
- `reshape2::colsplit()`
- `cut()` and `split()`
- packages **gtools** (macros, `mixedsort()`) and **R.utils**
- `sweep()`
- `expand.grid()`
- `rep()` and `seq()` (+ extensions)
- `ifelse` is bad -> `if` for one.
- `apply`, `lapply()`, `sapply`, `mapply`, `tapply`
- `replicate()`

## Tidyverse

- train many models with cross-validation (with **dplyr** and many models)
- [purrr cookbook](http://colinfay.me/purrr-cookbook/)
- `dplyr::case_when()`


## Performance

- Use the right data structures, for examples integers instead of characters
- Linear Algebra tricks:
  - `solve(A) %*% B`
  - `t(X) %*% X`
  - `A %*% B %*% c`
- une vectorization (e.g. `runif()`), package **matrixStats**
  
### Parallel

- linear algebra -> use MRO
  
## Solve problems
