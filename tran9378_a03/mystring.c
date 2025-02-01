/*
--------------------------------------------------
Project: assaignment 3
File:    mystring.c
Author:  Ryan Tran
Version: 2025-01-09
--------------------------------------------------
*/
#include "mystring.h"

/**
 * Count the number of words in a given simple string. A word starts with an English character and ends with a character of space, tab, comma, or period.
 *
 * @param s - char pointer to a string
 * @return - return the number of words.
 */
int str_words(char *s) { //works 
    int num = 0;
    int i = 0;
    int is_valid = 0;

    while (s[i] != '\0') {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            if (!is_valid) {
                is_valid = 1;
                num++;
            }
        } else if (s[i] == ' ' || s[i] == '\t' || s[i] == ',' || s[i] == '.') {
            is_valid = 0;
        }
        i++;
    }

    return num;
}

/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a string
 * @return - return the number of actual flips.
 */
int str_lower(char *s) {
    int flips = 0;
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + ('a' - 'A');
            flips++;
        }
        i++;
    }

    return flips;
}

/** 
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a string
 */
void str_trim(char *s) {
    int i = 0, j = 0;
    int space_found = 0;

    while (s[i] != '\0') {
        if (s[i] != ' ') {
            s[j++] = s[i];
            space_found = 0;
        } else if (!space_found) {
            s[j++] = s[i];
            space_found = 1;
        }
        i++;
    }

    if (j > 0 && s[j - 1] == ' ') {
        j--;
    }

    s[j] = '\0';
}

//gcc mystring.c mystring_ptest.c -o q1