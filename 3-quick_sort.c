#include "sort.h"

void swap_rec(int *num1, int *num2);
int lomuto_partition(int *array, int start, int end, size_t size);
void recursive_quick_sort(int *array, int start, int end, size_t size);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swaps two integers
 * @num1: First number
 * @num2: Second number
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
 * lomuto_partition - Sorts a partition of an array.
 * @array: Array to be  sorted.
 * @low: Starting index.
 * @high: Ending index.
 * @size: Size of the array.
 *
 * Return: void.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, partitionIndex, i;

	pivot = array[high];
	partitionIndex = low;
	for (i = low; i < high; i++)
	{
		if (array[i] < pivot)
		{
			if (partitionIndex < i)
			{
				swap_ints(&array[partitionIndex], &array[i]);
				print_array(array, size);
			}
			partitionIndex++;
		}
	}
	if (array[partitionIndex] > pivot)
	{
		swap_ints(&array[partitionIndex], &array[high]);
		print_array(array, size);
	}
	return (partitionIndex);
}

/**
 * recursive_quick_sort - Sort an array of integers
 * @array: Array to sort
 * @left: Beginning of the array
 * @right: End of the array
 * @size: Size of the array.
 *
 * Return: Pivot index.
 */
void recursive_quick_sort(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = lomuto_partition(array, left, right, size);
		recursive_quick_sort(array, left, pivot - 1, size);
		recursive_quick_sort(array, pivot + 1, right, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to sort
 * @size: Size of the array
 *
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}
