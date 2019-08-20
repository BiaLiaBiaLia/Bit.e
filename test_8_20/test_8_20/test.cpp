#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

#if 0
char *myString()
{
	char buffer[6] = { 0 };
	char *s = (char *)"Hello World!";
	for (int i = 0; i < sizeof(buffer) - 1; i++)
	{
		buffer[i] = *(s + i);
	}
	return buffer;
}
int main()
{
	printf("%s\n", myString());

	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = (char)(-1 - i);
	}
	printf("%d\n", strlen(a));
	system("pause");
	return 0;
}
#endif

#if 0
char FindFirstSingleChar(char str[])
{
	if (str == NULL || str[0] == '\0')
		return 0;

	int count[256] = { 0 };
	int i = 0;
	while (str[i++] != '\0')
	{
		count[str[i]]++;
	}
	i = 0;
	while (str[i++] != '\0')
	{
		if (count[str[i]] == 1)
			return str[i];
	}
	return 0;
}

int main()
{
	char arr[] = "abaccdeff";
	printf("'%c'\n", FindFirstSingleChar(arr));

	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	unsigned char a = 0xA5;
	unsigned char b = ~a >> 4 + 1;
	printf("%d\n", b);

	system("pause");
	return 0;
}
#endif

int main()
{
	const int i = 0;
	int *j = (int *)&i;
	*j = 1;
	printf("%d,%d", i, *j);

	system("pause");
	return 0;
}