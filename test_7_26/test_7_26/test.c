#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
//int find_fib(int x)//�ݹ�
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
//	printf("��%d��쳲���������%d\n", x, m);
//
//	system("pause");
//	return 0;
//}

//int main()//�ǵݹ�
//{
//	int input = 0;
//	scanf("%d", &input);
//	if (input <= 2)
//	{
//		printf("��%d��쳲����������ǣ�1\n", input);
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
//		printf("��%d��쳲����������ǣ�%d\n", input,c);
//	}
//	system("pause");
//	return 0;
//}
//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
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

//3. дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ�
//���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
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
//4. ��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
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
//	printf("ԭ�ַ���Ϊ:%s\n", n);
//	reverse_string(n);
//	printf("\n");
//	system("pause");
//	return 0;
//}
//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//int main()
//{
//	char* a= "string";//�ǵݹ�
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
//int main()//�ݹ�
//{
//	char* a = "string";
//	int m=my_strlen(a);
//	printf("%d\n", m);
//
//	system("pause");
//	return 0;
//}
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
//int main()//�ǵݹ�
//{
//	int n = 0;
//	int i = 0;
//	int ret = 1;
//	printf("��������Ҫ�׳˵���:");
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
//int main()//�ݹ���
//{
//	int x = 0;
//	printf("����������Ҫ�׳˵���:");
//	scanf("%d", &x);
//
//	int sum=my_factorial(x);
//	printf("%d\n", sum);
//
//	system("pause");
//	return 0;
//}
//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
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
	printf("����������Ҫ��ӡ��������");
	scanf("%d", &x);

	my_play(x);

	system("pause");
	return 0;
}