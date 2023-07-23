#include "sort.h"

/**
 * b_compare - Function Sorts  values in a sub-array
 *             with respect to the Bitonic sort algorithm
 * @up: is a irection of sorting
 * @array: is a sub-array to sort
 * @size: is the size of the sub-array
 */

void b_compare(char up, int *array, size_t size)
{
	int temp;
	size_t x = 0;
	size_t n;

	n = size / 2;
	while (x < n)
	{
		if ((array[x] > array[x + n]) == up)
		{
			temp = array[x];
			array[x] = array[x + n];
			array[x + n] = temp;
		}
		x++;
	}
}

/**
 * b_merge - Function Merges recursively two sub-arrays
 * @up: is a direction of sorting
 * @array: is a sub-array to sort
 * @size: is the size of the sub-array
 */

void b_merge(char up, int *array, size_t size)
{
	if (size < 2)
		return;
	b_compare(up, array, size);
	b_merge(up, array, size / 2);
	b_merge(up, array + (size / 2), size / 2);
}

/**
 * b_sort - Function Recursives helper function for the Bitonic
 *		sort algorithm
 * @up: the direction of sorting
 * @array: the sub-array to sort
 * @size: the size of the sub-array
 * @t: the total size of the original array
 */

void b_sort(char up, int *array, size_t size, size_t t)
{
	if (size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
	b_sort(1, array, size / 2, t);
	b_sort(0, array + (size / 2), size / 2, t);
	b_merge(up, array, size);
	printf("Result [%lu/%lu] (%s):\n", size, t, (up == 1) ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_sort - Function Sorts array of integers in ascending
 *       order using Bitonic sort algorithm
 * @array: The array to sort
 * @size: the size of the array
 */

void bitonic_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;
	b_sort(1, array, size, size);
}
