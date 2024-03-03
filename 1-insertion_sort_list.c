#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two const values
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
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order.
 *
 * @list: List to sort
 *
 * Return: void.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *sort;

	if (list == NULL || *list == NULL)
		return;

	ptr = (*list)->next;
	while (ptr)
	{
		sort = ptr;
		while (sort->prev && (sort->n < sort->prev->n))
		{
			swap((int *)&sort->prev->n, (int *)&sort->n);
			sort = sort->prev;
			print_list((const listint_t *)*list);
		}
		ptr = ptr->next;
	}
}
