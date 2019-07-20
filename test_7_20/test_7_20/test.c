#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	int a = 5;
//	int b = 10;
//	int temp = 0;
//	printf("a=%d b=%d\n", a, b);
//	temp = a;
//	a = b;
//	b = temp;
//	printf("a=%d b=%d\n", a, b);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 5;
//	int b = 10;
//	printf("a=%d b=%d\n", a, b);
//	a = a + b;
//	b = a - b;
//	a = a - b;
//	printf("a=%d b=%d", a, b);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 5;
//	int b = 10;
//	printf("a=%d b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("a=%d b=%d\n", a, b);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int max = 0;
//	int a[10] = { 0 };	
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	max = a[1];
//	for (i = 1; i < 10; i++)
//	{
//		if (a[i] > max)
//			max = a[i];
//	}
//	printf("max=%d", max);
//
//	system("pause");
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int tmp = 0;
//	scanf("%d,%d,%d", &a, &b, &c);
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//	printf("a=%d,b=%d,c=%d", a, b, c);
//
//	system("pause");
//	return 0;
//}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	if (a >= b)
	{
		int c = a % b;
		while (0 != c)
		{
			a = b;
			b = c;
			c = a % b;
		}
		printf("最大公约数是%d\n", b);
	}
	else if (a < b)
	{
		int d = b % a;
		while (0 != d)
		{
			b = a;
			a = d;
			d = b / a;
		}
		printf("最大公约数是%d\n", b);
	}

	system("pause");
	return 0;
}
