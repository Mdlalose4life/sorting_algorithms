#include "sort.h"

void swap_heap(int *a, int *b);
void turn_tree(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_heap - Swaps two intergers
 * @a: first interger to be swapped.
 * @b: Second interger to be swapped.
 * Return: Always 0.
 */
void swap_heap(int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}
/**
 * turn_tree - turns a binary treee into binary heap
 * @array: An array in Binaru tree form.
 * @size: size of an array in a binary tree.
 * @base: The base row index of an array.
 * @root: The root node of an array
 * Return: Always 0.
 */
void turn_tree(int *array, size_t size, size_t base, size_t root)
{
size_t left, right, large;
left = 2 * root + 1;
right = 2 * root + 2;
large = root;
if (left < base && array[left] > array[large])
	large = left;
if (right < base && array[right] > array[large])
	large = right;
if (large != root)
{
	swap_heap(array + root, array + large);
	print_array(array, size);
	turn_tree(array, size, base, large);
}

}
/**
 * heap_sort - sorts an array of intergers using a heap sort.
 * @array: array of intergers to be sorted.
 * @size: THe size of an array to be sorted.
 * Return: Always 0.
 *
 */
void heap_sort(int *array, size_t size)
{
int index;
if (array == NULL || size < 2)
	return;
for (index = (size / 2) - 1; index >= 0; index--)
	turn_tree(array, size, size, index);
for (index = size - 1; index > 0; index--)
{
	swap_heap(array, array + index);
	print_array(array, size);
	turn_tree(array, size, index, 0);
}

}
