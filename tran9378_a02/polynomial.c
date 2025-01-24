/* gcc polynomial.c polynomial_ptest.c -o q2 
--------------------------------------------------
Project: a02
File:   polynomial.c
About:   polynomail source ifle
Author:  ryan tran, 169069378, tran9378@mylaurier.ca
Version: 2025-01-14
--------------------------------------------------
*/

#include "polynomial.h"
#include <stdio.h>

/**
 * Cmpute and return the value of the (n-1)-th degree polynomial
 * p(x) = p[0]*x^{n-1} +  p[1]*x^{n-2} +...+ p[n-2]*x^1 + p[n-1]*x^0
 * using Horner's algorithm (https://en.wikipedia.org/wiki/Horner%27s_method)
 *
 * @param *p - pointer to float number array
 * @param n  - the number of coefficients   
 * @param x - the value to evaluate the polynomial
 * @return - the value of the above polynomial 
 */
float horner(float *p, int n, float x) {
    float result = p[0];
    for(int i=1;i<n;i++) {
        result = result * x + p[i];
    }
    return result;
}
    
/**
 * Cmpute the derivative of input (n-1)-th degree polynomial
 * p(x) = p[0]*x^{n-1} +  p[1]*x^{n-2} +...+ p[n-2]*x^1 + p[n-1]*x^0 
 * output the coefficients of the derivative polynomial in an array. 
 * The derivative of the above polynomial p(x) is as follows.  
 * p'(x) = (n-1)* p[0]*x^{n-2} +  (n-2)*p[1]*x^{n-3} +...+ p[n-2]*x^0
 *
 * @param *p - pointer to coefficient array of input polynomial.
 * @param *d - pointer to coefficient array of output polynomial. 
 * @param n  - the number of coefficients of the input polynomial
 */
void derivative(float *p, float *d, int n) {
    for (int i=0;i<n-1;i++) {
        d[i] = (n - 1 - i) * p[i];
    }
}

/**
 * Compute approximate real root x of polynomial p(x) using Newton's 
 * method(https://en.wikipedia.org/wiki/Newton%27s_method).  
 * Use fault tolerant 1e-6 (or 0.000001) and maximum 100 iterations.
 *
 * @param *p - pointer to coefficient array of input polynomial.
 * @param n  - the number of coefficients of the input polynomial
 * @param x0 - start point for Newton method
 * @return -  the root if found, otherwise x0.
 */

float my_fabs(float x) { //computes absolute value of a float number
    return (x < 0) ? -x : x;
}

float newton(float *p, int n, float x0) {
    float x = x0, px, d[n-1];
    derivative(p, d, n);
    int iterations = 0;
    do {
        x0 = x;
        px = horner(p, n, x);
        float dpx = horner(d, n - 1, x); //computes derivative at x
        if (dpx == 0) {
            break; //avoids division by zero
        }
        x = x - px /dpx; //Update x using Newton's method formula
        iterations++;
    } while(my_fabs(px) > 1e-6 && my_fabs(x - x0) > 1e-6 && iterations <100);
    return x;
}