#include "sort.h"

/**
 * bubble_sort - Rearrange an integer array in ascending
 *	order by applying the Bubble sort algorithm.
 *
 *
 * @array: the array that is being processed
 * @size: length of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t t, v;
	int tp, swp;

	for (v = size, swp = 1; v > 0 && swp; v--)
	{
		swp = 0;
		for (t = 0; t < v - 1; t++)
		{
			if (array[t] > array[t + 1])
			{
				tp = array[t + 1];
				array[t + 1] = array[t];
				array[t] = tp;
				print_array(array, size);
				swp = 1;
			}
		}
	}
}
