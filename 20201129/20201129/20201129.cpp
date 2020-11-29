#include <stdlib.h>
#include <stdio.h>

void PrintArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//1.直接插入排序
// 稳定性：稳定
// 时间复杂度
// 最好			最坏			平均
// O(n)			O(n^2)			O(n^2)
// 有序			逆序			随机的
// 空间复杂度	O(1)
void insertSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		// 有序区间[0,i)
		//无序区间[i,size)
		//抓起的是[i]牌
		//从后往前比较并插入
		int j;
		int k = a[i];
		for (j = i - 1; j >= 0 && k < a[j]; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = k;//看似是a[j]=k,但上个for循环‘；’结束后j经历了一次--
	}
}


//2.希尔排序
//前提：插入排序中，数据越接近有序，排序效率越高
//预排序->插排  分组插入
// 稳定性：不稳定
// 时间复杂度
// 最好			最坏			平均
// O(n)			O(n^2)			O(n^1.2-1.3)
// 有序			逆序			随机的
// 空间复杂度	O(1)
void insertSortwithgap(int a[], int size, int gap)
{
	for (int i = 0; i < size; i++)
	{
		int j;
		int k = a[i];
		for (j = i - gap; j >= 0 && a[i] < a[j]; j -= gap)
		{
			a[i] = a[j];
		}
		a[j + gap] = k;
	}
}

void shellSort(int a[], int size)
{
	int gap = size;
	while (1)
	{
		gap = gap / 3 + 1;
		insertSortwithgap(a, size, gap);
		if (gap == 1)
			break;
	}

}int main()
{
	int a[] = { 9,5,2,7,3,6,4,8,3,2,1 };
	int size = sizeof(a) / sizeof(int);
	PrintArray(a, size);

	insertSort(a, size);
	PrintArray(a, size);

	shellSort(a, size);
	PrintArray(a, size);

	system("pause");
	return 0;
}