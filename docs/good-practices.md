# Good practices



## Coding style

Good coding style is like correct punctuation: you can manage without it, butitsuremakesthingseasiertoread. I answer questions on Stack Overflow; first, I read the title of the question to see if I can answer the question, secondly, I check the coding style of the question and if the code is too difficult to read, I just move on. Please make your code readable by following e.g. [this coding style](http://style.tidyverse.org/) (examples below come from this guide).

You can use [package **styler**](https://github.com/r-lib/styler) (that provides RStudio addins) to correct your style:

<img src="https://raw.githubusercontent.com/lorenzwalthert/some_raw_data/master/styler_0.1.gif" width="70%" style="display: block; margin: auto;" />

### Naming

Be smart with your naming. I can't tell the number of times I've seen `df <- as.matrix(mtcars)` on Stack Overflow. 

### Spacing

Put a space before and after `=` when naming arguments in function calls.
Most infix operators (`==`, `+`, `-`, `<-`, etc.) are also surrounded by
spaces, except those with relatively high precedence: `^`, `:`, `::`, and `:::`. Always put a space after a comma, and never before (just like in regular English).


```r
# Good
average <- mean((feet / 12) + inches, na.rm = TRUE)
sqrt(x^2 + y^2)
x <- 1:10
base::get

# Bad
average<-mean(feet/12 + inches,na.rm=TRUE)
sqrt(x ^ 2 + y ^ 2)
x <- 1 : 10
base :: get
```

### Indenting

Curly braces, `{}`, define the the most important hierarchy of R code. To make 
this hierarchy easy to see, always indent the code inside `{}` by two spaces.


```r
# Good
if (y < 0 && debug) {
  message("y is negative")
}

if (y == 0) {
  if (x > 0) {
    log(x)
  } else {
    message("x is negative or zero")
  }
} else {
  y ^ x
}

# Bad
if (y < 0 && debug)
message("Y is negative")

if (y == 0)
{
    if (x > 0) {
      log(x)
    } else {
  message("x is negative or zero")
    }
} else { y ^ x }
```

### Long lines

Strive to limit your code to 80 characters per line. This fits comfortably on a 
printed page with a reasonably sized font. If you find yourself running out of 
room, this is a good indication that you should encapsulate some of the work in 
a separate function.

<img src="images/margin80.png" width="70%" style="display: block; margin: auto;" />


If a function call is too long to fit on a single line, use one line each for 
the function name, each argument, and the closing `)`. 
This makes the code easier to read and to change later. 


```r
# Good
do_something_very_complicated(
  something = "that",
  requires = many,
  arguments = "some of which may be long"
)

# Bad
do_something_very_complicated("that", requires, many, arguments,
                              "some of which may be long"
```

### Other

- Use `<-`, not `=`, for assignment. Keep `=` for parameters.


```r
# Good
x <- 5
system.time(
  x <- rnorm(1e6)
)
```

```
#>    user  system elapsed 
#>   0.101   0.000   0.102
```

```r
# Bad
x = 5
system.time(
  x = rnorm(1e6)
)
```

```
#> Error in system.time(x = rnorm(1e+06)): unused argument (x = rnorm(1e+06))
```

- Don't put `;` at the end of a line, and don't use `;` to put multiple commands 
on one line.

- Only use `return()` for early returns. Otherwise rely on R to return the result of the last evaluated expression.


```r
# Good
find_abs <- function(x, y) {
  if (x > 0) return(x)
  x * -1
}
add_two <- function(x, y) {
  x + y
}

# Bad
add_two <- function(x, y) {
  return(x + y)
}
```

- Use `"`, not `'`, for quoting text. The only exception is when the text already contains double quotes and no single quotes.


```r
# Good
"Text"
```

```
#> [1] "Text"
```

```r
'Text with "quotes"'
```

```
#> [1] "Text with \"quotes\""
```

```r
'<a href="http://style.tidyverse.org">A link</a>'
```

```
#> [1] "<a href=\"http://style.tidyverse.org\">A link</a>"
```

```r
# Bad
'Text'
```

```
#> [1] "Text"
```

```r
'Text with "double" and \'single\' quotes'
```

```
#> [1] "Text with \"double\" and 'single' quotes"
```


## RStudio

Download the latest version of [RStudio](https://www.rstudio.com/products/rstudio/download/#download) (> 1.1) and use it!

RStudio features:

- everything you can expect from a good IDE
- keyboard shortcuts I use
    1. *Ctrl + Space* (auto-completion, better than *Tab*)
    2. *Ctrl + Up* (command history & search)
    3. *Ctrl + Click* (function source code)
    3. *Ctrl + Enter* (execute line of code)
    4. *Ctrl + Shift + A* (reformat code)
    4. *Ctrl + Shift + C* (comment/uncomment selected lines)
    4. *Ctrl + Shift + K* (knit)
    4. *Ctrl + Shift + B* (build package, website or book)
    4. *Ctrl + Shift + M* (pipe)
    4. *Alt + Shift + K* to see all shortcuts...
- Panels (everything is integrated, including **Git** and a terminal)
- Interactive data importation from files and connections (see [this webinar](https://www.rstudio.com/resources/webinars/importing-data-into-r/))

<img src="images/data-import-environment.png" width="70%" style="display: block; margin: auto;" />

- Use [code diagnostics](https://support.rstudio.com/hc/en-us/articles/205753617-Code-Diagnostics):

<img src="images/diagnostics.png" width="70%" style="display: block; margin: auto;" />

- **R Projects**: 
    - **Meaningful structure** in one folder
    - The working directory automatically switches to the project's folder
    - File tab displays the associated files and folders in the project
    - History of R commands and open files
    - Any settings associated with the project, such as Git settings, are loaded. Note that a *set-up.R* or even a *.Rprofile* file in the project's root directory enable project-specific settings to be loaded each time people work on the project.

<blockquote class="twitter-tweet" data-lang="en" align="center"><p lang="en" dir="ltr">The only two things that make <a href="https://twitter.com/JennyBryan?ref_src=twsrc%5Etfw">\@JennyBryan</a> 😤😠🤯. Instead use projects + here::here() <a href="https://twitter.com/hashtag/rstats?src=hash&amp;ref_src=twsrc%5Etfw">#rstats</a> <a href="https://t.co/GwxnHePL4n">pic.twitter.com/GwxnHePL4n</a></p>&mdash; Hadley Wickham (\@hadleywickham) <a href="https://twitter.com/hadleywickham/status/940021008764846080?ref_src=twsrc%5Etfw">11 décembre 2017</a></blockquote>
<script async src="https://platform.twitter.com/widgets.js" charset="utf-8"></script>

Read more at https://www.tidyverse.org/articles/2017/12/workflow-vs-script/ and also see chapter [*Efficient set-up*](https://bookdown.org/csgillespie/efficientR/set-up.html) of book *Efficient R programming*.

## Version control (Git)

### Why use Git?

<div class="figure" style="text-align: center">
<img src="https://www.tacomaworld.com/attachments/i-also-like-to-live-dangerously-jpg.760853/" alt="You don't use Version Control?" width="50%" />
<p class="caption">(\#fig:unnamed-chunk-12)You don't use Version Control?</p>
</div>

Have you ever:

- **Made a change to code, realized it was a mistake and wanted to revert back?**
- **Lost code or had a backup that was too old?**
- Had to maintain multiple versions of a product?
- Wanted to see the difference between two (or more) versions of your code?
- Wanted to prove that a particular change broke or fixed a piece of code?
- Wanted to review the history of some code?
- **Wanted to submit a change to someone else's code?**
- **Wanted to share your code, or let other people work on your code?**
- Wanted to see how much work is being done, and where, when and by whom?
- Wanted to experiment with a new feature without interfering with working code?

In these cases, and no doubt others, a version control system should make your life easier (see https://stackoverflow.com/a/1408464/6103040).

- Version control for the researcher: don't do that, use Git

<img src="http://www.datacarpentry.org/rr-version-control/fig/phd101212s.png" width="45%" style="display: block; margin: auto;" />

- Version control for the data analyst: reproducible workflow

<center>
<iframe width="560" height="315" src="https://www.youtube.com/embed/s3JldKoA0zw" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>
</center>

Also, see https://stackoverflow.com/q/2712421/6103040.

- Use version control to work from anywhere
<img src="images/git.svg" width="70%" style="display: block; margin: auto;" />

- Working with GitHub can be a line on your CV ([read more](https://github.com/blog/2336-invest-in-tools-students-can-grow-with-github-and-rstudio-for-data-science-at-duke-university)):

> A lot of students have said to me later, even first-year undergraduates, that using GitHub has helped them a lot when they went for an internship or a research position interview.

> They are able to say, "Oh, I already have worked with GitHub. I'm familiar with it. I know how it works.” So I think they are at least able to put that on their CV and go into a situation where there's a research or data analysis team and say, "Yeah, sure. I am actually familiar with the same tools that you use."
>
> -- Mine Cetinkaya-Rundel, Duke University, RStudio

- Be able to get websites for your packages with [pkgdown](http://pkgdown.r-lib.org/), for your book (like this one!) with [bookdown](https://bookdown.org/), for your personal webpage with [R Markdown Websites](https://rmarkdown.rstudio.com/rmarkdown_websites.html) or [blogdown](https://bookdown.org/yihui/blogdown/).


### Git

- Main Git platforms (share your code, collaborate):
    - [GitHub](https://github.com/magrichard), [documentation](https://guides.github.com/activities/hello-world/) (only free for public repositories)
    - [GitLab UGA](https://gricad-gitlab.univ-grenoble-alpes.fr/), [documentation](https://docs.gricad-pages.univ-grenoble-alpes.fr/help/) or just [GitLab](https://about.gitlab.com/) (open source & free)
    - [Bitbucket](https://bitbucket.org/) (free with less than 5 collaborators)
    - any server..

- 3 main commands: 
    - pull: update your local project with the latest version of the main project
    - commit: snapshot of your code at a specified point in time
    - push: merge your local modifications with the main project


- Simple (solo) use of git to prevent merge conflicts:
    - after opening a project, always pull
    - before closing a project, always commit/push

- How to link between an RStudio project and a GitHub repository?

TODO: video

- Help with Git:
<img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQdltx925phiPYsw72GpjM30TBMn30YLTi8kAlf-N2sC_kTQNTiFQ" width="30%" style="display: block; margin: auto;" />
    - [H. Wickham's book](http://r-pkgs.had.co.nz/git.html)
    
    - [Happy Git and GitHub for the useR](http://happygitwithr.com/)
    
    - [Git cheat sheet](https://services.github.com/on-demand/downloads/github-git-cheat-sheet.pdf)
    
    - [When things go wrong](https://github.com/k88hudson/git-flight-rules)
    
    - [To fix a mistake](http://ohshitgit.com/)
    
    - [Create a new branch with git and manage branches](https://github.com/Kunena/Kunena-Forum/wiki/Create-a-new-branch-with-git-and-manage-branches)


## Getting help

### Help yourself, learn how to debug

A basic solution is to print everything, but it's usually not working well on complex problems. A convenient solution to see all the variables' states in your code is to place some `browser()` anywhere you want to check the variables' states.

Learn more with [this book chapter](https://bookdown.org/rdpeng/rprogdatascience/debugging.html) and [this RStudio article](https://support.rstudio.com/hc/en-us/articles/205612627-Debugging-with-RStudio).


### External help

Can't remember useful functions? Use [cheat sheets](https://www.rstudio.com/resources/cheatsheets/).

You can search for specific R stuff on https://rseek.org/. You should also read documentations carefully. If you're using a package, search for vignettes and a GitHub repository.

You can also use [Stack Overflow](https://stackoverflow.com/). The most common use of Stack Overflow is when you have an error or a question, you google it, and most of the times the first links are Q/A on Stack Overflow.

<img src="images/meme-SO.jpg" width="25%" style="display: block; margin: auto;" />

You can ask questions on Stack Overflow (using the tag `r`). You need to [make a great R reproducible example](https://stackoverflow.com/questions/5963269/how-to-make-a-great-r-reproducible-example) if you want your question to be answered. Most of the times, while making this reproducible example, you will find the answer to your problem.

If you're confident enough in your R skills, you can go to the next step and [answer questions on Stack Overflow](https://stackoverflow.com/unanswered/tagged/r?tab=newest). It's a good way to increase your skills, or just to [procrastinate while writing a scientific manuscript](https://privefl.github.io/blog/one-month-as-a-procrastinator-on-stack-overflow/).

### Exercises

TODO

