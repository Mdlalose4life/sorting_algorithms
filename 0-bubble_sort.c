#include "sort.h"
/**
 * swap - swaps two elements in an array
 * @xp: first value to be swapped
 * @yp: second value to be swapped
 * Return: Always 0.
 */
void swap_var(int *xp, int *yp)
{
int temp;
temp = *xp;
*xp = *yp;
*yp = temp;
}

/**
 * bubble_sort - This function performs bubble sort in an array
 * @array: A pointer to an array that need to be sorted.
 * @size: The size of an array to be sorted.
 * Return: Always 0.
 */
void bubble_sort(int *array, size_t size)
{
size_t len, j, pos;
if (array == NULL || size < 2)
	return;
len = size;
while (len > 0)
{
	pos = 0;
	for (j = 0; j < len - 1; j++)
	{
		if (array[j] > array[j + 1])
		{
			swap_var(&array[j], &array[j + 1]);
			pos = j + 1;
			print_array(array, size);
		}
	}
	len = pos;
}
}
