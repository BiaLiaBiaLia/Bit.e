#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define ROW 4
#define COL 4
#if 0
int main()
{
	int a[4][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20} };
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	//a 首行地址               a+1 加一行元素长度后的地址
	//&a 整个数组的地址        &a+1 加一个数组长度后的地址
	//a[0] 首行首元素的地址    a[0]+1 加一个元素长度后的地址
	//*a 首行首元素的地址      *a+1 加一个元素长度后的地址
	system("pause");
	return 0;
}
#endif

#if 0
bool search_Nmb(int a[ROW][COL], int key)
{
	int i = 0;
	int j = COL - 1;
	while (true)
	{
		if (a[i][j] == key)
			return true;
		else if (a[i][j] > key && j > 0)
			a[i][j] = a[i][--j];
		else if (a[i][j] < key && i < (ROW - 1))
			a[i][j] = a[++i][j];
		else
			return false;
	}
}
int main()
{
	int key = 0;
	int arr[ROW][COL] = {
		1,2,8,9,
		2,4,9,12,
		4,7,10,13,
		6,8,11,15
	};

	scanf("%d", &key);
	if (search_Nmb(arr, key))
		printf("找到了\n");
	else
		printf("没找到\n");

	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	printf("%x\n", (0x13 & 0x17));

	system("pause");
	return 0;
}
#endif

#if 0
//typedef struct {
//	int a;
//	char b;
//	short c;
//	short d;
//}AA_t;
int main()
{
	//printf("%d\n", sizeof(AA_t));
	struct S1 {
		char c1;
		int i;
		char c2;
	};
	printf("%d\n", sizeof(struct S1));//12

	struct S2 {
		char c1;
		char c2;
		int i;
	};
	printf("%d\n", sizeof(struct S2));//8

	struct S3 {
		double d;
		char c;
		int i;
	};
	printf("%d\n", sizeof(struct S3));//16

	//Linux 默认#pragma pack(4)
	//window 默认#pragma pack(8)
	struct S4 {
		char c1;         //1+7  按照struct S3中最大的偏移量进行计算(8)
		struct S3 s3;    //16
		double d;        //8
	};
	printf("%d\n", sizeof(struct S4));//32(1+7+16+8)

	system("pause");
	return 0;
}

#endif

int main()
{
	const char *p = "Hello!";
	printf("%c\n", *p);

	int a = 10;
	int b = a += a *= a -= a / 3;//从右往左计算 98
	printf("%d\n", b);

	system("pause");
	return 0;
}