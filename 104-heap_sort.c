#include "sort.h"

/**
 * swap_bubble - function for sorting with swap method.
 *@a: element to be swapped.
 *@b: element to be swapped.
 * Return: nothing.
 */

void swap_bubble(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * max_heap - Turn a binary tree into heap.
 * @array: An array representing a binary tree.
 * @size: The size of the array/tree.
 * @bse: The indx of the baseof the tree.
 * @rt: The root  binary tree.
 */
void max_heap(int *array, size_t size, size_t bse, size_t rt)
{
	size_t left = 2 * rt + 1;
	size_t right = 2 * rt + 2;
	size_t big = rt;

	if (left < bse && array[left] > array[big])
		big = left;
	if (right < bse && array[right] > array[big])
		big = right;

	if (big != rt)
	{
		swap_bubble(array + rt, array + big);
		print_array(array, size);
		max_heap(array, size, bse, big);
	}
}
/**
 * heap_sort - Sort an array of integers in ascending
 *             order.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int k;

	if (array == NULL || size < 2)
		return;

	for (k = (size / 2) - 1; k >= 0; k--)
		max_heap(array, size, size, k);

	for (k = size - 1; k > 0; k--)
	{
		swap_bubble(array, array + k);
		print_array(array, size);
		max_heap(array, size, k, 0);
	}
}
