#include "sort.h"
#include <stdio.h>
/**
 * swap_num - swaps two intergers in a list.
 * @xp: fist value to be sorted.
 * @yp: second value to be sorted.
 * Return: Always 0.
 */
void swap_num(int *xp, int *yp)
{
int temp;
temp = *xp;
*xp = *yp;
*yp = temp;
}

/**
 * selection_sort - Sorts the intergers in a list.
 * @array: an array to be sorted.
 * @size: size of an array to be sorted.
 * Return: void
 *
 */
void selection_sort(int *array, size_t size)
{
int *min_idx;
size_t i, j;
if (array == NULL || size < 2)
	return;
for (i = 0; i < size - 1; i++)
{
	min_idx = array + 1;
	for (j = i + 1; j < size; j++)
		min_idx = (array[j] < *min_idx) ? (array + j) : min_idx;
	if ((array + i) != min_idx)
	{
		swap_num(array + i, min_idx);
		print_array(array, size);
	}
}
}
