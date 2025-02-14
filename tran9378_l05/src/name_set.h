/**
 * -------------------------------------
 * @file  name_set.h
 * Lab 5 Header File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 * @author David Brown, 123456789, dbrown@wlu.ca
 * @author Ryan Tran, 169069378, tran9378@mylaurier.ca
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#ifndef NAME_SET_H_
#define NAME_SET_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN  41           // Max. size of first and last name fields +end byte.

/**
 * name_set node structure.
 */
typedef struct NAME_SET_NODE {
    char first_name[NAME_LEN];  	// Person's first name.
    char last_name[NAME_LEN];	   // Person's last  name.
    struct NAME_SET_NODE *next; 	// Pointer to next node.
} name_set_node;

/**
 * name_set header structure
 */
typedef struct {
    name_set_node *front;	 // Pointer to first node of name_set.
    name_set_node *rear;	  // Pointer to last  node of name_set.
} name_set;

/**
 * Define enumeration type BOOLEAN with value FALSE = 0 and TRUE 1
 */
typedef enum boolean {
    FALSE = 0, TRUE = 1
} BOOLEAN;

// =============================================================================
// Prototypes

/**
 * Initializes and returns an empty name_set.
 * The empty name_set has front and rear pointers set to NULL and
 * count field initialized to zero.
 *
 * @returns pointer to an initialized name_set
 */
name_set* name_set_initialize();

/**
 * Frees all of the nodes in the set, including the header node.
 * Returns a count of the number of nodes freed, including the header node.
 *
 * @param set - pointer to an initialized name_set
 * @return number of nodes freed
 */
int name_set_free(name_set **set);

/**
 * Print the contents of the linked set of names, one name per line in the format:
 * last name, first name
 * ex:
 * Brown, David
 *
 * @param set - pointer to an initialized name_set
 */
void name_set_print(const name_set *set);

/**
 * Appends a name to a name_set, but only if the name is not already present in the set.
 * That is, only unique names are inserted.
 *
 * @param set - pointer to an initialized name_set
 * @param first_name - a first name string
 * @param last_name - a last name string
 * @return TRUE if the name was appended, FALSE otherwise
 */
BOOLEAN name_set_append(name_set *set, const char *first_name, const char *last_name);

/**
 * Determines if a name is already in a name_set.
 *
 * @param set - pointer to an initialized name_set
 * @param first_name - a first name string
 * @param last_name - a last name string
 * @return TRUE if the name in set, FALSE otherwise
 */
BOOLEAN name_set_contains(const name_set *set, const char *first_name, const char *last_name);

#endif
