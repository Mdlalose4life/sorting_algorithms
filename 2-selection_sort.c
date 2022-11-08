#include "sort.h"
#include <stdio.h>
/**
 * selection_sort - Sorts the intergers in a list.
 * @array: an array to be sorted.
 * @size: size of an array to be sorted.
 * Return: void
 *
 */
void selection_sort(int *array, size_t size)
{
size_t i, j;
int min_num, temp, index;

for (i = 0; i < size; i++)
{
	min_num = array[i];
	for (j = i + 1; j < size; j++)
	{
		if (min_num > array[j])
		{
			min_num = array[j];
			index = j;
		}
	}

	if (min_num != array[i])
	{
		temp = array[i];
		array[i] = min_num;
		array[index] = temp;
		print_array(array, size);
	}
}
}
