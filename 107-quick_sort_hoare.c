#include "sort.h"

/**
 * qsort_h - Function Recursives helper function
 *	for quick_sort_hoare
 * @arr: the array to sort
 * @start: the lowest index of partition to sort
 * @end: the highest index of partition to sort
 * @size: the size of the array
 */

void qsort_h(int *arr, ssize_t start, ssize_t end, size_t size)
{
	ssize_t i, k;
	int temp, x;

	if (end > start)
	{
		k = end;
		i = start;
		x = arr[k];
		while (i <= k)
		{
			while (arr[k] > x)
				k--;
			while (arr[i] < x)
				i++;
			if (i <= k)
			{
				if (i != k)
				{
					temp = arr[i];
					arr[i] = arr[k];
					arr[k] = temp;
					print_array(arr, size);
				}
				k--;
				i++;
			}
		}
		qsort_h(arr, start, k, size);
		qsort_h(arr, k + 1, end, size);
	}
}

/**
 * quick_sort_hoare - Function Sorts array of integers in ascending
 *		order using the Quick sort hoare algorithm
 * @array: An  array to sort
 * @size:  size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2 || !array)
		return;
	qsort_h(array, 0, size - 1, size);
}
