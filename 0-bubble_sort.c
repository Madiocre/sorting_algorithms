// #include "sort.h"

// /**
//  * bubble_sort - Sorts an array of integers
//  *
//  * @array: The array to be sorted
//  * @size: Number of elements in @array
//  */

// void bubble_sort(int *array, size_t size){
//     size_t step, i;
//     int temp = 0;
    
//     for (step = 0; step < size - 1; ++step) {
//         for (i = 0; i < size - step - 1; ++i) {
//             if (array[i] > array[i + 1]) {
//                 temp = array[i];
//                 array[i] = array[i + 1];
//                 array[i + 1] = temp;
//             }
//         }
//         print_array(array, size);
//     }
// }
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
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}