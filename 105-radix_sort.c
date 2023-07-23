#include "sort.h"

/**
 * radix_sort - Function Sorts an array of integers
 *        in an ascending order using the Radix sort algorithm
 * @array: The input array
 * @size: The size of input array
 */

void radix_sort(int *array, size_t size)
{
	size_t i = 1;
	size_t j = 1;
	int f = 1, n = 10;

	if (size == 1 || !array)
		return;

	while (f)
	{
		f = 0;
		while (i < size)
		{
			if ((array[i - 1] % (n * 10)) / ((n * 10) / 10) > 0)
				f = 1;
			if (((array[i - 1] % n) / (n / 10)) > ((array[i] % n) / (n / 10)))
			{
				array[i - 1] = array[i - 1] + array[i];
				array[i] = array[i - 1] - array[i];
				array[i - 1] = array[i - 1] - array[i];
				if ((i - 1) > 0)
					i -= 2;
			}
			i++;
			j++;
		}
		print_array(array, size);
		n *= 10;
	}
}
