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
 *@low: partition.
 *@high: partition.
 * Return: void.
 */
void partition_sort_hoare(int *array, size_t size, int low, int high)
{
	int part;

	if (high - low > 0)
	{
		part = partition_hoare(array, size, low, high);
		partition_sort_hoare(array, size, low, part - 1);
		partition_sort_hoare(array, size, part, high);
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
	int left = low;
	int right = high;

	while (true)
	{
		while (array[left] < pivot)
			left++;

		while (array[right] > pivot)
			right--;

		if (left >= right)
			return (right);

		swap_bubble(array + left, array + right);
		print_array(array, size);

		left++;
		right--;
	}
}
