#include "20191229.h"

int main()
{
	int a[] = { 5, 3, 2, 9, 1, 4, 8, 7, 3, 9, 6 };
	int size = sizeof(a) / sizeof(int);
	printArray(a, size);

	selectSort(a, size);
	printArray(a, size);

	selectSort1(a, size);
	printArray(a, size);

	heapSort(a, size);
	printArray(a, size);

	system("pause");
	return 0;
}