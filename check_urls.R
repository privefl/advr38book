## Inspired from https://gist.github.com/hyginn/c15e697223c45b5e16b3e90300807e45

library(magrittr)

HTML <- list.files(path = "docs", pattern = "\\.html$", full.names = TRUE)
all_bad <- purrr::map_dfr(HTML, function(html) {
  
  html %>% 
    xml2::read_html() %>% 
    rvest::html_nodes("a") %>% 
    rvest::html_attr("href") %>% 
    # remove URLs that don't begin with http:// or https://
    grep("^https?://", ., value = TRUE) %>% 
    # remove anchor parts (from "#" to end), since absence of internal
    # anchors does not affect the status code
    gsub("#[^#]*$", "", .) %>% 
    # remove duplicates
    unique() %>% 
    purrr::map_dfr(~ {
      status <- tryCatch(
        httr::http_status(httr::GET(print(.x))),
        error = function(e) list(category = "Unknown", reason = "Unknown"))
      cbind.data.frame(URL = .x, status[c("category", "reason")])
    }) %>% 
    dplyr::filter(category != "Success") %>% 
    dplyr::mutate(doc = sub("\\.html$", "", basename(html)))
})

all_bad
