#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

//void Guess()
//{
//	srand((unsigned int)time(NULL));
//	int i = rand() % 100;
//	int input;
//	while (1)
//	{
//		printf("请输入你猜的数字:\n");
//		scanf("%d", &input);
//		if (input == i)
//		{
//			printf("猜对了\n");
//			break;
//		}
//		else if (input > i)
//		{
//			printf("猜大了\n");
//		}
//		else
//		{
//			printf("猜小了");
//		}
//	}
//}
//int main()
//{
//	int input = 0;
//	while (1)
//	{
//		printf("***********************\n");
//		printf("*     1.玩游戏        *\n");
//		printf("*     0.退出游戏      *\n");
//		printf("***********************\n");
//
//		scanf("%d", &input);
//		if (input == 1)
//		
//			Guess( );
//		
//		else if(input==0)
//		{
//			break;
//		}
//		else
//		{
//			printf("输入错误，请重新输入！\n");
//		}
//	}
//
//	system("pause");
//	return 0;
//}
//2.写代码可以在整型有序数组中查找想要的数字，
//找到了返回下标，找不到返回 - 1.（折半查找）
//int BinarySearch(int arr[], int sz, int key)
//{
//	int left = 0;
//	int right = sz - 1;
//	int mid = 0;
//	while (left <= right)
//	{
//		 mid = left + (right-left) / 2;
//		if (key == arr[mid])
//		{
//			return mid;
//		}
//		else if (key < arr[mid])
//		{
//			right = mid-1;
//		}
//		else
//		{
//			left = mid + 1;
//		}
//			
//	}
//	if (left > right)
//		return -1;
//
//}
//int main()
//{
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	int sz = sizeof arr / sizeof arr[0];
//	int k = 0;
//	printf("请输入你所需要查找的数：");
//	scanf("%d", &k);
//
//	int i = BinarySearch(arr, sz, k);
//	if (i != -1)
//	{
//		printf("找到了，下标是%d\n", i);
//
//	}
//	else
//	{
//		printf("%d", i);
//	}
//
//	system("pause");
//	return 0;
//}

//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序。

//int main()
//{
//	char password[20];
//	char key[20] = "abcdef";
//	printf("请输入密码：\n");
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%s", &password);
//		if (0 == strcmp(key, password))
//		{
//			printf("密码正确!\n");
//			break;
//		}
//		else
//			printf("密码错误!\n");
//	}
//
//	system("pause");
//	return 0;
//}
//
//4.编写一个程序，可以一直接收键盘字符，
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。
int main()
{
	char src[20];
	int i = 0;
	scanf("%s", &src);

	//for(i=0;i<strlen(src);i++)
	//{
	//	if ('A' <= src[i] && src[i] <= 'Z')
	//	{
	//		printf("%c", src[i] + 32);
	//	}
	//	if ('a' <= src[i] && src[i] <= 'z')
	//	{
	//		printf("%c", src[i] - 32);
	//	}
	//}
	while (src[i] != '\0')
	{
		if ('A' <= src[i] && src[i] <= 'Z')
		{
			printf("%c", src[i] + 32);
		}
		if ('a' <= src[i] && src[i] <= 'z')
		{
			printf("%c", src[i] - 32);
		}
		i++;
	}
	printf("\n");

	system("pause");
	return 0;
}