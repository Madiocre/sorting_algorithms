#include "sort.h"

/**
 * sortedInsert - Sorts using insert method.
 * @sorted: The sorted.
 * @next: The next node.
 * @prev: The prev node.
 */
void sortedInsert(listint_t **head, listint_t **prev, listint_t *current)
{
    (*prev)->next = current->next;
    if (current->next != NULL)
        current->next->prev = (*prev);
    current->prev = (*prev)->prev;
    current->next = (*prev);
    if((*prev)->prev != NULL){
        (*prev)->prev->next = current;
    }
    else
        (*head) = current;
    (*prev)->prev = current;
    (*prev) = current->prev;

}

/**
 * insertion_sort_list - Sorts a list of integers
 *
 * @@list: The list to be sorted
 */

void insertion_sort_list(listint_t **list){
    listint_t *current, *next, *prev;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
    current = (*list)->next;
    while (current != NULL) {
        next = current->next;
        prev = current->prev;
        while(prev != NULL && current->n < prev->n)
            sortedInsert(list, &prev, current);
        print_list((const listint_t *)*list);
        current = next;
    }
}