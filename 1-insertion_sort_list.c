#include "sort.h"

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