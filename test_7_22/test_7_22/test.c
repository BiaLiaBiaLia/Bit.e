#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	printf("«Î ‰»Î–– ˝£∫");
//	scanf("%d", &k);
//	for (i = 1; i <= k/2+1; i++)
//	{
//		for (j = 1; j <= 2 * i - 1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (i = 1; i <=(k/2); i++)
//	{
//		for (j = 2 * (k / 2 + 1)-1-2*i; j > 0; j--)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 0; i < 1000; i++)
//	{
//		int count = 1;
//		int sum = 0;
//		int temp = 0;
//		temp = i;
//		while (temp / 10)
//		{
//			count++;
//			temp /= 10;
//		}
//		temp = i;
//		while (temp)
//		{
//			sum += pow((temp % 10), count);
//			temp /= 10;
//		}
//		if (i == sum)
//			printf("%d\n", i);
//	}
//	system("pause");
//	return 0;
//}

int main()
{
	int a = 0;
	int i = 0;
	int sum = 0;
	int Sn = 0;
	scanf("%d", &a);
	for (i = 0; i < 5; i++)
	{
		sum = 10 * sum + a;
		Sn += sum;
	}
	printf("%d", Sn);

	system("pause");
	return 0;
}