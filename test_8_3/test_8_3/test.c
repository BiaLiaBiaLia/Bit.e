#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

int main()
{
	int array[] = { 3,5,2,7,6,9,8 };
	Print(array, sizeof(array) / sizeof(int));
	bubbleSort(array, sizeof(array) / sizeof(int));
	Print(array, sizeof(array) / sizeof(int));
	int m = binarySearch(array, sizeof(array) / sizeof(int), 9);
	printf("%d\n", m);

	system("pause");
	return 0;
}