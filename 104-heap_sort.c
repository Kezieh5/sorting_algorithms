#include "sort.h"
/**
 * check_tree - swiftdown check
 * @array: pointer to array
 * @size: size of the pointer
 * @size_init: original size of the array
 * @idx: index as a root of the tree
 *
**/
void check_tree(int *array, size_t size_init, size_t size, size_t idx)
{

	int n, brch1, brch2;
	size_t br1, br2;

	br1 = idx * 2 + 1;
	br2 = br1 + 1;
	brch1 = array[br1];
	brch2 = array[br2];
	if (((br1 < size) && (br2 < size) &&
		(brch1 >= brch2 && brch1 > array[idx]))
		|| ((br1 == size - 1) && brch1 > array[idx]))
	{
		n = array[idx];
		array[idx] = brch1;
		array[br1] = n;
		print_array(array, size_init);
	}
	else if ((br1 < size) && (br2 < size) &&
		(brch2 > brch1 && brch2 > array[idx]))
	{
		n = array[idx];
		array[idx] = brch2;
		array[br2] = n;
		print_array(array, size_init);
	}
	if (br1 < size - 1)
		check_tree(array, size_init, size, br1);
	if (br2 < size - 1)
		check_tree(array, size_init, size, br2);
}
/**
 * heap_sort - sorts an array of integers
 * @array: pointer to array
 * @size: size of the pointer
 *
**/
void heap_sort(int *array, size_t size)
{
	size_t idx, size_init = size;
	int n;

	if (!array)
		return;
	for (idx = 0; idx < size / 2 ; idx++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - idx);
	}
	for (idx = 0; idx < size_init - 1; idx++)
	{
		n = array[0];
		array[0] = array[size - 1 - idx];
		array[size - 1 - idx] = n;
		print_array(array, size_init);
		check_tree(array, size_init, size - idx - 1, 0);
	}

}
