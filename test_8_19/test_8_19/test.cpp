#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

#if 0
int a = 1;
void test()
{
	int a = 2;
	a += 1;
}
int main()
{
	test();
	printf("%d\n", a);

	system("pause");
	return 0;
}
#endif
#if 0
int findNum(int a[], int k)
{
	int min = a[0];
	for (int i = 1; i < k; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}
int main()
{
	int arr[] = { 4,6,3,9,4,2,5,1 };
	int k = 0;
	char s[] = "\\123456\123456\t";
	scanf("%d", &k);
	printf("%d\n", findNum(arr, k));
	printf("%d\n", strlen(s));//12

	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int s = 0, n;
	for (n = 0; n < 4; n++)
	{
		switch (n)
		{
		default:s += 4;
		case 1:s += 1;
		case 2:s += 2;
		case 3:s += 3;
		}
	}
	printf("%d\n", s);//24

	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	unsigned long ulA = 0x11000000;
	printf("%x\n", *(unsigned char *)&ulA);

	system("pause");
	return 0;
}
#endif

#if 0
void findNum1(int a[], int size)
{
	int max = a[0];
	for (int i = 1; i < size; i++)
	{
		if (a[i] > max)
			max = a[i];
	}

	int *b = (int *)malloc(sizeof(int)*(max+1));
	for (int j = 0; j <= max; j++)
	{
		b[j] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		b[a[i]]++;
	}
	for (int j = 0; j <= max; j++)
	{
		if (b[j] > (size / 2))
			printf("%d ", j);
	}
	free(b);
	printf("\n");
}
int main()
{
	int arr[] = { 1,2,3,2,2,2,5,4,2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	findNum1(arr, size);

	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int a[5] = { 1,2,3,4,5 };
	int* p1 = (int*)(&a + 1);
	int* p2 = (int*)((int)a + 1);
	int* p3 = (int*)(a + 1);
	printf("%d, %x, %d", p1[-1], p2[0], p3[1]);

	system("pause");
	return 0;
}
#endif

int Max_Arr(int a[], int size)
{
	int sum = 0;
	int n = 1;
	for (int i = 0; i < size; i++)
	{
		sum += a[i];
	}
	int max = sum;
	for (int j = 0; j < size - 1; j++)
	{
		int min = a[j] < a[size - n] ? a[j] : a[size - n];
		if (min != a[j])
		{
			n++;
			j--;
		}
		sum -= min;
		if (max < sum)
			max = sum;
	}
	return max;
}

int main()
{
	int arr[] = { 1,-2,3,10,-4,7,2,-5 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printf("%d\n", Max_Arr(arr, size));

	system("pause");
	return 0;
}
