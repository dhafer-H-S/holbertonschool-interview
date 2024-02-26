#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: double pointer to the first node of the list
 * @number: the number to insert
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current = *head;
    listint_t *prev = NULL;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL || (*head)->n >= number)
    {
        new->next = *head;
        *head = new;
    }
    else
    {
        while (current != NULL && current->n < number)
        {
            prev = current;
            current = current->next;
        }
        new->next = current;
        prev->next = new;
    }

    return (new);
}