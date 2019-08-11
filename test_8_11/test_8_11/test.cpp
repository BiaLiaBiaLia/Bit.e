#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

#if 0
int count1(Byte v)
{
	int sum = 0;
	while (v)
	{
		if (v % 2 == 1)
		{
			sum++;
		}			
		v/=2;
	}
	return sum;
}

int count2(Byte v)
{
	int sum = 0;
	while (v)
	{
		sum += v & 1;
		v >>= 1;
	}
	return sum;
}
int count3(Byte v)
{
	int sum = 0;
	while (v)
	{
		v &= (v - 1);
		sum++;
	}
	return sum;
}
int main()
{
	Byte k = 0;
	scanf("%d", &k);

	printf("sum=%d\n", count1(k));
	printf("sum=%d\n", count2(k));
	printf("sum=%d\n", count3(k));

	system("pause");
	return 0;
}
#endif

#if 0
int Change(int *pX)
{
	int y = 8;
	y = y - *pX;
	pX = &y;
	return 0;
}

int main()
{
	int xx = 3;
	int *pY = &xx;
	Change(pY);
	printf("%d\n", *pY);

	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	char arr[2][4];
	strcpy((char*)arr, "you");
	strcpy(arr[1], "me");
	arr[0][3] = '&';

	printf("%s\n", arr);
	system("pause");
	return 0;
}
#endif