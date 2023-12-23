#include "sort.h"
/**
 * partition - marks the pivot
 *
 * @array: the array
 * @low: low pivot of array
 * @high: high pivot of array
 *
 * Return: pivot
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = (low - 1), j, temp1, temp2;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp1 = array[i];
			array[i] = array[j];
			array[j] = temp1;
		}
	}
	temp2 = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp2;
	return (i + 1);
}
/**
 * quick_sort_sec - sorts using quick
 *
 * @array: array to be sorted
 * @pivot: current size of array
 * @org_size: original array size
 * @org_array: original array
 */
void quick_sort_sec(int *array, size_t pivot, int *org_array, size_t org_size)
{
	int pivotIndex;

	if (pivot == 0 || pivot == 1)
	return;
	pivotIndex = partition(array, 0, pivot - 1);
	print_array(org_array, org_size);
	quick_sort_sec(array, pivotIndex, org_array, org_size);
	quick_sort_sec(array + pivotIndex + 1, pivot - pivotIndex - 1,
org_array, org_size);
}

/**
 * quick_sort - sorts using quick
 *
 * @array: array to be sorted
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	int pivotIndex;

	if (size == 0 || size == 1)
		return;
	pivotIndex = partition(array, 0, size - 1);
	print_array(array, size);
	quick_sort_sec(array, pivotIndex, array, size);
	quick_sort_sec(array + pivotIndex + 1, size - pivotIndex - 1, array, size);
}
