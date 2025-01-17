/** ALL CORRECT YAYAYAY
 * -------------------------------------
 * @file mychar.c
 * Assaignment 1 Char type and operations
 * -------------------------------------
 * @author Ryan Tran, 169069378, tran9378@myls
 *
 * @version 2025-01-15
 *
 * -------------------------------------
 */

#include "mychar.h"

int mytype(char c) { 
    int answer = -1;
    if(c >= '0' && c <= '9') {
        answer = 0;
    } else if(c >= '*' && c <= '/') {
        answer = 1;
    } else if (c == '(') {
        answer = 2;
    } else if (c == ')') {
        answer = 3;
    } else if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
        answer = 4;
    }
    return answer;
}

char case_flip(char c) {
    if (c >= 'A' && c <= 'Z') {
        c = c + ('a' - 'A');
    } else if (c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
    }
    return c;
}

int digit_to_int(char c) {
    return c - '0';
}