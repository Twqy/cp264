/**
 * -------------------------------------
 * @file  main.c
 * Lab 5 Source Code File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 * @author David Brown, 123456789, dbrown@wlu.ca
 * @author Ryan Tran, 169069378, tran9378@mylaurier.ca
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "name_set.h"
#define NAME_LEN  41
#define MAX_LINE (NAME_LEN * 2 + 2)

/**
 * Testing for name_set structure.
 *
 * @param argc - unused
 * @param argv - unused
 * @return
 */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    char *filename = "names.txt";    // Input file name.
    FILE *fp = NULL;           // Input file pointer.
    int return_val = EXIT_SUCCESS;

    if((fp = fopen(filename, "r")) != NULL) {
        // File open was successful!

        // define to avoid "Format string vulnerability in sscanf" warning
        // ex: "%40s %40s"
        char read_format[16] = "";
        sprintf(read_format, "%%%ds %%%ds", NAME_LEN - 1, NAME_LEN - 1);

        // Initialize the name_set object
        name_set *set = name_set_initialize();
        // Local storage for the current line of text
        char line[MAX_LINE] = "";
        char first_name[NAME_LEN] = "";
        char last_name[NAME_LEN] = "";
        BOOLEAN appended = FALSE;
        printf("Reading names from file:\n");

        // Keep reading and appending until reach EOF (End-Of-File).
        while(fgets(line, sizeof line, fp) != NULL) {
            sscanf(line, read_format, first_name, last_name);
            appended = name_set_append(set, first_name, last_name);

            if(appended) {
                printf("%s, %s: appended to set\n", last_name, first_name);
            } else {
                printf("%s, %s: already in set\n", last_name, first_name);
            }
        }
        fclose(fp);
        printf("\nNames in set:\n");
        name_set_print(set);

        printf("\nIs most recent name in set?\n");
        BOOLEAN contains = name_set_contains(set, first_name, last_name);

        if(contains) {
            printf("%s, %s: is in set\n", last_name, first_name);
        } else {
            printf("%s, %s: not in set\n", last_name, first_name);
        }

        printf("\nAttempt to re-append most recent name:\n");
        appended = name_set_append(set, first_name, last_name);

        if(appended) {
            printf("%s, %s: appended to set\n", last_name, first_name);
        } else {
            printf("%s, %s: already in set\n", last_name, first_name);
        }

        // Free the set.
        int freed = name_set_free(&set);
        printf("\nFreed %d nodes\n", freed);
        printf("set header: %p\n", (void*) set);
    } else {
        // Open input file and check if open is successful.
        printf("Cannot open file: %s\n", filename);
        // Get set to have Main return an ERROR condition to OS.
        return_val = -1;
    }
    return return_val;
}
