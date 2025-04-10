/*
--------------------------------------------------
Project: a5q2
File:    dllist.c
Author:  Ryan Tran 169069378 tran9378@mylaurier.ca
Version: 2025-01-09
--------------------------------------------------
*/
 
#include <stdio.h>
#include <stdlib.h> 
#include "dllist.h"

NODE *dll_node(char data) {
// your code
  NODE* n = (NODE *)malloc(sizeof(NODE));
  n->data = data;
  n->next = NULL;
  n->prev = NULL;
  return n;
}

void dll_insert_start(DLL *dllp, NODE *np) {
// your code
  if (dllp->start == NULL) { // when the dllist is empty
    np->prev = NULL;
    np->next =NULL;
    dllp->start = np;
    dllp->end = np;
  } else { // the following linking operations to set np at start
    np->prev= NULL; // this set prev of np to NULL, as start node
    np->next =dllp->start; // set next of np to the current start
    dllp->start->prev = np; // set the prev of current start to np
    dllp->start = np; // set the start of the dllist to np
  }
  dllp->length++;
}

void dll_insert_end(DLL *dllp, NODE *np) {
// your code
  if (dllp->end == NULL) { // when the dllist is empty
    np->prev = NULL;
    np->next = NULL;
    dllp->start = np;
    dllp->end = np;
  } else { // the following linking operations to set np at start
    np->next = NULL; // this set prev of np to NULL, as start node
    np->prev = dllp->end; // set next of np to the current start
    dllp->end->next = np; // set the prev of current start to np
    dllp->end= np; // set the start of the dllist to np
  }
  dllp->length++;
}

void dll_delete_start(DLL *dllp) {
// your code
  NODE *ptr = dllp->start;

  if(ptr == NULL) {
    printf("Underflow on delete_start\n");
  } else {
    dllp->start = ptr->next; 
    if (dllp->start != NULL) { 
      dllp->start->prev = NULL;
    } else {
      dllp->end = NULL; 
    }
    free(ptr);
    dllp->length--;

  }
}

void dll_delete_end(DLL *dllp) {
// your code
  NODE *ptr = dllp->end;

  if(ptr == NULL) {
    printf("Underflow on delete_end\n");
  } else {
    dllp->end = ptr->prev; 

    if (dllp->end != NULL) { 
      dllp->end->next = NULL;
    } else {
      dllp->start = NULL; 
    }

    free(ptr);
    dllp->length--;

  }
}

void dll_clean(DLL *dllp) {
// your code

  NODE *temp, *np =dllp->start;
  while (np != NULL) {
    temp = np;
    np = np->next;
    free(temp);
  }

  dllp->start= NULL;
  dllp->end = NULL;
  dllp->length = 0;
}