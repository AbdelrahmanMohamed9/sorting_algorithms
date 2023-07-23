#include "sort.h"

/**
 * counting_sort - Rearrange an array of integers in increasing
 *	order by employing the Counting sort technique.
 *
 *
 * @array: that is the Array.
 *
 * @size: that is the Size.
 */
void counting_sort(int *array, size_t size)
{
	int *s, *d, v, c;

	if (!array || size < 2)
		return;

	for (c = v = 0; v < (int)size; v++)
		if (array[v] > c)
			c = array[v];

	d = malloc(sizeof(int) * (c + 1));
	if (!d)
		return;

	for (v = 0; v <= c; v++)
		d[v] = 0;
	for (v = 0; v < (int)size; v++)
		d[array[v]] += 1;
	for (v = 1; v <= c; v++)
		d[v] += d[v - 1];

	print_array(d, (c + 1));
	s = malloc(sizeof(int) * (size + 1));
	if (!s)
	{
		free(d);
		return;
	}

	for (v = 0; v < (int)size; v++)
	{
		s[d[array[v]] - 1] = array[v];
		d[array[v]] -= 1;
	}
	for (v = 0; v < (int)size; v++)
		array[v] = s[v];

	free(d);
	free(s);
}
