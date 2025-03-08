/**
 * -------------------------------------
 * @file  bst_linked.c
 * Linked BST Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2025-01-06
 *
 * -------------------------------------
 */
#include "bst_linked.h"

// Macro for comparing node heights
#define MAX_HEIGHT(a, b) ((a) > (b) ? a : b)

// Forward declarations of all static helper functions
static bst_node *bst_node_initialize(const data_ptr item);
static int bst_node_height(const bst_node *node);
static void bst_update_height(bst_node *node);
static bool bst_insert_aux(bst_linked *source, bst_node **node, const data_ptr item);
static void bst_free_aux(bst_node **node);
static void bst_inorder_aux(const bst_node *node, data_ptr *items, int *index);
static void bst_preorder_aux(const bst_node *node, data_ptr *items, int *index);
static void bst_postorder_aux(const bst_node *node, data_ptr *items, int *index);
static bool bst_retrieve_aux(const bst_node *node, const data_ptr key, data_ptr item);
static bool bst_remove_aux(bst_linked *source, bst_node **node, const data_ptr key, data_ptr item);
static int bst_leaf_count_aux(const bst_node *node);
static int bst_one_child_count_aux(const bst_node *node);
static int bst_two_child_count_aux(const bst_node *node);
static void bst_node_counts_aux(const bst_node *node, int *zero, int *one, int *two);
static void bst_print_aux(bst_node *node);
static int check_balance_helper(const bst_node *node, int *balanced);
static bool is_valid_bst_helper(const bst_node *node, const data_ptr min_key, const data_ptr max_key);
static bool equals_aux_helper(const bst_node *node1, const bst_node *node2);

//--------------------------------------------------------------------
// Local Functions

/**
 * Initializes a new BST node with a copy of item.
 *
 * @param source pointer to a BST source
 * @param item pointer to the item to assign to the node
 * @return a pointer to a new BST node
 */
