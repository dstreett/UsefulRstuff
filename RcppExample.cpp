#include <Rcpp.h>
#include <iostream>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//

int fib(int x) {
  if (x <= 1) {
    return x;
  } else {
    return fib(x - 1) + fib(x - 2);
  }
}

// [[Rcpp::export]]
NumericVector fibCpp(NumericVector x) {
    NumericVector z(x.size());
  
    for (int i = 0; i < x.size(); ++i) {
      z[i] = fib(x[i]);
    }
    return z;
}

/*** R
#R code
testVec <- 1:25 

#test speed of first 25 fib numbers with C++ code
system.time(fibCpp(testVec))
# My results
# user  system elapsed 
#  0.005   0.001   0.007 

fibR <- function(x) {
  sapply(x, function(x) { if (x <= 1) { return (x) } else {return(fibR(x - 1) + fibR(x - 2))} } )
}

#test speed of first 25 fib numbers with R function
system.time(fibR(testVec))
#my results
#user  system elapsed 
#  26.601   0.223  30.540
*/
