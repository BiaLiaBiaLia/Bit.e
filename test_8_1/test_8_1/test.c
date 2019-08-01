#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
char *LeftTurn(char *ch, int size, int k)
{
	assert(ch != '\0');
	int n = k % size;
	char c[20];
	char s[10];
	strcpy(c, ch);
	strcat(c, ch);//ABCDABCD
	for (int i = 0; i < size; i++)
		s[i] = c[n++];
	s[size] = '\0';

	for (int i = 0; i < size; i++)
	{
		printf("%c", s[i]);
	}
	printf("\n");
	return s;
}



//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
int judgestr(char *ch, char*vh)
{
	char x[20];
	strcpy(x, ch);
	strcat(x, ch);
	if (strstr(x, vh) != NULL)
		return 1;
	return 0;
}

int main()
{
	char *a = "ABCD";
	int count = strlen(a);
	LeftTurn(a, count, 2);

	char *b = "abcd";
	char *c = "ABCD";
	int x = judgestr(b, c);
	printf("%d\n", x);
	system("pause");
	return 0;
}