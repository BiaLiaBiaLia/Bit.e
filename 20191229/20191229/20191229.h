#pragma once
#include <iostream>
using namespace std;

void printArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
//直接选择排序
// 通过遍历无序区间，找到无序区间的最大的数的下标
// 交换 无序区间最大的数 和 无序区间的最后一个数
// 稳定性：不稳定
// 时间复杂度	O(n^2)	数据不敏感
// 空间复杂度	O(1)
void selectSort(int a[], int size)
{
	//有序区间[size-i，size)
	//无序区间[0,size-i)
	for (int i = 0; i < size; i++)
	{
		int max = 0;
		for (int j = 1; j < size - i; j++)
		{
			if (a[j] > a[max])
			{
				max = j;
			}
			int tmp = a[max];
			a[max] = a[size - i - 1];
			a[size - i - 1] = tmp;
		}
	}
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void selectSort1(int a[], int size)
//双向
//1)选最大的放在最后
//2)选最小的放在最前
{
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		int min = left;
		int max = left;
		int i;
		for (i = left + 1; i <= right; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}
		swap(&a[left], &a[min]);
		if (max == left)
			max = min;
		swap(&a[right], &a[max]);
		left++;
		right--;
	}
}

//2.堆排序
void heapify1(int a[], int size, int index)//建大堆
{
	int left = 2 * index + 1;//左孩子下标
	int right = 2 * index + 2;//右孩子下标

	//先判断index是不是叶子节点
	//先判断index有没有孩子
	//index有没有左孩子
	//index左孩子下标是否越界
	if (left >= size)
	{
		return;
	}

	//找左右孩子中较大的孩子的下标
	//先假设较大的孩子是左孩子
	//比较两孩子的大小
	int max = left;
	if (right < size&&a[left] < a[right])
	{
		max = right;
	}

	//比较较大孩子和index的值
	if (a[index] >= a[max])
	{
		//根的值比最大孩子的值还大，已经满足堆的性质
		//可以结束调整
		return;
	}
	//交换最大孩子和根的值
	int t = a[max];
	a[max] = a[index];
	a[index] = t;

	//继续调整max的位置
	heapify1(a, size, max);
}

void heapify2(int a[], int size, int index)//建小堆
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left >= size)
	{
		return;
	}

	int min = left;
	if (right<size&&a[left]>a[right])
	{
		min = right;
	}

	if (a[index] <= a[min])
		return;

	int t = a[min];
	a[min] = a[index];
	a[index] = t;

	heapify2(a, size, min);
}

//时间复杂度O(n*log(n))
void CreatHeap(int a[], int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)//最后一个非叶子节点
	{
		heapify1(a, size, i);
	}
}

// 稳定性：不稳定
// 时间复杂度	O(n * log(n))	数据不敏感
// 空间复杂度	O(1)
void heapSort(int a[], int size)
{
	//1.建堆
	CreatHeap(a, size);

	//2.需要 size 次
	for (int i = 0; i < size; i++)
	{
		//有序区间[0,size-i)
		//无序区间[size-i.size)
		int tmp = a[0];
		a[0] = a[size - i - 1];//把最大的往后放，逐渐向前
		a[size - i - 1] = tmp;
		heapify1(a, size - i - 1, 0);
	}

}