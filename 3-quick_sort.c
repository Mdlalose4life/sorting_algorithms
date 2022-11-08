#include "sort.h"
#include <stdio.h>
/*Prototypes, defining funtions to use in the program*/
void swap_var1(int *xp, int *yp);
void swap_var2(int *a, int *b);
void rec_fun(int *arr, int left, int right, size_t size);
int div_arr(int *arr, int left, int right, size_t size);

/**
 * swap_var1 - swaps elements in an array.
 * @xp: First element to be swapped.
 * @yp: Second element to be swapped.
 * Return: Always 0.
 */
void swap_var1(int *xp, int *yp)
{
int tmp;
tmp = *xp;
*xp = *yp;
*yp = tmp;
}

/**
 * swap_var2 - swaps elements in an array.
 * @a: First element to be swapped.
 * @b: Second element to be swapped.
 * Return: Always 0.
 */
void swap_var2(int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}

/**
 * div_arr - devides the elements of array into
 * equal halves
 * @arr: An array to be splited.
 * @left: index of the leftmost element
 * @right: index of the rightmost element
 * @size: The size of an arrar to be divided.
 * Return: Retuns an index where the
 * division took place.
 */
int div_arr(int *arr, int left, int right, size_t size)
{
int i, j, pivot;
	pivot = arr[right];
	i = left;
	for (j = left; j < right; j++)
	{
		if (arr[j] < pivot)
		{
			if (i != j)
			{
				swap_var1(&arr[i], &arr[j]);
				print_array(arr, size);
			}
			i++;
		}
	}

	if (arr[i] != arr[right])
	{
		swap_var2(&arr[i], &arr[right]);
		print_array(arr, size);
	}
	return (i);
}

/**
 * rec_fun - iterates throught an array.
 * @arr: The array to be iterated
 * @left: index of the leftmost element.
 * @right: index of the rightmost element
 * @size: the size of an array.
 * Return: Always 0.
 */
void rec_fun(int *arr, int left, int right, size_t size)
{
int pivot;
if (left < right)
{
	pivot = div_arr(arr, left, right, size);
	rec_fun(arr, left, pivot - 1, size);
	rec_fun(arr, pivot + 1, right, size);
}
}

/**
 * quick_sort - Sorts the the the elements
 * of an array.
 * @array: The array to be sorted.
 * @size: The size of an array.
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size <= 1)
	return;
rec_fun(array, 0, size - 1, size);
}
