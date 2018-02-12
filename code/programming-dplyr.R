library(dplyr)
# dplyr programming
my_summarise <- function(df, group) {
  group <- enquo(group)
  
  df %>%
    group_by(!!group) %>%
    summarise_all(mean)
}

my_summarise(iris, Species)

# macros
my_summarise2 <- gtools::defmacro(df, group, expr = {
  df %>%
    group_by(group) %>%
    summarise_all(mean)
})

my_summarise2(iris, Species)
