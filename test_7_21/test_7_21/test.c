#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[] = { 11,12,13,14,15,16,17,18,19,20 };
//	int tmp=0;
//	int i = 0;
//	for (i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++)
//	{
//		tmp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = tmp;
//	}
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	printf("\n");
//	for (i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
//	{
//		printf("%d ", arr2[i]);
//	}	
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	double sum = 0;
//	int n = 0;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		sum += pow(-1, (i + 1))*(1.0 / i);
//	}
//	printf("%f", sum);
//	
//	system("pause");
//	return 0;
//}

int main()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++)
	{
		if (9 == i % 10)
			count++;
		if (9 == i / 10)
			count++;
	}
	printf("%d\n", count);

	system("pause");
	return 0;
}