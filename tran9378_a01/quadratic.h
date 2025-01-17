/**
 * -------------------------------------
 * @file quadratic.h
 * Assaignment 1 
 * -------------------------------------
 * @author Ryan Tran, 169069378, tran9378@myls
 *
 * @version 2025-01-15
 *
 * -------------------------------------
 */

/**
 * Compute and return solution type of given quadratic equation ax*x + bx + c = 0
 *
 * @param a  - quadratic coefficient
 * @param b  - linear coefficient
 * @param c - constant coefficient
 * @return - 0 if not quadratic equation, i.e. a=0;
 *           1 for one unique real solution;
 *           2 for two distinct real solutions;
 *           3 for two complex solutiions
 */
int solution_type(float a, float b, float c);

/**
 * Compute and return unique or bigger real roots of given quadratic equation ax*x + bx + c = 0 of types 1 and 2.
 * @param a  - quadratic coefficient
 * @param b  - linear coefficient 
 * @param c - constant coefficient
 * @return - the unique real root or the bigger real root if the quadratic equation has two distinct real roots 
             Ohterwise, return 0.
 */
float real_root_big(float a, float b, float c);

/**
 * Compute and return unique or smaller real roots of given quadratic equation ax*x + bx + c = 0 of types 1 and 2.
 * @param a  - quadratic coefficient
 * @param b  - linear coefficient 
 * @param c - constant coefficient
 * @return - 0 if not a == 0
             1 if having two complex solutions
             2 if            the unique real root or the smaller real root if the quadratic equation has two distinct real roots 
             Ohterwise, return 0.
 */
float real_root_small(float a, float b, float c);