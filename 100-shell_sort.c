#include "sort.h"
/**
 * swap_bubble - function to swap/sort.
 *@a: to be swapped.
 *@b: to be swapped.
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
 * shell_sort - sorts array with shell sort algorithm.
 *@array: array to be sorted.
 *@size: size of array.
 * Return: Always 0
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t gap;
	size_t c, d;

	if (array == NULL || size < 2)
		return;


	for (gap = 1; gap <= (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (c = gap; c < size; ++c)
		{
			for (d = c; d >= gap && array[d - gap] > array[d]; d -= gap)
			{
				temp = array[d];
				array[d] = array[d - gap];
				array[d - gap] = temp;
			}
		}
		print_array(array, size);
	}
}
