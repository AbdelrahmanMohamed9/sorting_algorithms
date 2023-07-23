#include "sort.h"

/**
 * print_data - Display the information.
 *
 * @msg: that is the Message.
 * @a: that is the Array.
 * @from: that is From.
 * @to: that is To.
 */
void print_data(char *msg, int *a, int from, int to)
{
	char *ssp;
	int n;

	printf("[%s]: ", msg);
	ssp = "";
	for (n = from; n <= to; n++)
	{
		printf("%s%d", ssp, a[n]);
		ssp = ", ";
	}
	printf("\n");
}

/**
 * merge - Auxiliary function for the merge_sort function.
 *
 * @a: that is the Array.
 *
 * @start: that is Start Index.
 * @middle: that is the Middle.
 *
 * @end: that is the End Index.
 * @b: that is the Buffer.
 */
void merge(int *a, int start, int middle, int end, int *b)
{
	int lw, lmd, n;

	lw = n = start;
	lmd = middle + 1;

	printf("Merging...\n");
	print_data("left", a, start, middle);
	print_data("right", a, middle + 1, end);
	while (lw <= middle && lmd <= end)
	{
		if (a[lw] < a[lmd])
			b[n++] = a[lw++];
		else
			b[n++] = a[lmd++];
	}

	while (lw <= middle)
		b[n++] = a[lw++];

	while (lmd <= end)
		b[n++] = a[lmd++];

	for (n = start; n <= end; n++)
		a[n] = b[n];

	print_data("Done", a, start, end);
}

/**
 * msort - Auxiliary function to assist the merge_sort function.
 *
 * @array: that is the Array.
 * @start: that is Start Index.
 * @end: that is the End Index.
 * @b: that is the Buffer.
 */
void msort(int *array, int start, int end, int *b)
{
	int md;

	if (start < end)
	{
		md = (start + end - 1) / 2;
		msort(array, start, md, b);
		msort(array, md + 1, end, b);
		merge(array, start, md, end, b);
	}
}

/**
 * merge_sort - Arrange an array of integers in ascending
 *	order by utilizing the Merge sort algorithm.
 *
 *
 * @array: that is the Array.
 *
 * @size: that is the Size.
 */
void merge_sort(int *array, size_t size)
{
	int *p;

	p = malloc(sizeof(int) * size);
	if (!p)
		return;
	msort(array, 0, size - 1, p);
	free(p);
}
