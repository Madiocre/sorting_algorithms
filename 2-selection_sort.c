#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
    int temp = 0;
	bool check = false;

	if (array == NULL || size < 2)
		return;
    for (i = 0; i < size; i++)
    {
        check = true;
        temp = 0;
        for (j = i + 1; j < size; j++){
            if (array[i] > array[j] && check == true)
            {
                temp = array[j];
                swap_ints(array + i, array + j);
                check = false;
            }
            else if (temp > array[j])
            {
                swap_ints(&temp, array + j);
                check = false;
            }
        }
        if (check == false && i != size-1){
            array[i] = temp;
            print_array(array, size);
        }else{
            return;
        }
    }
}