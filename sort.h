#ifndef _SORT_H_
#define _SORT_H_


#include <stdio.h>
#include <stdlib.h>



/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element in the list
 * @next: Pointer to the next element in the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;




void quick_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void _qsort(int *a, int low, int high, int size);
void shell_sort(int *array, size_t size);
void _ssort(int *a, int size, int n);
void cocktail_sort_list(listint_t **list);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void sift_down(int *arr, size_t root, size_t end, size_t size);
void heapify(int *arr, size_t size);



#endif /* _SORT_H_ */
