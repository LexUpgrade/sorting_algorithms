#include "sort.h"

/**
 * swap - Swaps two integers
 * @num1: First number
 * @num2: Second number
 *
 * Return: void.
 */
void swap(int *num1, int *num2)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: Array of integers to sort
 * @size: Size of @array.
 *
 * Return: void.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, idx;
	int smallest;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		smallest = array[i];
		idx = 0;
		for (j = i; j < size - 1; j++)
		{
			if (smallest > array[j + 1])
			{
				smallest = array[j + 1];
				idx = j + 1;
			}
		}
		if (idx)
		{
			swap(&array[i], &array[idx]);
			print_array(array, size);
		}
	}
}
