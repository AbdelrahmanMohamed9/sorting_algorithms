#include "sort.h"

/**
 * heapify - Function Build the max heap tree
 *
 * @arr: IS input array
 * @size: Is size of the array
 */

void heapify(int *arr, size_t size)
{
	size_t head;

	for (head = ((size - 1) - 1) / 2; 1; head--)
	{
		sift_down(arr, head, size - 1, size);
		if (head == 0)
			break;
	}
}

/**
 * heap_sort - Function Sorts an array of integers in
 *           an ascending order using the Heap sort algorithm
 * @array: The input array
 * @size: The size of the array
 */

void heap_sort(int *array, size_t size)
{
	int temp;
	size_t x;

	if (size < 2 || !array)
		return;

	heapify(array, size);
	x = size - 1;
	while (x > 0)
	{
		temp = array[x];
		array[x] = array[0];
		array[0] = temp;
		print_array(array, size);
		x--;
		sift_down(array, 0, x, size);
	}
}

/**
 * sift_down - Function Swap numbers
 * @arr: input array
  * @end: the last index of the heap
 * @root: the root of the heap
 * @size: size of the array
 */

void sift_down(int *arr, size_t root, size_t end, size_t size)
{
	int temp;
	size_t swap, right_n, left_n;

	while ((left_n = (2 * root) + 1) <= end)
	{
		swap = root;
		right_n = left_n + 1;
		if (arr[swap] < arr[left_n])
			swap = left_n;
		if (right_n <= end && arr[swap] < arr[right_n])
			swap = right_n;
		if (swap == root)
			return;

		temp = arr[root];
		arr[root] = arr[swap];
		arr[swap] = temp;
		print_array(arr, size);
		root = swap;
	}
}
