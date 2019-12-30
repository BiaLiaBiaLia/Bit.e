#pragma once
#include <iostream>
using namespace std;

void printfArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//冒泡排序
//有序区间[size-i-1,size)
//无序区间[0,size-i-1)
//时间复杂度:
//最好：	O(n)		有序
//平均：	O(n^2)
//最坏：	O(n^2)		逆序
//空间复杂度：	O(1)
//稳定性：稳定
void bubbleSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

//快速排序(分治算法)
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition1(int a[], int left, int right)
{
	//Hover法
	int begin = left;
	int end = right;
	int pivot = a[right];
	while (begin < end)
	{
		while (begin < end && a[begin] <= pivot)
		{
			begin++;
		}
		while (begin < end && a[end] >= pivot)
		{
			end--;
		}
		swap(&a[begin], &a[end]);//begin和end都不相符时交换
	}
	swap(&a[begin], &a[right]);//交换中间和基准值
	return begin;
}

int partition2(int a[], int left, int right)
{
	//挖坑法
	int begin = left;
	int end = right;
	int pivot = a[right];
	while (begin < end)
	{
		while (begin < end && a[begin] <= pivot)
		{
			begin++;
		}
		a[end] = a[begin];//将基准值的位置记为坑，不符合条件后填坑
		while (begin < end && a[end] >= pivot)
		{
			end--;
		}
		a[begin] = a[end];
	}
	a[begin] = pivot;
	return begin;
}

int partition3(int a[], int left, int right)
{
	//前后下标法
	// [left, div) 比基准小
	// [div, i) 比基准值大于等于
	int div = left;
	int pivot = a[right];
	for (int i = left; i < right; i++)
	{
		if (a[i] < pivot)
		{
			swap(&a[i], &a[div]);
			div++;
		}
	}
	swap(&a[div], &a[right]);
	return div;
}
/*
时间复杂度：
最好     O(n*log(n))
平均     O(n*log(n))
最坏     O(n^2)

空间复杂度：相当于求二叉树的高度
最好     O(log(n))
平均     O(log(n))
最坏     O(n)

稳定性： 不稳定
*/
void quickSort(int a[], int left, int right)//递归解法
{
	if (left >= right)
	{//区间元素个数只剩1个或0个
		return;
	}
	//1.确定基准值，最右边a[right](3种)
	//1)选择最边上
	//2)随机数
	//3)三数取中法
	//最后可以统一调到最右边，还原成最熟悉的形式

	//2.做partition,小的左，大的右，返回基准值的最终下标
	int pivotIndex = partition3(a, left, right);
	//3.分治处理左右两个小区间
	quickSort(a, left, pivotIndex - 1);
	quickSort(a, pivotIndex + 1, right);
}
#include <stack>

void quickSortNoR(int a[], int left, int right)
{
	std::stack<int> s;
	s.push(left);
	s.push(right);

	while (!s.empty())
	{
		int high = s.top(); s.pop();
		int low = s.top(); s.pop();//用栈保存每一个待排序子串的首尾元素下标
		if (low >= high)
		{
			continue;
		}
		int pivotIndex = partition1(a, low, high);//基准值下标
		s.push(low);//基准值左边的小区间
		s.push(pivotIndex - 1);

		s.push(pivotIndex + 1);//基准值右边的小区间
		s.push(high);
	}

}