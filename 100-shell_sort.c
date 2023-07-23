#include "sort.h"

/**
 * s_sort - auxiliary function for the shell_sort algorithm
 *
 * @a: the array being processed
 *
 * @size: length of the array
 * @n: increment
 */
void s_sort(int *a, int size, int n)
{
	int tp, t, k;

	for (t = 0; (t + n) < size; t++)
	{
		for (k = t + n; (k - n) >= 0; k = k - n)
		{
			if (a[k] < a[k - n])
			{
				tp = a[k];
				a[k] = a[k - n];
				a[k - n] = tp;
			}
		}
	}
	print_array(a, size);
}

/**
 * shell_sort - that sort the array of integers in ascending order
 *	using a Shell sort algorithm.
 * @array: that is the array to sort.
 * @size: that is the size of the array to sort.
 */
void shell_sort(int *array, size_t size)
{
	size_t i = 1;

	if (!array || size < 2)
		return;

	while (i < size)
		i = (i * 3) + 1;

	while ((i = (i - 1) / 3) > 0)
		s_sort(array, size, i);
}
