# Spelling check
words <- spelling::spell_check_files(
  path = knitr::current_input(), #list.files(pattern = "\\.Rmd$"),
  ignore = c(scan(system.file("WORDLIST", package = "advr38pkg"), "")),
  lang = "en-US"
)

if (nrow(words)) {
  capture.output(print(words), file = "spelling.errors")
  stop("Check spelling! Check file 'spelling.errors'")
}

rm(words)
