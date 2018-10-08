#include "search_algos.h"

/**
 * print_search - This is a function that will print our Searching in array.
 * @array: This is a pointer to the first element of the array to search in.
 * @left: This is the beginning of the array.
 * @right: This is the end of the array.
 *
 * Return: Void.
 */


void print_search(int *array, size_t left, size_t right)
{
	size_t index = left;


	printf("Searching in array: ");
	while (index < right)
	{
		printf("%d, ", array[index]);
		index++;
	}
	printf("%d\n", array[index]);
}



/**
 * binary_search - This is a function that searches for a value in a
 * sorted array of integers using the Binary search algorithm
 * @array: is a pointer to the first element of the array to search in.
 * @size: is the number of elements in an array.
 * @value: is the value to search for.
 *
 * Return: -1, or index where value is located.
 */


int binary_search(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;
	size_t midpoint = 0;

	if (array == NULL)
	{
		return (-1);
	}
	while (left <= right)
	{
		midpoint = (left + right) / 2;
		print_search(array, left, right);
		if (array[midpoint] < value)
		{
			left = midpoint + 1;
		}
		else if (array[midpoint] > value)
		{
			right = midpoint;
		}
		else
		{
			return (midpoint);
		}
	}
	return (-1);
}
