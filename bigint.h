/*
--------------------------------------------------
Project: a5
File:    bigint.h
Author:  Ryan Tran 169069378 tran9378@mylaurier.ca
Version: 2025-01-09
--------------------------------------------------
*/
 
#ifndef BIGINT_H
#define BIGINT_H
#include "dllist.h"

typedef DLL BIGINT;
BIGINT bigint(char *digitstr);
BIGINT bigint_add(BIGINT oprand1, BIGINT oprand2);
BIGINT bigint_fibonacci(int n);

#endif