#pragma once
#include <stdlib.h>
#include <stdio.h>

void swap(int a[], int x, int y)
{
	int temp = 0;
	temp = a[x];
	a[x] = a[y];
	a[y] = temp;
}
void bubbleSort(int array[], int size)//O(n)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
				swap(array, j, j + 1);
		}
	}
}

void Print(int array[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d", array[i]);
	printf("\n");
}

int binarySearch(int a[], int size, int value)//O(logn)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == value)
			return mid;
		else if (a[mid] < value)
			left = a[mid];
		else
			right = a[mid];
	}
	return -1;
}