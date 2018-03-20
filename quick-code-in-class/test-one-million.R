library(tidyverse)
mydf <- readRDS(system.file("extdata/one-million.rds", 
                            package = "advr38pkg"))
mydf
skimr::skim(mydf)

QRA_3Dmatrix <- array(0, dim = c(max(mydf$ID), max(mydf$Volume), 2))
dim(QRA_3Dmatrix)
QRA_3Dmatrix

transfo <- function(x) {
  1.358 / (1 + exp( (1000 * x - 129000) / 120300 ))
}

# system.time({
#   for (i in seq_len(nrow(mydf))) {  # nrow(mydf)
#     # Row corresponds to IDcell 
#     row    <- mydf[[i, 1]]    
#     # Column corresponds to the volume class
#     column <- mydf[[i, 3]]      
#     # Number of events, initially zero, then +1
#     QRA_3Dmatrix[row, column, 1] <- QRA_3Dmatrix[row, column, 1] + 1  
#     # Sum energy 
#     QRA_3Dmatrix[row, column, 2] <- 
#       QRA_3Dmatrix[row, column, 2] + 1 - transfo(mydf[[i, 2]])
#   }
# })

library(tidyverse)
system.time({
  res <- mydf %>%
    group_by(ID, Volume) %>%
    summarize(
      n = n(),
      n2 = n - sum(transfo(Energy))
    )
  QRA_3Dmatrix2 <- array(0, dim = c(max(mydf$ID), max(mydf$Volume), 2))
  QRA_3Dmatrix2[cbind(as.matrix(res[1:2]), 1)] <- res[[3]]
  QRA_3Dmatrix2[cbind(as.matrix(res[1:2]), 2)] <- res[[4]]
})

res
QRA_3Dmatrix2[1, 1:10, ]
all.equal(QRA_3Dmatrix2, tmp)

all.equal(QRA_3Dmatrix2, QRA_3Dmatrix)


f1 <- function(mydf) {
  res <- mydf %>%
    group_by(ID, Volume) %>%
    summarize(
      n = n(),
      n2 = n - sum(transfo(Energy))
    )
  
  QRA_3Dmatrix2 <- array(0, dim = c(max(mydf$ID), max(mydf$Volume), 2))
  QRA_3Dmatrix2[cbind(as.matrix(res[1:2]), 1)] <- res[[3]]
  QRA_3Dmatrix2[cbind(as.matrix(res[1:2]), 2)] <- res[[4]]
  
  QRA_3Dmatrix2
}


mydf2 <- mydf[seq_len(1e4), ]
all.equal(f1(mydf2), getArray(mydf2))
microbenchmark::microbenchmark(
  "DPLYR" = f1(mydf2), 
  "RCPP"  = getArray(mydf2)
)

microbenchmark::microbenchmark(
  # "DPLYR" = f1(mydf2), 
  "RCPP"  = getArray(mydf)
)