static bst_node *bst_node_initialize(const data_ptr item)
{
    // Base case: add a new node containing a copy of item.
    bst_node *node = malloc(sizeof *node);
    node->item = malloc(sizeof *node->item);
    data_copy(node->item, item);
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Helper function to determine the height of node - handles empty node.
 * @param node The node to process.
 * @return The height of the current node.
 */
static int bst_node_height(const bst_node *node)
{
    int height = 0;

    if (node != NULL)
    {
        height = node->height;
    }
    return height;
}

/**
 * Updates the height of a node. Its height is the max of the heights of its
 * child nodes, plus 1.
 * @param node The node to process.
 */
static void bst_update_height(bst_node *node)
{
    int left_height = bst_node_height(node->left);
    int right_height = bst_node_height(node->right);

    node->height = MAX_HEIGHT(left_height, right_height) + 1;
    return;
}

/**
 * Inserts item into a BST. Insertion must preserve the BST definition.
 * item may appear only once in source.
 *
 * @param source - pointer to a BST
 * @param node - pointer to a node
 * @param item - the item to insert
 * @return - true if item inserted, false otherwise
 */
static bool bst_insert_aux(bst_linked *source, bst_node **node, const data_ptr item)
{
    bool inserted = false;

    if (*node == NULL)
    {
        // Base case: add a new node containing the item.
        *node = bst_node_initialize(item);
        source->count += 1;
        inserted = true;
    }
    else
    {
        // Compare the node data_ptr against the new item.
        int comp = data_compare(item, (*node)->item);

        if (comp < 0)
        {
            // General case: check the left subsource.
            inserted = bst_insert_aux(source, &(*node)->left, item);
        }
        else if (comp > 0)
        {
            // General case: check the right subsource.
            inserted = bst_insert_aux(source, &(*node)->right, item);
        }
    }
    if (inserted)
    {
        // Update the node height if any of its children have been changed.
        bst_update_height(*node);
    }
    return inserted;
}

//--------------------------------------------------------------------
// Functions

// Initializes a BST.
bst_linked *bst_initialize()
{
    bst_linked *source = malloc(sizeof *source);
    source->root = NULL;
    source->count = 0;
    return source;
}

// frees a BST.
void bst_free(bst_linked **source)
{
    if (source == NULL || *source == NULL)
    {
        return;
    }
    bst_free_aux(&(*source)->root);
    free(*source);
    *source = NULL;
}

// Then later in the file, make bst_free_aux static:
static void bst_free_aux(bst_node **node)
{
    if (*node == NULL)
    {
        return;
    }
    bst_free_aux(&(*node)->left);
    bst_free_aux(&(*node)->right);
    free((*node)->item);
    free(*node);
    *node = NULL;
}

// Determines if a BST is empty.
bool bst_empty(const bst_linked *source)
{
    // your code here
    return (source->root == NULL);
}

// Determines if a BST is full.
bool bst_full(const bst_linked *source)
{
    return false;
}

// Returns number of items in a BST.
int bst_count(const bst_linked *source)
{
    // your code here
    return source->count;
}

// Copies the contents of a BST to an array in inorder.
void bst_inorder(const bst_linked *source, data_ptr *items)
{
    if (source == NULL || source->root == NULL)
    {
        return;
    }

    int index = 0;
    bst_inorder_aux(source->root, items, &index);
    return;
}

static void bst_inorder_aux(const bst_node *node, data_ptr *items, int *index)
{
    if (node == NULL)
    {
        return;
    }

    bst_inorder_aux(node->left, items, index);

    if (items[*index] == NULL)
    {
        items[*index] = malloc(sizeof(int));
        if (items[*index] == NULL)
        {
            return;
        }
    }

    data_copy(items[*index], node->item);
    (*index)++;
    bst_inorder_aux(node->right, items, index);
}

void bst_preorder(const bst_linked *source, data_ptr *items)
{
    // your code here
    int index = 0;
    bst_preorder_aux(source->root, items, &index);
    return;
}

static void bst_preorder_aux(const bst_node *node, data_ptr *items, int *index)
{
    if (node == NULL)
    {
        return;
    }

    if (items[*index] == NULL)
    {
        items[*index] = malloc(sizeof(int));
    }
    data_copy(items[*index], node->item);

    (*index)++;
    bst_preorder_aux(node->left, items, index);
    bst_preorder_aux(node->right, items, index);
    return;
}

// Copies the contents of a BST to an array in postorder.
void bst_postorder(const bst_linked *source, data_ptr *items)
{
    // your code here
    int index = 0;
    bst_postorder_aux(source->root, items, &index);
    return;
}

static void bst_postorder_aux(const bst_node *node, data_ptr *items, int *index)
{
    if (node == NULL)
    {
        return;
    }
    bst_postorder_aux(node->left, items, index);
    bst_postorder_aux(node->right, items, index);
    // Add memory allocation before copying data
    if (items[*index] == NULL)
    {
        items[*index] = malloc(sizeof(int));
    }
    data_copy(items[*index], node->item);

    (*index)++;
    return;
}

bool bst_insert(bst_linked *source, const data_ptr item)
{
    return bst_insert_aux(source, &(source->root), item);
}

// Retrieves a copy of a value matching key in a BST.
bool bst_retrieve(bst_linked *source, const data_ptr key, data_ptr item)
{
    // your code here
    if (source == NULL)
    {
        return false;
    }
    return bst_retrieve_aux(source->root, key, item);
}

static bool bst_retrieve_aux(const bst_node *node, const data_ptr key, data_ptr item)
{
    if (node == NULL)
    {
        return false;
    }

    int comp = data_compare(key, node->item);
    if (comp == 0)
    {
        data_copy(item, node->item);
        return true;
    }
    else if (comp < 0)
    {
        return bst_retrieve_aux(node->left, key, item);
    }
    else
    {
        return bst_retrieve_aux(node->right, key, item);
    }
}

// Removes a value matching key in a BST.
bool bst_remove(bst_linked *source, const data_ptr key, data_ptr item)
{
    if (source == NULL)
    {
        return false;
    }
    bool removed = bst_remove_aux(source, &(source->root), key, item);
    if (removed)
    {
        source->count--;
    }
    return removed; // Always return the result
}

static bool bst_remove_aux(bst_linked *source, bst_node **node, const data_ptr key, data_ptr item)
{
    if (*node == NULL)
    {
        return false;
    }
    int comp = data_compare((*node)->item, key);

    if (comp < 0)
    {
        return bst_remove_aux(source, &(*node)->left, key, item); // Add return
    }
    else if (comp > 0)
    {
        return bst_remove_aux(source, &(*node)->right, key, item); // Add return
    }
    else // node is found
    {
        data_copy(item, (*node)->item);
        // case: leaf node (no children)
        if ((*node)->left == NULL && (*node)->right == NULL)
        {
            free((*node)->item);
            free(*node);
            *node = NULL;
            return true;
        }
        // case: only left child
        if ((*node)->left && (*node)->right == NULL)
        {
            bst_node *temp = *node;
            *node = (*node)->left;
            free(temp->item);
            free(temp);
            return true;
        }
        // case: only right child
        else if ((*node)->left == NULL && (*node)->right)
        {
            bst_node *temp = *node;
            *node = (*node)->right;
            free(temp->item);
            free(temp);
            return true;
        }
        // case: parent with two children
        else
        {
            // Find successor (minimum in right subtree)
            bst_node **successor = &((*node)->right);
            while ((*successor)->left != NULL)
            {
                successor = &((*successor)->left);
            }
            free((*node)->item);
            (*node)->item = malloc(sizeof(data_ptr));
            data_copy((*node)->item, (*successor)->item);
            // Remove successor
            bst_node *temp = *successor;
            *successor = (*successor)->right; // Handle successor's right child
            free(temp->item);
            free(temp);
            // Update height
            bst_update_height(*node);
            return true;
        }
    }
    return true;
}

// Copies source to target.
void bst_copy(bst_linked **target, const bst_linked *source)
{

    // your code here
    return;
}

// Finds the maximum item in a BST.
bool bst_max(const bst_linked *source, data_ptr item)
{
    // your code here
    if (source == NULL || source->root == NULL)
    {
        return false;
    }

    bst_node *node = source->root;
    while (node->right != NULL)
    {
        node = node->right;
    }
    data_copy(item, node->item);
    return true;
}

// Finds the minimum item in a BST.
bool bst_min(const bst_linked *source, data_ptr item)
{
    // your code here
    if (source == NULL || source->root == NULL)
    {
        return false;
    }

    bst_node *node = source->root;
    while (node->left != NULL)
    {
        node = node->left;
    }
    data_copy(item, node->item);
    return true;
}

// Finds the number of leaf nodes in a tree.
int bst_leaf_count(const bst_linked *source)
{
    // your code here
    if (source == NULL || source->root == NULL)
    {
        return 0;
    }
    bst_node *node = source->root;
    return bst_leaf_count_aux(node);
}

static int bst_leaf_count_aux(const bst_node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) // only root node
    {
        return 1;
    }

    return bst_leaf_count_aux(node->left) + bst_leaf_count_aux(node->right);
}

