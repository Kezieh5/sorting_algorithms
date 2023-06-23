#include "sort.h"

/**
 * counting_sort - Algorithm that sorts the array in order ascended
 *@array: type array of integers.
 *@size: type size of array.
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sort, sum, max_val;
	size_t k;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;

	max_val = array[0];
	for (k = 1; k < size; k++)
		max_val = (array[k] > max_val) ? array[k] : max_val;
	count = malloc(sizeof(int) * (max_val + 1));
	if (count == NULL)
		return;

	for (k = 0; k < (size_t)(max_val + 1); k++)
		count[k] = 0;

	for (k = 0; k < size; k++)
		count[array[k]]++;

	for (k = 0, sum = 0; k < (size_t)(max_val + 1); k++)
	{
		count[k] += sum;
		sum = count[k];
	}
	print_array(count, max_val + 1);

	for (k = 0; k < size; k++)
	{
		sort[count[array[k]] - 1] = array[k];
		count[array[k]]--;
	}
	for (k = 0; k < size; k++)
		array[k] = sort[k];

	free(sort);
	free(count);
}
