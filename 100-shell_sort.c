#include "sort.h"
/**
 * swap_shell - Swaps the two elements recieved.
 * @a: first element to be swapped.
 * @b: Second element to be swapped.
 * Return: Always 0.
 */
void swap_shell(int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}

/**
 * shell_sort - Uses the shell sort to sort an array.
 * @array: The array to be sorted.
 * @size: The size of an array to be sorted
 * Return: Always 0.
 */
void shell_sort(int *array, size_t size)
{
size_t gap, i, j;
if (array == NULL || size < 2)
	return;
for (gap = 1; gap < (size / 3);)
	gap = gap * 3 + 1;
for (; gap >= 1; gap /= 3)
{
	for (i = gap; i < size; i++)
	{
		for (j = i; gap && array[j - gap] > array[j]; j -= gap)
		{
			swap_shell(array + j, array + (j - gap));
		}
	}
	print_array(array, size);
}
}
