#include "sort.h"

/**
 * swap_ints - Swaps integers
 * @num1: First number.
 * @num2: Second number.
 *
 * Return: void.
 */
void swap_ints(int *num1, int *num2)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending order
 * @array: Array to be sorted
 * @size: Size of @array
 *
 * Return: void.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size <= 1)
		return;

	gap = 1;
	while (gap < size)
		gap = gap * 3 + 1;
	gap /= 3;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(&array[j], &array[j - gap]);
				j -= gap;
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
