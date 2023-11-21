#include "sort.h"
#include <stdio.h>

/**
 * swap_items - Swaps two items in an array.
 * @array: array to modify
 * @l: The index of the first item
 * @r: The index of the second item
 * Return: void
 */
void swap_items(int *array, size_t l, size_t r)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}

/**
 * quick_sort_range_lomuto - Sorts a sub array
 * @array: The array contaning the sub-array.
 * @low: the first position of the sub-array.
 * @high: the end position of the sub-array
 * @size: the length of the array
 */
void quick_sort_range_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t k, i;
	int pivot;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	k = low;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (k != i)
			{
				swap_items(array, k, i);
				print_array(array, size);
			}
			k++;
		}
	}
	if (k != high)
	{
		swap_items(array, k, high);
		print_array(array, size);
	}
	if (k - low > 1)
		quick_sort_range_lomuto(array, low, k - 1, size);
	if (high - k > 1)
		quick_sort_range_lomuto(array, k + 1, high, size);
}

/**
 * quick_sort - Sorts an array using the quick sort algorithm
 * and Lomuto's partition scheme.
 * @array: The array to sort
 * @size: the length of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quick_sort_range_lomuto(array, 0, size - 1, size);
	}
}
