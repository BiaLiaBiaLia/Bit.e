#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//1.递归和非递归分别实现求第n个斐波那契数。
//int find_fib(int x)//递归
//{
//	if (x <= 2)
//	{
//		return 1;
//	}
//	else
//		return find_fib(x - 1) + find_fib(x - 2);
//}
//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//	int m=find_fib(x);
//	printf("第%d个斐波那契数是%d\n", x, m);
//
//	system("pause");
//	return 0;
//}

//int main()//非递归
//{
//	int input = 0;
//	scanf("%d", &input);
//	if (input <= 2)
//	{
//		printf("第%d个斐波那契额数是：1\n", input);
//	}
//	else
//	{
//		int i = 0;
//		int a = 1;
//		int b = 1;
//		int c = a + b;
//		for (i = 0; i < input - 3; i++)
//		{
//			a = b;
//			b = c;
//			c = a + b;
//		}
//		printf("第%d个斐波那契额数是：%d\n", input,c);
//	}
//	system("pause");
//	return 0;
//}
//2.编写一个函数实现n^k，使用递归实现
//int fun(int n, int k)
//{
//	if (k == 1)
//		return n;
//	else
//	{
//		return fun(n, k - 1)*n;
//	}
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//	int output = fun(n, k);
//	printf("%d\n", output);
//
//	system("pause");
//	return 0;
//}

//3. 写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
//int DigitSum(int n)
//{
//	int m = 0;
//	int sum = 0;
//	if (n/10==0)
//		return n;
//	else
//	{
//		m = n % 10;
//		n = n / 10;
//		sum = m + DigitSum(n);
//	}
//	return sum;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int x = DigitSum(n);
//	printf("%d\n", x);
//
//	system("pause");
//	return 0;
//}
//4. 编写一个函数 reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
//void reverse_string(char * string)
//{
//	if (*string != '\0')
//	{
//		string++;
//		reverse_string(string);
//		printf("%c", *(string - 1));
//	}
//}
//int main()
//{
//	char* n = "bitekeji666";
//	printf("原字符串为:%s\n", n);
//	reverse_string(n);
//	printf("\n");
//	system("pause");
//	return 0;
//}
//5.递归和非递归分别实现strlen
//int main()
//{
//	char* a= "string";//非递归
//	int count = 0;
//	while (*a != '\0')
//	{
//		a++;
//		count++;
//	}
//	printf("%d\n", count);
//
//	system("pause");
//	return 0;
//}
//int my_strlen(char* a)
//{
//	if (*a == '\0')
//		return 0;
//	else
//		return my_strlen(a+1) + 1;
//}
//int main()//递归
//{
//	char* a = "string";
//	int m=my_strlen(a);
//	printf("%d\n", m);
//
//	system("pause");
//	return 0;
//}
//6.递归和非递归分别实现求n的阶乘
//int main()//非递归
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	printf("请输入需要阶乘的数:");
//	scanf("%d", &n);
//
//	for (i = 1; i <= n; i++)
//	{
//		ret *= i;
//	}
//	printf("%d\n", ret);
//
//	system("pause");
//	return 0;
//}
//int my_factorial(x)
//{
//	if (x == 1)
//		return 1;
//	else
//	    return x * my_factorial(x - 1);
//}
//int main()//递归求法
//{
//	int x = 0;
//	printf("请输入你需要阶乘的数:");
//	scanf("%d", &x);
//
//	int sum=my_factorial(x);
//	printf("%d\n", sum);
//
//	system("pause");
//	return 0;
//}
//7.递归方式实现打印一个整数的每一位
void my_play(int x)
{
	//if (x>0 && x<10)
	//	printf("%d ", x);
	//else
	//{
	//	my_play(x / 10);
	//	printf("%d ", x % 10);
	//}
	if (x > 9)
	{
		my_play(x / 10);
	}
	printf("%d  ", x % 10);

}
int main()
{
	int x = 0;
	printf("请输入你需要打印的整数：");
	scanf("%d", &x);

	my_play(x);

	system("pause");
	return 0;
}