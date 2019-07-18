#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 101; i < 200; i+=2)
//	{
//		for (j = 2; j <= i - 1; j++)		
//		{
//			if (i % j == 0)	
//				break;
//		}
//		{
//			if (i == j)			
//				printf(" %d", i);
//		}
//		
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i < 10; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//
//			printf("%d*%d=%-3d",i,j,i*j);
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		{
			printf("  %d", year);
		}
	}
	system("pause");
	return 0;
}