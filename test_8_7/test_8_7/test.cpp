#define _CRT_SECURE_NO_WARNINGS
#include "test.h"

void Print_Str(char str[],int len)
{
	assert(str);
	for(int i=0;i<len;++i)
	{
		if (str[i] != '/0')
			printf("%c", str[i]);
	}
	printf("\n");
}
void replace(char *str)
{
	//算出新字符串的长度
	int length = 0;
	int count = 0;
	char *tmp = str;
	while (*tmp != '\0')
	{
		length++;
		if (*tmp++ == ' ')
		{
			count++;
		}
	}
	int newsize = length + count * 2;
	str[newsize] = '\0';
	//从后往前进行替换
	int j = newsize - 1;
	for (int i = length - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			str[j--] = str[i];
		}
		else
		{
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
	}
}


int main()
{
	char str[] = "abc defgx yz";
	int len = strlen(str);
	Print_Str(str,len);

	replace(str);
	int newlen = strlen(str);
	Print_Str(str,newlen);

	system("pause");
	return 0;
}