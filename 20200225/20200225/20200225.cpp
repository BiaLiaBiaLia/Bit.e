#define	_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//��������жϴ�С��
int check_sys()
{
	union
	{
		int a;
		char b;
	}un;
	un.a = 1;//0X 01 00 00 00
	return un.b; // 0X 01
}

int main()
{
	int ret = check_sys();
	{
		printf("%d\n", ret);
	}

	system("pause");
	return 0;
}
