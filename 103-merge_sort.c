#include "sort.h"

/**
 * merge_sub - merge sorting algorithm function.
 *@subarray: array split into sub array.
 *@buffer: buffer of array.
 *@end: low partition.
 *@mid: mid partition.
 *@strt: high partition.
 * Return: Always 0
 */
void merge_sub(int *subarray, int *buffer, size_t end, size_t mid, size_t strt)
{
	size_t low = end;
	size_t midd = mid;
	size_t k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + end, mid - end);

	printf("[right]: ");
	print_array(subarray + mid, strt - mid);

	while (low < mid && midd < strt)
	{
		if (subarray[low] < subarray[midd])
		{
			buffer[k++] = subarray[low++];
		}
		else
		{
			buffer[k++] = subarray[midd++];
		}
	}

	while (low < mid)
	{
		buffer[k++] = subarray[low++];
	}

	while (midd < strt)
	{
		buffer[k++] = subarray[midd++];
	}

	for (low = end, k = 0; low < strt; low++)
	{
		subarray[low] = buffer[k++];
	}

	printf("[Done]: ");
	print_array(subarray + end, strt - end);
}

/**
 * merge_sort_call - calling the merge sort function.
 *@subarray: subarray to be sorted.
 *@buffer: buffer of array.
 *@end: low partition.
 *@strt: high partition.
 * Return: Always 0
 */
void merge_sort_call(int *subarray, int *buffer, size_t end, size_t strt)
{
	size_t mid;

	if (strt - end > 1)
	{
		mid = end + (strt - end) / 2;
		merge_sort_call(subarray, buffer, end, mid);
		merge_sort_call(subarray, buffer, mid, strt);
		merge_sub(subarray, buffer, end, mid, strt);
	}
}
/**
 * merge_sort - merge sort algorithm implementation
 *@array: array to be sorted.
 *@size: size of array to be sorted.
 * Return: void.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_call(array, buffer, 0, size);

	free(buffer);
}
