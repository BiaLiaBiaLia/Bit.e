#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//1.ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
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
//	printf("����������������к��У�\n");
//	scanf("%d %d", &m, &n);
//	multiply(m,n);
//
//	system("pause");
//	return 0;
//}
/*2.ʹ�ú���ʵ���������Ľ���*/
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
//	printf("����������Ҫ������������(�ÿո����)��\n");
//	scanf("%d %d", &x, &y);
//	printf("����ǰx=%d,y=%d\n", x, y);
//	my_swap(&x, &y);
//	printf("������x=%d,y=%d\n", x, y);
//
//	system("pause");
//	return 0;
//}
//3.ʵ��һ�������ж�year�ǲ�������
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
//	printf("����������Ҫ�жϵ���ݣ�");
//	scanf("%d", &year);
//	int n=my_leapYear(year);
//	if (1 == n)
//		printf("%d������\n", year);
//	else
//		printf("%d��������\n", year);
//
//	system("pause");
//	return 0;
//}
//4.
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
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
//	reverse(arr, sz);//�����������
//	printfArray(arr, sz);
//	init(arr, sz, y);//��ʼ������
//	printfArray(arr, sz);
//	empty(arr, sz);//�������
//	printfArray(arr, sz);
//
//	system("pause");
//	return 0;
//}
//5.ʵ��һ���������ж�һ�����ǲ���������
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
			printf("%d������\n", k);
		else
			printf("%d��������\n", k);
	}

	system("pause");
	return 0;
}