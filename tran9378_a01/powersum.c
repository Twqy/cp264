/** ALL CORRECT
 * -------------------------------------
 * @file powersum.c
 * Assaignment 1 
 * -------------------------------------
 * @author Ryan Tran, 169069378, tran9378@myls
 *
 * @version 2025-01-15
 *
 * -------------------------------------
 */

#include "powersum.h"
//just some global variables
const long long INT_MAX = 2147483647;
const long long INT_MIN = -2147483648;

/**
 * Detect if overflow in power computing of b to power of n  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - 1 if overflow happens, 0 otherwise
 */
int power_overflow(int b, int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= b;
        if (result > INT_MAX || result < INT_MIN) {
            return 1;
        }
    }
    return 0;
}

/**
 * Compute and return b to power of n.  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - b to the power of n if no overflow happens, 0 otherwise
 */
int mypower(int b, int n) {
    long long ans = 1;
    for(int i=0;i<n;i++) {
        ans *= b;
        if (ans > INT_MAX || ans < INT_MIN) {
            return 0; // overflow
        }
    }
    return (int)ans;
}


/**
 * Compute and return the sum of powers.
 *
 * @param b - the base
 * @param n - the exponent
 * @return -  the sum of powers if no overflow happens, 0 otherwise 
 */
int powersum(int b, int n) {
    long long ans = 0;
    long long term = 1;
    for (int i = 0; i <= n; i++) {
        if (i > 0) {
            term *= b;
            if (term > INT_MAX || term < INT_MIN) {
                return 0; // overflow
            }
        }
        ans += term;
        if (ans > INT_MAX || ans < INT_MIN) {
            return 0; // overflow
        }
    }
    return (int)ans;
}
