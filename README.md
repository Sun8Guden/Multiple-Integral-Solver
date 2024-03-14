# Numerical Solver for Multiple Integral

Some analytical solutions encountered in my research, which express the integral in a closed form with well-defined functions, are not achievable for analytical simplification. This is where numerical solvers come in. 
While single integrals deal with one variable and one can find mature solver in commerical softwares. Multiple integrals need to directly compute integrals with two or more variables directly. Here, we provide two implementations.

A numerical solver for multiple integration approximates the value of the integral using numerical methods. These methods break down the integration region  -- the multidimensional space over which the integration is performed --  into smaller subregions and employ certain rules to evaluate the integrand (the function being integrated) over these subregions. The sum of the contributions from all these subregions provides an approximate value for the entire integral.
Here, we provide the implementation of two rules:
* GenzMalik: Genz, A. C., & Malik, A. A. (1980). Remarks on algorithm 006: An adaptive algorithm for numerical integration over an N-dimensional rectangular region. Journal of Computational and Applied mathematics, 6(4), 295-302.
* Cuhre: Berntsen, J., Espelid, T. O., & Genz, A. (1991). An adaptive algorithm for the approximate calculation of multiple integrals. ACM Transactions on Mathematical Software (TOMS), 17(4), 437-451.

## How to use the code
We append an example file, the user should compile it with the flag "-std=gnu++20". Specifically:
1, The user should define an integrand function by Lambda functions, or functor classes. 
2, The user should define a corresponding region for integration.
3, If the output is NaN, the user should check if the function is integrable.
