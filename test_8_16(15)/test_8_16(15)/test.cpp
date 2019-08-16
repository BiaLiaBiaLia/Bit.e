#define _CRT_SECURE_NO_WARNINGS
#include "test.h"
#define CIR(r) r*r
#if 0
int fun1(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x & (x - 1);
	}
	return count;
}

int main()
{
	printf("fun1(2017)=%d\n", fun1(2019));

	system("pause");
	return 0;
}
#endif

/*int main()
{
	int a = 1;
	int b = 2;
	int t;
	t = CIR(a + b);
	printf("%d\n", t);

	system("pause");
	return 0;
}*/

#if 0
unsigned long g_ulGlobal = 0;
void GlobalInit(unsigned long ulArg)
{
	ulArg = 0x01;
	return;
}

void test()
{
	GlobalInit(g_ulGlobal);
	printf("%lu\n", g_ulGlobal);
	return;
}
int main()
{
	test();
	system("pause");
	return 0;
}
#endif
#if 0
int fun2(int a, int b)
{
	if (a > b)
		return (a + b);
	else
		return (a - b);
}

int main()
{
	int x = 3, y = 8, z = 6, r;
	int a = 4;
	r = fun2(fun2(x, y), 2 * z);
	printf("%d\n",r);//17
	printf("%d\n", ++(a++));


	system("pause");
	return 0;
}
#endif
#if 0
int f(int a)
{
	int b = 0;
	static int c = 3;
	a = c++, b++;
	return (a);
}
int main()
{
	int a = 2, i, k;
	for (i = 0; i < 2; i++)
	{
		k = f(a++);
	}
	printf("%d\n", k);

	system("pause");
	return 0;
}
#endif

int x = 3;
void inc()
{
	static int x = 1;

	x *= (x + 1);
	printf("%d", x);
	return;
}
int main()
{
	int i = 0;
	for (i = 1; i < x; i++)
	{
		inc();
	}

	system("pause");
	return 0;
}