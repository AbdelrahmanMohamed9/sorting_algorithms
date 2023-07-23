#include "sort.h"

/**
 * q_sort - Function Helper function for  quick_sort function
 * @arr: The input arrray
 * @start: The index of first element
 * @end: The index of last element
 * @size: The size of array
 */

void q_sort(int *arr, int start, int end, int size)
{
	int temp, a;
	int i = start;
	int k;

	if (end > start)
	{
		a = arr[end];
		k = start - 1;
		while (i < end)
		{
			if (arr[i] < a)
			{
				k++;
				if (i != k)
				{
					temp = arr[i];
					arr[i] = arr[k];
					arr[k] = temp;
					print_array(arr, size);
				}
			}
			i++;
		}
		if (arr[end] < arr[k + 1])
		{
			temp = arr[k + 1];
			arr[k + 1] = arr[end];
			arr[end] = temp;
			print_array(arr, size);
		}
		q_sort(arr, start, k, size);
		q_sort(arr, k + 2, end, size);
	}
}

/**
 * quick_sort - Function Sorts array of integers in ascending order
 *     using  quick sort algorithm and lomuto partition scheme
 * @array: The input arrray
 * @size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;

	q_sort(array, 0, size - 1, size);
}
