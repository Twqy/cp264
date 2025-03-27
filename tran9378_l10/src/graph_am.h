/**
 * -------------------------------------
 * @file  graph_am.h
 * Adjacency Matrix Graph Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef GRAPH_AM_H_
#define GRAPH_AM_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * Stores row/col pairs of adjacency matrix values.
 */
typedef struct {
    int row;
    int col;
} graph_am_pair;

/**
 * Adjacency Matrix Graph header.
 */
typedef struct {
    int size;       // size (width/height) of adjacency matrix
    int *values;    // pointer to 2D array of values
} graph_am;

/**
 * Initializes an adjacency matrix graph.
 *
 * @param source - pointer to a graph
 * @param size - height and width of the graph matrix
 */
graph_am* graph_am_initialize(int size);

/**
 * Frees the contents of an adjacency matrix graph.
 *
 * @param source - pointer to a graph
 */
void graph_am_free(graph_am **source);

/**
 * Adds a vertice to source. Fails if pair values invalid or vertice already in source.
 * Pairs containing row < 0 or row >= size are ignored;
 * Pairs containing col < 0 or col >= size are ignored;
 * Pairs containing row == col are a loop and are given a value of 2;
 * All other pairs are given a value of 1 in [row][col] and [col][row].
 *
 * @param source - pointer to a graph
 * @param pair - pointer to vertice to add to source
 * @return - 1 if the vertice was added, 0 otherwise
 */
int graph_am_add_vertice(graph_am *source, const graph_am_pair *pair);

/**
 * Removes an vertice from source. Fails if pair values invalid or vertice not in source.
 * Pairs containing row < 0 or row >= size are ignored;
 * Pairs containing col < 0 or col >= size are ignored;
 *
 * @param source - pointer to a graph
 * @param pair - pointer to vertice to remove from source
 * @return - 1 if the vertice was removed, 0 otherwise
 */
int graph_am_remove_vertice(graph_am *source, const graph_am_pair *pair);

/**
 * Creates a graph from an array of vertex pairs.
 * Pairs containing row < 0 or row >= size are ignored;
 * Pairs containing col < 0 or col >= size are ignored;
 * Pairs containing row == col are a loop and is given a value of 2;
 * All other pairs are given a value of 1 in [row][col] and [col][row].
 * The resulting matrix is symmetrical.
 *
 * @param source - pointer to a graph
 * @param pairs - array of vertex pairs
 * @param count - number of values in pairs
 */
graph_am* graph_am_create(int size, const graph_am_pair pairs[], int count);

/**
 * Returns an array of all vertices connected to a vertex.
 * vertices must be defined with a size of source->size.
 *
 * @param source - pointer to a graph
 * @param vertex - index of a vertex
 * @param vertices - array of neighbours
 * @param count - number of vertices
 */
void graph_am_neighbours(const graph_am *source, int vertex, int vertices[], int *count);

/**
 * Returns number of vertices connected to vertex.
 *
 * @param source - pointer to a graph
 * @param vertex - index of a vertex
 * @return - number of vertices connected to vertex
 */
int graph_am_degree(const graph_am *source, int vertex);

/**
 * Performs a breadth-first traversal of a graph. Copies
 *
 * @param source - pointer to a graph
 * @param vertex - index of a vertex to start traversal from
 * @param vertices - array of resulting vertices
 * @param count - number of items in vertices
 */
void graph_am_breadth_traversal(const graph_am *source, int vertex, int vertices[], int *count);

/**
 * Performs a depth-first traversal of a graph.
 *
 * @param source - pointer to a graph
 * @param vertex - index of a vertex to start traversal from
 * @param vertices - array of resulting vertices
 * @param count - number of items in vertices
 */
void graph_am_depth_traversal(const graph_am *source, int vertex, int vertices[], int *count);

/**
 * FOR TESTING
 * Prints the contents of an adjacency matrix graph.
 *
 * @param source - pointer to a graph
 */
void graph_am_print(const graph_am *source);

#endif /* GRAPH_AM_H_ */