// Finds the number of nodes with one child in a tree.
int bst_one_child_count(const bst_linked *source)
{
    // your code here
    if (source == NULL || source->root == NULL)
    {
        return 0;
    }
    return bst_one_child_count_aux(source->root);
}

// Helper function for one-child count
static int bst_one_child_count_aux(const bst_node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    // Check if this node has exactly one child (XOR logic)
    int count = 0;
    if ((node->left != NULL && node->right == NULL) ||
        (node->left == NULL && node->right != NULL))
    {
        count = 1;
    }

    // Add counts from both subtrees
    return count + bst_one_child_count_aux(node->left) +
           bst_one_child_count_aux(node->right);
}

// Finds the number of nodes with two children in a tree.
int bst_two_child_count(const bst_linked *source)
{
    // your code here
    if (source == NULL || source->root == NULL)
    {
        return 0;
    }
    return bst_two_child_count_aux(source->root);
}

// Helper function for two-child count
static int bst_two_child_count_aux(const bst_node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    // Check if this node has exactly two children
    int count = 0;
    if (node->left != NULL && node->right != NULL)
    {
        count = 1;
    }

    // Add counts from both subtrees
    return count + bst_two_child_count_aux(node->left) +
           bst_two_child_count_aux(node->right);
}

// Determines the number of nodes with zero, one, and two children.
void bst_node_counts(const bst_linked *source, int *zero, int *one, int *two)
{
    // Initialize counts
    *zero = 0;
    *one = 0;
    *two = 0;

    if (source == NULL || source->root == NULL)
    {
        return;
    }

    // Use a helper function to count all node types in one traversal
    bst_node_counts_aux(source->root, zero, one, two);
    return;
}

