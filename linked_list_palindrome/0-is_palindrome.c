#include <stddef.h>
#include "lists.h" // Include the header file for list definitions and prototypes

/* Function prototype for reversing the list */
listint_t *reverse_list(listint_t *head) {
    listint_t *prev = NULL;
    listint_t *current = head;
    listint_t *next = NULL;

    while (current != NULL) {
        next = current->next; // Save next
        current->next = prev; // Reverse current node's pointer
        prev = current; // Move pointers one position ahead
        current = next;
    }
    head = prev;
    return head;
}

int is_palindrome(listint_t **head) {
    listint_t *slow, *fast, *temp;
    /* An empty list or a single element list is a palindrome. */
    if (*head == NULL || (*head)->next == NULL) {
        return 1;
    }

    slow = *head;
    fast = *head;
    /* Find the middle of the list. */
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse the second half of the list. */
    slow->next = reverse_list(slow->next);
    slow = slow->next; /* Move slow to the start of the reversed half. */

    /* Compare the first half and the reversed second half. */
    temp = *head;
    while (slow != NULL) {
        if (temp->n != slow->n) {
            return 0; /* Not a palindrome. */
        }
        temp = temp->next;
        slow = slow->next;
    }

    return 1; /* The list is a palindrome. */
}