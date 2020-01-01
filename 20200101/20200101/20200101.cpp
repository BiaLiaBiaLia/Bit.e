#include "20200101.h"

int main()
{
	int a[] = { 3,1,5,3,3,3,3,0,5,6,4,9,7,2 };
	int size = sizeof(a) / sizeof(int);
	PrintArray(a, size);

	countSort(a, size);
	PrintArray(a, size);

	system("pause");
	return 0;
}