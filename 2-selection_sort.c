#include "sort.h"
/**
 * swap_bubble - function to swap/sort.
 *@a: variable to swap.
 *@b: variable to swap.
 * Return: void.
 */
void swap_bubble(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sorting array via selection sort method.
 *@array: array to be sorted.
 *@size: size of array.
 * Return: Always 0
 */
void selection_sort(int *array, size_t size)
{
	size_t i, k;

	for (i = 0; i < size - 1; i++)
	{
		size_t min_idx = i;
		int temp = array[i];

		for (k = i + 1; k < size; k++)
		{
			if (array[k] < array[min_idx])
				min_idx = k;
		}

		if (min_idx != i)
		{

			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
