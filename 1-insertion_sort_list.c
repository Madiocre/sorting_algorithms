#include "sort.h"


listint_t *sortedInsert(listint_t *sorted, listint_t *newNode) {
    listint_t *current;

    if (sorted == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }
    current = sorted;
    while (current->next != NULL && current->next->n < newNode->n)
        current = current->next;
    newNode->next = current->next;
    if (current->next != NULL)
        current->next->prev = newNode;
    current->next = newNode;
    newNode->prev = current;
    return sorted;
}

/**
 * insertion_sort_list - Sorts a list of integers
 *
 * @@list: The list to be sorted
 */

void insertion_sort_list(listint_t **list){
    listint_t *sorted = NULL;
    listint_t *current = *list;

    while (current != NULL) {
        listint_t *next = current->next;
        sorted = sortedInsert(sorted, current);
        current = next;
    }
    *list = sorted;
}