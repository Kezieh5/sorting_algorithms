#include "sort.h"

/**
 * swap_bubble - function to swap.
 *@a: pointer to be swapped.
 *@b: pointer to be swapped.
 * Return: Always 0
 */
void swap_bubble(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quick_sort_hoare - sorts an array.
 *@array: array to be sorted.
 *@size: size of array.
 * Return: void.
 */
void quick_sort_hoare(int *array, size_t size)
{

	partition_sort_hoare(array, size, 0, size - 1);
}

/**
 * partition_sort_hoare - function of partition.
 *@array: given array to be sorted.
 *@size: size of array to be sorted.
 *@end: partition.
 *@start: partition.
 * Return: void.
 */
void partition_sort_hoare(int *array, size_t size, int end, int start)
{
	int part;

	if (start - end > 0)
	{
		part = partition_hoare(array, size, end, start);
		partition_sort_hoare(array, size, end, part - 1);
		partition_sort_hoare(array, size, part, start);
	}
}

/**
 * partition_hoare - function with pivot for partition.
 *@array: array to be sorted with Hoare algorithm.
 *@size: size of array to be sorted.
 *@low: low partition.
 *@high: high partition.
 * Return: Always 0
 */
int partition_hoare(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int left = low - 1;
	int right = high + 1;

	while (1)
	{
		do {
			left++;
		} while (array[left] < pivot);

		do {
			right--;
		} while (array[right] > pivot);

		if (left >= right)
			return (right);

		swap_bubble(array + left, array + right);
		print_array(array, size);
	}
}
