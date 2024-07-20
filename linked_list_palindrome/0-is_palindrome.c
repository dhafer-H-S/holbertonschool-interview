#include <stdio.h>
#include <stdlib.h>
#include "lists.h" // Assuming lists.h defines the listint_t structure.

/**
 * Reverse the second half of the linked list.
 */
listint_t *reverse_list(listint_t *head) {
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

/**
 * Checks if a singly linked list is a palindrome.
 */
int is_palindrome(listint_t **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return 1; // An empty list or a single element list is a palindrome.
    }

    listint_t *slow = *head;
    listint_t *fast = *head;
    // Find the middle of the list.
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the list.
    slow->next = reverse_list(slow->next);
    slow = slow->next; // Move slow to the start of the reversed half.

    // Compare the first half and the reversed second half.
    listint_t *temp = *head;
    while (slow != NULL) {
        if (temp->n != slow->n) { // Corrected field name from val to n
            return 0; // Not a palindrome.
        }
        temp = temp->next;
        slow = slow->next;
    }

    // Optional: Reverse the second half back to its original form if needed.

    return 1; // The list is a palindrome.
}