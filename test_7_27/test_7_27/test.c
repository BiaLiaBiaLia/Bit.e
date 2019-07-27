#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//1.
//写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	int x = 0;
//	while (value)
//	{
//		x = value % 2;
//		value >>= 1;
//		if (x == 1)
//			count++;
//		/*if (value % 2)
//			count++;
//		value >>= 1;*/
//	}
//	return count;
//}
//int main()
//{
//	unsigned int n = 0;
//	scanf("%u", &n);
//	int m = count_one_bits(n);
//	printf("二进制中1的个数为：%d\n", m);
//
//	system("pause");
//	return 0;
//}
//
//2.获取一个数二进制序列中所有的偶数位和奇数位，
//分别输出二进制序列。
//int main()
//{
//	int i = 0;
//	int j = 0;
//;	int x = 0;
//	scanf("%d", &x);
//	printf("获取的偶数位为：");
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d", (x >> i) & 1);
//	}
//	printf("\n");
//	printf("获取的奇数位为：");
//	for (j = 30; j >= 0; j -= 2)
//	{
//		printf("%d", (x >> j) & 1);
//	}
//	printf("\n");
//
//	system("pause");
//	return 0;
//}

//3. 输出一个整数的每一位。
//void print(int x)
//{
//	if (x > 9)
//	{
//		print(x / 10);
//	}
//	printf("%d  ", x % 10);
//}
//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//	print(x);
//
//	system("pause");
//	return 0;
//}
//4.编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
int count_dif_bits(int m, int n)
{
	int count = 0;
	int x = m ^ n;
	int z = 0;
	while (x)
	{
		z = x % 2;
		x >>= 1;
		if (z == 1)
			count++;
	}
	return count;
}
int main()
{
	int m = 0;
	int n = 0;
	int x = 0;
	scanf("%d %d", &m, &n);

	printf("整数%d和%d的二进制表达中，有%d个位（bit）不同\n", m, n, count_dif_bits(m, n));

	system("pause");
	return 0;
}