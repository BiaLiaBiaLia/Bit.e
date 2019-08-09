#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

#if 0
int Fibonacci(int k)
{
	if (k <= 2)
		return 1;
	int a = 1;
	int b = 1;
	int c = a + b;
	for (int i = 1; i <= k - 3; ++i)
	{
		a = b;
		b = c;
		c = a + b;
	}
	return c;
}

int main()
{
	int key = 0;
	scanf("%d", &key);

	printf("%d\n", Fibonacci(key));

	system("pause");
	return 0;
}
#endif

#if 0
#define F(X,Y) ((X)+(Y))
int main()
{
	char a[20];
	char *p1 = (char *)a;
	char *p2 = (char *)(a + 5);
	int n = p2 - p1;
	printf("%d\n", n);//5
	
    int b = 3, c = 4;
	printf("%d\n", F(b++, c++));//7

	int x = 5 > 1 + 2 && 2 || 2 * 4 < 4 - !0;
	printf("%d\n", x);

	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	int i = 1, sum = 0;
	while (i < 10)
	{
		sum += 1;
		i++;
	}
	printf("i=%d,sum=%d\n", i, sum);

	system("pause");
	return 0;
}
#endif

#if 0
#pragma pack(4)
int main()
{
	struct tagTest1
	{
		short a;//2
		char d;//1+1
		long b;//4
		long c;//4
	};
	struct tagTest2
	{
		long b;//4
		short c;//2
		char d;//1+1
		long a;//4
	};
	struct tagTest3
	{
		short c;//2+2
		long b;//4
		char d;//1+3
		long a;//4
	};
	struct tagTest1 stT1;//12
	struct tagTest2 stT2;//12
	struct tagTest3 stT3;//16

	printf("%d %d %d\n", sizeof(stT1), sizeof(stT2), sizeof(stT3));

	system("pause");
	return 0;
}
#pragma pack()
#endif

#if 0
int main()
{
	enum ENUM_A
	{
		X1,
		Y1,
		Z1 = 5,
		A1,
		B1
	};
	enum ENUM_A enumA = Y1;
	enum ENUM_A enumB = B1;

	printf("%d %d\n", enumA, enumB);

	system("pause");
	return 0;
}
#endif

int fun(int x, int y)
{
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}
int main()
{
	int j = 4;
	int m = 1;
	int k;
	k = fun(j, m);
	printf("%d\n", k);
	k = fun(j, m);
	printf("%d\n", k);

	system("pause");
	return 0;
}