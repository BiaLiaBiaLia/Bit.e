#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//1.��������ʹ����ȫ����λ��ż��ǰ�档
//
//��Ŀ��
//
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
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

//���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//���飺
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
	printf("��������Ҫ���ҵ�����");
	scanf("%d", &x);
	if (search_yang(ar, x))
		printf("�ҵ���\n");
	else
		printf("û�ҵ�\n");

	system("pause");
	return 0;
}