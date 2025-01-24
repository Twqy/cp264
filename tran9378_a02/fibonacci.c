/*
--------------------------------------------------
Project: a02
File:    fibonacci_ptest.c
About:   fib source ifle
Author:  ryan tran, 169069378, tran9378@mylaurier.ca
Version: 2025-01-14
--------------------------------------------------
*/
#include "fibonacci.h"
#include <stdio.h>

int iterative_fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1;

    for (int i = 1; i < n; i++) {
        int next = a + b;
        a = b;
        b = next;
    }
    return b;
}

int recursive_fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
}

int dpbu_fibonacci(int *f, int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    f[0] = 0; f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[n];
}

int dptd_fibonacci(int *f, int n) {
    if (n <= 1) {
        f[n] = n;
        return n;
    }
    if (f[n] > 0) {
        return f[n];
    } else {
        f[n] = dptd_fibonacci(f, n - 2) + dptd_fibonacci(f, n - 1);
        return f[n];
    }
}