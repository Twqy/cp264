/**
 * -------------------------------------
 * @file  main.c
 * Lab 10 Main Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include <math.h>
#include <time.h>

#include "graph_am.h"

#define TEST_SIZE 6
#define GRAPH_AM_MAX 8

#define SEP "-------------------------------\n"

/**
 * FOR TESTING
 * Fill an array with pairs of random row and column values for the creation
 * of an adjacency matrix graph.
 *
 * @param size - width/height of adjacency matrix
 * @param pairs - array of row/column pairs
 * @param count - size of pairs
 */
void random_pairs(int size, graph_am_pair *pairs, int count) {
    // See the random number generator
    srand(time(NULL));

    for(int i = 0; i < count; i++) {
        pairs[i].row = rand() % size;
        pairs[i].col = rand() % size;
    }
    return;
}

/**
 * FOR TESTING
 * Prints array of integer.
 *
 * @param vertices
 * @param count
 */
void print_array(int *vertices, int count) {
    printf("{");

    for(int i = 0; i < count; i++) {
        printf("%d, ", vertices[i]);
    }
    printf("}");
}

/**
 * Test the graph_am functions.
 */
void test_graph(void) {
    graph_am_pair pairs[TEST_SIZE];

    printf(SEP);
    printf("Create an adjacency matrix graph:\n");
    // Create an array of random pairs
    random_pairs(GRAPH_AM_MAX, pairs, TEST_SIZE);
    // Add these pairs to an adjacency graph
    graph_am *source = graph_am_create(GRAPH_AM_MAX, pairs, TEST_SIZE);
    graph_am_print(source);
    printf(SEP);
    printf("Degrees of graph:\n");
    printf("Vertex Degree\n");

    for(int i = 0; i < GRAPH_AM_MAX; i++) {
        int degree = graph_am_degree(source, i);
        printf("%6d %6d\n", i, degree);
    }
    printf(SEP);
    printf("Neighbours in graph:\n");
    printf("Vertex Neighbours\n");

    for(int i = 0; i < GRAPH_AM_MAX; i++) {
        int vertices[GRAPH_AM_MAX];
        int count = 0;
        graph_am_neighbours(source, i, vertices, &count);
        printf("%6d ", i);
        print_array(vertices, count);
        printf("\n");
    }
    printf(SEP);
    printf("Breadth First Traversal:\n");
    printf("Vertex Traversal\n");

    for(int i = 0; i < GRAPH_AM_MAX; i++) {
        int vertices[GRAPH_AM_MAX];
        int count = 0;
        graph_am_breadth_traversal(source, i, vertices, &count);
        printf("%6d ", i);
        print_array(vertices, count);
        printf("\n");
    }

    printf(SEP);
    printf("Depth First Traversal:\n");
    printf("Vertex Traversal\n");

    for(int i = 0; i < GRAPH_AM_MAX; i++) {
        int vertices[GRAPH_AM_MAX];
        int count = 0;
        graph_am_depth_traversal(source, i, vertices, &count);
        printf("%6d ", i);
        print_array(vertices, count);
        printf("\n");
    }
    printf(SEP);
    printf("Remove all vertices:\n");

    for(int i = 0; i < TEST_SIZE; i++) {
        graph_am_pair *pair = &pairs[i];
        int removed = graph_am_remove_vertice(source, pair);
        printf("removed {%d, %d}: %d\n", pair->row, pair->col, removed);
    }
    printf("\n");
    graph_am_print(source);
}

/**
 * @param argc - unused
 * @param argv - unused
 * @return EXIT_SUCCESS
 */
int main(int argc, char *argv[]) {
    setbuf(stdout, NULL);

    test_graph();
    return (EXIT_SUCCESS);
}
