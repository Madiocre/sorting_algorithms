#include <sort.h>

/**
 * partition - 
 *
 */

int partition(int* array, int low, int high) {
	int pivot = array[high];
	int i = (low - 1),j,temp1,temp2;

	for (j = low; j <= high - 1; j++) {
		if (array[j] < pivot) {
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
 * quick_sort :
 * @array:
 * @size:
 */
void quick_sort(int* array, size_t size) {
	int pivotIndex;

	if (size == 0 || size == 1)
		return;

	pivotIndex = partition(array, 0, size - 1);
	quick_sort(array, pivotIndex);
	quick_sort(array + pivotIndex + 1, size - pivotIndex - 1);
}
