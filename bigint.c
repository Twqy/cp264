/*
--------------------------------------------------
Project: a5 q3
File:    bigint.c
Author:  Ryan Tran 169069378 tran9378@mylaurier.ca
Version: 2025-01-09
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

BIGINT bigint(char *p)
{
  BIGINT bn = {0};
  if (p == NULL)
    return bn;
  else if (!(*p >= '0' && *p <= '9'))
  { // not begin with digits
    return bn;
  }
  else if (*p == '0' && *(p + 1) == '\0')
  { // just "0"
    dll_insert_end(&bn, dll_node(*p - '0'));
    return bn;
  }
  else
  {
    while (*p)
    {
      if (*p >= '0' && *p <= '9')
      {
        dll_insert_end(&bn, dll_node(*p - '0'));
      }
      else
      {
        dll_clean(&bn);
        break;
      }
      p++;
    }
    return bn;
  }
}

BIGINT bigint_add(BIGINT op1, BIGINT op2)
{
  // your code
  BIGINT sum = bigint(NULL);
  NODE *p1 = op1.end;
  NODE *p2 = op2.end;
  int c = 0, a, b, s;
  while (p1 || p2)
  { // addition algorithm
    a = 0;
    b = 0;
    if (p1)
    {
      a = p1->data;
      p1 = p1->prev;
    }
    if (p2)
    {
      b = p2->data;
      p2 = p2->prev;
    }
    // compute the sum digit s and insert it at start of the doubly linked list
    s = a + b + c;
    // printf("%d\n", s);
    if (s >= 10)
    {
      dll_insert_start(&sum, dll_node(s - 10));
      c = 1;
    }
    else
    {
      dll_insert_start(&sum, dll_node(s));
      c = 0;
    }
  }
  if (c == 1) // insert 1 at start of the doubly linked list
    dll_insert_start(&sum, dll_node(c));

  return sum;
}

BIGINT bigint_fibonacci(int n)
{
  // your code
  if (n <= 2)
  {
    return bigint("1");
  }
  else
  {
    BIGINT temp = bigint(NULL);
    BIGINT f1 = bigint("1");
    BIGINT f2 = bigint("1");

    // your implementation of iterative algorithm for Fibonacci number
    for (int i = 3; i <= n; i++)
    {
      temp = f1;
      f1 = f2;
      f2 = bigint_add(temp, f1);
      dll_clean(&temp);
    }

    return f2;
  }
}
