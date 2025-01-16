/**
 * -------------------------------------
 * @file  parameters.h
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-05
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef PARAMETERS_H_
#define PARAMETERS_H_

// Prototypes.

/**
 * Prints all parameters passed on command line.
 *
 * @param argc - count of elements in args
 * @param args - array of strings
 */
void parameters(int argc, char *const argv[]);

#endif /* PARAMETERS_H_ */
