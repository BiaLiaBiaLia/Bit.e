#include "20191231.h"

int main()
{
	int a[] = { 9, 3, 5, 4, 9, 2, 7, 9, 3, 6, 8, 8 };
	int size = sizeof(a) / sizeof(int);
	int left = 0;
	int right = size - 1;
	printArray(a, size);

	mergeSortInternal(a, left, right);
	printArray(a, size);

	system("pause");
	return 0;
}