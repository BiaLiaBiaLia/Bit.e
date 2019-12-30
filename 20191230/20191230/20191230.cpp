#include "20191230.h"

int main()
{
	int a[] = { 9,2,3,5,4,9,9,7,9,3,6,8 };
	int size = sizeof(a) / sizeof(int);
	int left = 0;
	int right = size - 1;
	printfArray(a, size);

	bubbleSort(a, size);
	printfArray(a, size);

	quickSort(a, left, right);
	printfArray(a, size);

	quickSortNoR(a, left, right);
	printfArray(a, size);

	system("pause");
	return 0;
}