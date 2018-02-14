library(tidyverse)

most_dled <- cranlogs::cran_top_downloads("last-month", count = 100)

# https://juliasilge.com/blog/mining-cran-description/
tools::CRAN_package_db()[, -65] %>%
  select(Package, Maintainer) %>%
  right_join(most_dled, by = c("Package" = "package")) %>%
  count(Maintainer) %>%
  filter(n > 2)

dplyr::starwars

