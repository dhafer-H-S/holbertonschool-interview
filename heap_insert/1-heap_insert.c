#include "binary_trees.h"

/**
 * heapify_up - Maintains the max heap property by moving the newly inserted
 *               node up to its correct position.
 * @node: Pointer to the node to heapify up.
 *
 * Return: Pointer to the node that has been moved to its correct position.
 */
heap_t *heapify_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        /* Swap node with its parent */
        int temp = node->n;
        node->n = node->parent->n;
        node->parent->n = temp;
        node = node->parent;
    }
    return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the newly inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent, *current;

    if (!root)
        return (NULL);

    new_node = binary_tree_node(NULL, value);
    if (!new_node)
        return (NULL);

    if (!*root)
    {
        *root = new_node;
        return (new_node);
    }

    /* Traverse the heap to find the appropriate position to insert the new node */
    parent = NULL;
    current = *root;
    while (current)
    {
        parent = current;
        current = current->left;
    }

    if (!parent->left)
        parent->left = new_node;
    else
        parent->right = new_node;
    new_node->parent = parent;

    return (heapify_up(new_node));
}
