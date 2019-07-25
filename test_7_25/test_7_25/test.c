#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//1.实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
//void multiply(int x, int y)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= x; i++)
//	{
//		for (j = 1; j <= y; j++)
//		{
//			printf("%d*%d=%-3d", i, j, i*j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	printf("请输入你想输出的行和列：\n");
//	scanf("%d %d", &m, &n);
//	multiply(m,n);
//
//	system("pause");
//	return 0;
//}
/*2.使用函数实现两个数的交换*/
//void my_swap(int* x, int* y)
//{
//	int tmp = *x;
//	*x = *y;
//	*y = tmp;
//
//	/**x = *x + *y;
//	*y = *x - *y;
//	*x = *x - *y;*/
//
//	//*x = *x^*y;
//	//*y = *x^*y;
//	//*x = *x^*y;
//}
//int main()
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入你想要交换的两个数(用空格隔开)：\n");
//	scanf("%d %d", &x, &y);
//	printf("交换前x=%d,y=%d\n", x, y);
//	my_swap(&x, &y);
//	printf("交换后x=%d,y=%d\n", x, y);
//
//	system("pause");
//	return 0;
//}
//3.实现一个函数判断year是不是润年
//int my_leapYear(int x)
//{
//	if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
//		return 1;
//	else
//		return - 1;
//}
//int main()
//{
//	int year = 0;
//	printf("请输入你所要判断的年份：");
//	scanf("%d", &year);
//	int n=my_leapYear(year);
//	if (1 == n)
//		printf("%d是闰年\n", year);
//	else
//		printf("%d不是闰年\n", year);
//
//	system("pause");
//	return 0;
//}
//4.
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
//#define X 10
//void inputArray(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	printf("\n");
//}
//void printfArray(int arr[],int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf(" %d", arr[i]);
//	}
//	printf("\n");
//}
//void init(int arr[],int sz,int y)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = y;
//	}
//}
//void empty(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = 0;
//	}
//}
//void reverse(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz / 2; i++)
//	{
//		int tmp = arr[i];
//		arr[i] = arr[sz -i- 1];
//		arr[sz -i- 1] = tmp;
//	}
//}
//int main()
//{
//	int arr[X];
//	int y = 5;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	inputArray(arr, sz);
//	printfArray(arr, sz);
//	reverse(arr, sz);//输出逆序数组
//	printfArray(arr, sz);
//	init(arr, sz, y);//初始化数组
//	printfArray(arr, sz);
//	empty(arr, sz);//清空数组
//	printfArray(arr, sz);
//
//	system("pause");
//	return 0;
//}
//5.实现一个函数，判断一个数是不是素数。
int judge_prime(int k)
{
	int i = 0;
	for (i = 2; i <= sqrt(k); i++)
	{
		if (k%i == 0)
			return -1;
	}
	return 1;
}
int main()
{
	int k = 0;
	while (1)
	{
		scanf("%d", &k);
		int n = judge_prime(k);
		if (n == 1)
			printf("%d是素数\n", k);
		else
			printf("%d不是素数\n", k);
	}

	system("pause");
	return 0;
}