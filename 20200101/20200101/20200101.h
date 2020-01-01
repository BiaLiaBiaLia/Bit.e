#pragma once
#include <iostream>
using namespace std;

void PrintArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//非比较排序
//1.计数排序：(鸽巢原理)
//数据密集集中在某个范围(应用场景)
//确认数据的范围
//申请保存数据个数的空间
//统计区间中每个数据出现的次数
//按照次数对数据进行回收
//时间复杂度：O(N)
//空间复杂度：O(M)  M：区间中元素的个数
//稳定性：稳定的
void countSort(int a[], int size)
{
	//1.计算数据范围
	int minValue = a[0];
	int maxValue = a[0];
	//O(N)
	for (int i = 0; i < size; i++)
	{
		if (a[i] < minValue)
			minValue = a[i];

		if (a[i] > maxValue)
			maxValue = a[i];
	}

	//2.获取计数的空间
	int range = maxValue - minValue + 1;
	int* temp = (int*)malloc(sizeof(int)*range);//空间初始为0
	if (NULL == temp)
		return;

	//3.统计每个元素出现的次数
	memset(temp, 0, sizeof(int)*range);

	//O(N)
	for (int i = 0; i < size; i++)
		temp[a[i] - minValue]++;

	//回收
	int index = 0;
	for (int i = 0; i < range; i++)
	{
		while (temp[i])
		{
			a[index++] = i + minValue;
			temp[i]--;
		}
	}

	free(temp);
}

//2.基数排序----多关键码排序
//1.统计每个桶中元素的个数
//2.计算每个桶的起始地址

//for(最大的数据位数：M)
//3.以当前位为桶的编号，将数据放到对应的桶中 O(N)
//4.按照桶的编号从小到大，对每个桶中的元素进行回收 O(N)
//桶中元素回收规则：FIFO

//addr[i]=addr[i-1]+Count[i-1];
