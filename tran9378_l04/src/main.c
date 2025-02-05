/**
 * -------------------------------------
 * @file  main.c
 * Lab 4 Main Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 * DO NOT CHANGE
 */
#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

#define SIZE 128

void test_strings_with_substring(strings_array *data) {
    printf("------------------------\n");
    printf("Test strings_with_substring\n\n");
    char substring[MAX_LINE] = "";
    printf("Enter substring: ");
    scanf("%128s", substring);
    strings_with_substring(data, substring);
}

void test_strings_length(strings_array *data) {
    printf("------------------------\n");
    printf("Test strings_length\n\n");

    FILE *fp_short = fopen("short.txt", "w");
    FILE *fp_long = fopen("long.txt", "w");
    int length = 0;
    printf("Enter the length comparison value: ");
    scanf("%d", &length);
    strings_length(data, fp_short, fp_long, length);
    fclose(fp_short);
    fclose(fp_long);
}

/**
 * Test the file and string functions.
 *
 * @param argc - unused
 * @param args - unused
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    strings_array *data = initialize_strings_array(SIZE);

    printf("------------------------\n");
    printf("Test read_strings\n\n");
    FILE *fp = fopen("data.txt", "r");
    int lines = read_strings(data, fp);
    fclose(fp);

    if(lines == MALLOC_FAILED) {
        printf("Could not allocate string memory.\n");
    } else if(lines == TOO_MANY_LINES) {
        printf("Size of string array exceeded.\n");
    } else {
        printf("lines read: %d\n\n", lines);
        printf("Contents of string array\n");
        printf("------------------------\n");

        for(int i = 0; i < data->lines; i++) {
            printf("%s\n", data->strings[i]);
        }
        printf("\n");

        test_strings_with_substring(data);
        test_strings_length(data);
    }
    free_strings_array(&data);

    return (EXIT_SUCCESS);
}