// Helper function to count all node types in one pass
static void bst_node_counts_aux(const bst_node *node, int *zero, int *one, int *two)
{
    if (node == NULL)
    {
        return;
    }

    // Categorize the current node
    if (node->left == NULL && node->right == NULL)
    {
        (*zero)++; // Leaf node (zero children)
    }
    else if (node->left != NULL && node->right != NULL)
    {
        (*two)++; // Two children
    }
    else
    {
        (*one)++; // One child
    }

    // Recursively count in subtrees
    bst_node_counts_aux(node->left, zero, one, two);
    bst_node_counts_aux(node->right, zero, one, two);
}

// Determines whether or not a tree is a balanced tree.
bool bst_balanced(const bst_linked *source)
{
    if (source == NULL || source->root == NULL)
    {
        return true;
    }

    int balanced = 1;
    check_balance_helper(source->root, &balanced);
    return balanced == 1;
}

static int check_balance_helper(const bst_node *node, int *balanced)
{
    if (node == NULL)
    {
        return 0;
    }

    int left_height = check_balance_helper(node->left, balanced);
    int right_height = check_balance_helper(node->right, balanced);

    if (*balanced == 0 || left_height == -1 || right_height == -1)
    {
        *balanced = 0;
        return -1;
    }

    if (abs(left_height - right_height) > 1)
    {
        *balanced = 0;
        return -1;
    }

    return 1 + (left_height > right_height ? left_height : right_height);
}

// Determines whether or not a tree is a valid BST.
bool bst_valid(const bst_linked *source)
{
    if (source == NULL || source->root == NULL)
    {
        return true;
    }

    return is_valid_bst_helper(source->root, NULL, NULL);
}

static bool is_valid_bst_helper(const bst_node *node, const data_ptr min_key, const data_ptr max_key)
{
    if (node == NULL)
    {
        return true;
    }

    if ((min_key != NULL && data_compare(node->item, min_key) <= 0) ||
        (max_key != NULL && data_compare(node->item, max_key) >= 0))
    {
        return false;
    }

    return is_valid_bst_helper(node->left, min_key, node->item) &&
           is_valid_bst_helper(node->right, node->item, max_key);
}

// Determines if two trees contain same data in same configuration.
bool bst_equals(const bst_linked *target, const bst_linked *source)
{
    if (source == NULL && target == NULL)
    {
        return true;
    }
    if (source == NULL || target == NULL)
    {
        return false;
    }
    if (source->count != target->count)
    {
        return false;
    }

    return equals_aux_helper(source->root, target->root);
}

static bool equals_aux_helper(const bst_node *node1, const bst_node *node2)
{
    if (node1 == NULL && node2 == NULL)
    {
        return true;
    }

    if (node1 == NULL || node2 == NULL)
    {
        return false;
    }

    if (data_compare(node1->item, node2->item) != 0)
    {
        return false;
    }

    return equals_aux_helper(node1->left, node2->left) &&
           equals_aux_helper(node1->right, node2->right);
}

/**
 * Private helper function to print contents of BS in preorder.
 *
 * @param to_string - function to print data_ptr
 * @param node - pointer to bst_node
 */
static void bst_print_aux(bst_node *node)
{
    char string[DATA_STRING_SIZE];

    if (node != NULL)
    {
        data_string(string, DATA_STRING_SIZE, node->item);
        printf("%s\n", string);
        bst_print_aux(node->left);
        bst_print_aux(node->right);
    }
    return;
}

// Prints the items in a BST in preorder.
void bst_print(const bst_linked *source)
{
    printf("  count: %d, height: %d, items:\n", source->count, source->root->height);
    bst_print_aux(source->root);
    printf("\n");
    return;
}
