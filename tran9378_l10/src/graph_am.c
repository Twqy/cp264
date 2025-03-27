/**
 * -------------------------------------
 * @file  graph_am.c
 * Adjacency Matrix Graph Code File
 * -------------------------------------
 * @author Ryan Tran, 169069378, tran9378@mylaurier.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "graph_am.h"

// Initializes an adjacency matrix graph.
graph_am *graph_am_initialize(int size)
{
    graph_am *source = malloc(sizeof *source);
    source->size = size;
    // Initialize values to zeroes.
    source->values = calloc(size * size, sizeof *source->values);
    return source;
}

void graph_am_free(graph_am **source)
{
    // Free up the data array.
    free((*source)->values);
    (*source)->values = NULL;
    free(*source);
    *source = NULL;
    return;
}

int graph_am_add_vertice(graph_am *source, const graph_am_pair *pair)
{
    // your code here
    if (source == NULL || pair == NULL)
    {
        return 0;
    }
    if (*(source->values + pair->row * source->size + pair->col) == 1)
    {
        return 0;
    }
    if ((pair->row < 0 || pair->row >= source->size) || (pair->col < 0 || pair->col >= source->size))
    {
        return 0;
    }
    if (pair->col == pair->row)
    {
        *(source->values + pair->row * source->size + pair->col) = 2;
        return 1;
    }
    // since the pair is valid, set the pair adjacency to 1
    *(source->values + pair->row * source->size + pair->col) = 1;
    *(source->values + pair->col * source->size + pair->row) = 1;

    return 1;
}

int graph_am_remove_vertice(graph_am *source, const graph_am_pair *pair) // full marks
{
    // your code here
    if (source == NULL || pair == NULL)
    {
        return 0;
    }
    if ((pair->col < 0 || pair->row >= source->size) || (pair->col < 0 || pair->col >= source->size))
    {
        return 0;
    }

    *(source->values + pair->col * source->size + pair->row) = 0;
    *(source->values + pair->row * source->size + pair->col) = 0;

    return 1;
}

graph_am *graph_am_create(int size, const graph_am_pair pairs[], int count)
{
    // your code here
    if (size <= 0 || pairs == NULL || count < 0)
    {
        return NULL;
    }

    graph_am *source = graph_am_initialize(size);
    if (source == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < count; i++)
    {
        const graph_am_pair *pair = &pairs[i];
        graph_am_add_vertice(source, pair);
    }
    return source;
}

void graph_am_neighbours(const graph_am *source, int vertex, int vertices[], int *count)
{

    // your code here
    if (source == NULL || vertex < 0)
    {
        *count = 0;
        return NULL;
    }
    *count = 0;
    // with the vertex index, traverse its column. if adjacent, add to list
    for (int i = 0; i < source->size; i++)
    {
        // index = row * size + col
        int index = vertex * source->size + i;
        if (*(source->values + index) > 0)
        {
            vertices[*count] = i;
            (*count)++;
        }
    }
}

int graph_am_degree(const graph_am *source, int vertex)
{
    int connected = 0;

    // your code here
    if (source == NULL || vertex < 0 || vertex >= source->size)
    {
        return -1;
    }
    for (int i = 0; i < source->size; i++)
    {
        int index = vertex * source->size + i;
        if (*(source->values + index) == 1)
        {
            connected += 1;
        }
        else if (*(source->values + index) == 2)
        {
            connected += 2;
        }
    }
    return connected;
}

void graph_am_breadth_traversal(const graph_am *source, int vertex, int vertices[], int *count)
{

    // your code here
    if (source == NULL || vertex < 0 || vertex >= source->size)
    {
        *count = 0;
        return NULL;
    }

    int visited[source->size];
    for (int i = 0; i < source->size; i++)
    {
        visited[i] = 0; // mark all as unvisited
    }

    int queue[source->size];
    int front = 0, rear = 0;

    *count = 0;
    // process first node
    visited[vertex] = 1;
    queue[rear++] = vertex;

    // process the rest of the tree
    while (front < rear) // while queue not empty
    {
        int current = queue[front++];
        vertices[(*count)++] = current;

        for (int i = 0; i < source->size; i++)
        {
            int index = current * source->size + i;
            if (*(source->values + index) > 0 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void graph_am_depth_traversal(const graph_am *source, int vertex, int vertices[], int *count)
{

    // your code here
    if (source == NULL || vertex < 0 || vertex >= source->size || vertices == NULL || count == NULL)
    {
        *count = 0;
        return;
    }

    int visited[source->size];
    for (int i = 0; i < source->size; i++)
    {
        visited[i] = 0;
    }

    // initialize stack
    int stack[source->size];
    int top = -1;
    *count = 0;

    // process vertex
    visited[vertex] = 1;
    stack[++top] = vertex;

    while (top >= 0)
    {
        int current = stack[top--];
        vertices[(*count)++] = current;

        for (int i = 0; i < source->size; i++)
        {
            int index = current * source->size + i;
            if (*(source->values + index) > 0 && !visited[i])
            {
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }

    return;
}

// Prints the contents of an adjacency matrix graph.
void graph_am_print(const graph_am *source)
{
    // Print the column numbers.
    printf("    ");

    for (int i = 0; i < source->size; i++)
        printf("%3d", i);
    printf("\n");
    printf("    ");
    for (int i = 0; i < source->size; i++)
        printf("---");
    printf("\n");

    // Print the row numbers and rows.
    for (int i = 0; i < source->size; i++)
    {
        printf("%3d|", i);

        for (int j = 0; j < source->size; j++)
        {
            // find item using offsets
            printf("%3d", *(source->values + i * source->size + j));
        }
        printf("\n");
    }
}
