/*
--------------------------------------------------
Project: a5q1
File:    myrecord_slist.c
Author:  Ryan Tran 169069378 tran9378@mylaurier.ca
Version: 2025-01-09
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myrecord_sllist.h"

NODE *sll_search(SLL *sllp, char *name)
{

  NODE *np = sllp->start;
  while (np != NULL)
  {
    if (strcmp(np->data.name, name) == 0) // if pattern match
      return np;                          // action
    np = np->next;
  }
  return np;
}

void sll_insert(SLL *sllp, char *name, float score)
{
  // your code

  NODE *p = (NODE *)malloc(sizeof(NODE));
  strcpy(p->data.name, name);
  p->data.score = score;
  p->next = NULL;
  NODE *prev = NULL;
  NODE *ptr = sllp->start;
  while (ptr != NULL)
  {
    if (strcmp(ptr->data.name, name) >= 0) // found the node
      break;                               // action
    prev = ptr;                            // move to next
    ptr = ptr->next;                       // move to next
  }
  if (prev == NULL)
  {                  // empty linked list or found at start
    sllp->start = p; // insert at beginning
    p->next = ptr;
  }
  else
  {                 // found the node or not found, i.e. ptr = NULL
    prev->next = p; // insert between bewteen prev and ptr,
    p->next = ptr;
  }
  sllp->length++;
}

int sll_delete(SLL *sllp, char *name)
{

  int found = 0;
  NODE *prev = NULL;
  NODE *ptr = sllp->start;
  while (ptr != NULL)
  {
    if (strcmp(ptr->data.name, name) == 0)
    { // found the node
      found = 1;
      if (prev == NULL)
      {
        sllp->start = ptr->next;
      }
      else
      {
        prev->next = ptr->next;
      }
      free(ptr);

      sllp->length--;
      break; // action
    }
    prev = ptr;      // move to next
    ptr = ptr->next; // move to next
  }
  return found;
}

void sll_clean(SLL *sllp)
{
  NODE *temp, *ptr = sllp->start;
  while (ptr != NULL)
  {
    temp = ptr;
    ptr = ptr->next;
    free(temp);
  }
  sllp->start = NULL;
  sllp->length = 0;
}