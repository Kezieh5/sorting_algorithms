#include "sort.h"

/**
 * swap_bubble - Swap two integers.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_bubble(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - Sort a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: starting index.
 * @seq: size of the sequence to sort.
 * @flow: direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t j, jump = seq / 2;

	if (seq > 1)
	{
		for (j = start; j < start + jump; j++)
		{
			if ((flow == UP && array[j] > array[j + jump]) ||
			    (flow == DOWN && array[j] < array[j + jump]))
				swap_bubble(array + j, array + j + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}
/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: size of the array.
 * @start: starting index
 * @seq: size of a block
 * @flow: direction to sort.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t brk = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, brk, UP);
		bitonic_seq(array, size, start + brk, brk, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}
/**
 * bitonic_sort - Sort an array of integers.
 * @array: An array.
 * @size: The size.
 *
 * Description: Prints the array after each swap.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
