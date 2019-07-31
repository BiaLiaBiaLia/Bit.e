#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//1.调整数组使奇数全部都位于偶数前面。
//
//题目：
//
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
//void num_change(int ar[], int left,int right)
//{
//	while (left <= right)
//	{
//		if ((ar[left] % 2 == 1) && (ar[right] % 2 == 1))
//			left++;
//		else if ((ar[left] % 2 == 1) && (ar[right] % 2 == 0))
//		{
//			left++;
//			right--;
//		}
//		else if ((ar[left] % 2 == 0) && (ar[right] % 2 == 1))
//		{
//			int tmp = 0;
//			tmp = ar[left];
//			ar[left] = ar[right];
//			ar[right] = tmp;
//			left++;
//			right--;
//		}
//		else
//			right--;
//	}
//}
//void print(int ar[], int n)
//{
//	int i = 0;
//	for (i = 0; i <= n; ++i)
//		printf("%d ", ar[i]);
//	printf("\n");
//}
//int main()
//{
//	int ar[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int left = 0;
//	int right = sizeof(ar) / sizeof(ar[0]) - 1;
//	num_change(ar,left,right);
//	print(ar, right);
//
//	system("pause");
//	return 0;
//}

//杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
#include <stdbool.h>
#define ROW 3
#define COL 3
static ar[ROW][COL] = { {1,3,4},{2,4,5},{4,5,6} };//1 3 4
bool search_yang(int ar[ROW][COL], int x)         //2 4 5
{                                                 //4 5 6
	int i = 0;
	int j = COL - 1;
	while (true)
	{
		if (ar[i][j] == x)
		{
			return true;
		}
		else if ((ar[i][j] > x) && (j > 0))
		{
			ar[i][j] = ar[i][--j];
		}
		else if ((ar[i][j] < x) && (i < (ROW - 1)))
		{
			ar[i][j] = ar[++i][j];
		}
		else
			return false;
	}
}
int main()
{
	int x = 0;
	printf("请输入所要查找的数：");
	scanf("%d", &x);
	if (search_yang(ar, x))
		printf("找到了\n");
	else
		printf("没找到\n");

	system("pause");
	return 0;
}