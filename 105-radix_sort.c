#include "sort.h"

/**
 * get_max - To get the max of the array
 *@array: array to be sorted
 *@size: size to be sorted
 *
 * Return: int
 */
int get_max(int *array, int size)
{
	int max = array[0];
	int i;


	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}
/**
 * lsd_sort - sorting algo
 *@array: array to be sorted
 *@size: size of array to be sorted
 *@exp: exp
 *@copy: copy
 * Return: void
 */
void lsd_sort(int *array, size_t size, int exp, int *copy)
{
	size_t b;
	int bucket[10] = {0};

	for (b = 0; b < size; b++)
	{
		bucket[(array[b] / exp) % 10]++;
	}

	for (b = 1; b < 10; b++)
	{
		bucket[b] = bucket[b] + bucket[b - 1];
	}

	for (b = size - 1; (int)b >= 0; b--)
	{
		copy[bucket[(array[b] / exp) % 10] - 1] = array[b];
		bucket[(array[b] / exp) % 10]--;
	}

	for (b = 0; b < size; b++)
	{
		array[b] = copy[b];
	}
}
/**
 * radix_sort - radix sorting algo function
 *@array: array to be sorted
 *@size: size of array to be sorted
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, exp, *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;

	max = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		lsd_sort(array, size, exp, copy);
		print_array(array, size);
	}
	free(copy);
}
