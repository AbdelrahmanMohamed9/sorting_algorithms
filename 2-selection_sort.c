#include "sort.h"

/**
 * selection_sort - Function sorts  array of integers in
 *		ascending order using the Selection Sort algorithm.
 * @array: The Given array to be sorted.
 * @size: TThe Number of elements in given array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t k, mini, swaap;

	if (size < 2 || !array)
		return;

	while (i < size)
	{
		mini = i;
		swaap = 0;
		for (k = i + 1; k < size; k++)
			if (array[k] < array[mini])
				mini = k, swaap = array[i];

		if (swaap)
		{
			array[i] = array[mini];
			array[mini] = swaap;
			print_array(array, size);
		}
		i++;
	}
}
