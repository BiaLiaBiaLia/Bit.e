#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

#if 0
int main()
{
	int k, j, s;
	for (k = 2; k < 6; k++, k++)
	{
		s = 1;
		for (j = k; j < 6; j++)
			s += j;
	}
	printf("%d\n", s);

	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int arr[] = { 6,7,8,9,10 };
	int *ptr = arr;
	*(ptr++) += 123;
	printf("%d,%d\n", *ptr, *(++ptr));//8,8

	system("pause");
	return 0;
}
#endif
#if 0
bool isPalindrome(int x)
{
	if (x / 10 == 0)
		return true;
	int tmp = 0;
	int n = x;
	while (n)
	{
		tmp = tmp * 10 + n % 10;
		n = n / 10;
	}
	if (x == tmp)
	{
		return true;
	}
	return false;
}

int main()
{
	int x = 0;
	scanf("%d", &x);
	if (1 == isPalindrome(x))
		printf("%d是回文数\n", x);
	else
		printf("%d不是回文数\n", x);

	system("pause");
	return 0;
}
#endif

int main()
{
	char str[] = "ABCDEFG";
	const char *p1, *p2;
	p1 = "abcd"; p2 = "efgh";
	strcpy(str + 1, p2 + 1);
	strcpy(str + 3, p1 + 3);
	printf("%s\n", str);

	system("pause");
	return 0;
}