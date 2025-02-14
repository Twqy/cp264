/**
 * -------------------------------------
 * @file  name_set_initialize.c
 * Lab 5 Source Code File
 * -------------------------------------
 * @author Heider Ali, 999999999, heali@wlu.ca
 * @author David Brown, 123456789, dbrown@wlu.ca
 *  @author Ryan Tran, 169069378, tran9378@mylaurier.ca
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "name_set.h"

name_set* name_set_initialize() {
    // Allocate memory to the data structure
    name_set *set = malloc(sizeof *set);
    // Initialize the header fields.
    set->front = NULL;
    set->rear = NULL;
    return set;
}

// Frees all of the nodes in the set, including the header node.
// Returns a count of the number of nodes freed, including the header node
int name_set_free(name_set **set) {
    if (set == NULL || *set == NULL) {
        return 0; 
    }

    int AmountOfNodesFreed = 0;
    name_set_node *CurrentNode = (*set)->front;

    while (CurrentNode != NULL) {
        name_set_node *NextNode = CurrentNode->next;
        free(CurrentNode);
        CurrentNode = NextNode;
        AmountOfNodesFreed++;
    }
    free(*set);
    *set = NULL; 
    return AmountOfNodesFreed + 1; 
}

BOOLEAN name_set_append(name_set *set, const char *first_name, const char *last_name) {
    if (name_set_contains(set, first_name, last_name)) {
        return FALSE; // Name already exists, no append
    }

    // new node
    name_set_node *NewNode = malloc(sizeof(name_set_node));
    if (NewNode == NULL) {
        return FALSE; // Memory allocation failed
    }

    // Copy the first name and last name into the new node
    strncpy(NewNode->first_name, first_name, NAME_LEN - 1);
    NewNode->first_name[NAME_LEN - 1] = '\0'; 
    strncpy(NewNode->last_name, last_name, NAME_LEN - 1);
    NewNode->last_name[NAME_LEN - 1] = '\0'; 

    NewNode->next = NULL;

    // Append new node to end of the linked list
    if (set->rear != NULL) {
        set->rear->next = NewNode;
    } else {
        set->front = NewNode;
    }

    set->rear = NewNode;

    return TRUE; // Name successfully appended
}

BOOLEAN name_set_contains(const name_set *set, const char *first_name, const char *last_name) { //done

    name_set_node *current = set->front;
    while (current != NULL) {
        if ((strcmp(current->first_name, first_name) == 0) && (strcmp(current->last_name, last_name) == 0)) {
            return TRUE; //names found in node
        }
        current = current->next;
    }
    return FALSE; //names not found in node
}

//Print the contents of the linked set of names
//one name per line in the format: last name, first name ex: Brown, David
void name_set_print(const name_set *set) { //done
    // your code here
    name_set_node *current = set->front;
    while (current != NULL) {
        printf("%s, %s\n" , current->last_name, current->first_name);
        if (current->next == NULL) {
            break;
        }
        else {
            current = current->next;
        }
    }
}
