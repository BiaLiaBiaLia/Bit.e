#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
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



//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC
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