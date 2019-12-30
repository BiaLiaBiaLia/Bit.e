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

//ð������
//��������[size-i-1,size)
//��������[0,size-i-1)
//ʱ�临�Ӷ�:
//��ã�	O(n)		����
//ƽ����	O(n^2)
//���	O(n^2)		����
//�ռ临�Ӷȣ�	O(1)
//�ȶ��ԣ��ȶ�
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

//��������(�����㷨)
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition1(int a[], int left, int right)
{
	//Hover��
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
		swap(&a[begin], &a[end]);//begin��end�������ʱ����
	}
	swap(&a[begin], &a[right]);//�����м�ͻ�׼ֵ
	return begin;
}

int partition2(int a[], int left, int right)
{
	//�ڿӷ�
	int begin = left;
	int end = right;
	int pivot = a[right];
	while (begin < end)
	{
		while (begin < end && a[begin] <= pivot)
		{
			begin++;
		}
		a[end] = a[begin];//����׼ֵ��λ�ü�Ϊ�ӣ����������������
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
	//ǰ���±귨
	// [left, div) �Ȼ�׼С
	// [div, i) �Ȼ�׼ֵ���ڵ���
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
ʱ�临�Ӷȣ�
���     O(n*log(n))
ƽ��     O(n*log(n))
�     O(n^2)

�ռ临�Ӷȣ��൱����������ĸ߶�
���     O(log(n))
ƽ��     O(log(n))
�     O(n)

�ȶ��ԣ� ���ȶ�
*/
void quickSort(int a[], int left, int right)//�ݹ�ⷨ
{
	if (left >= right)
	{//����Ԫ�ظ���ֻʣ1����0��
		return;
	}
	//1.ȷ����׼ֵ�����ұ�a[right](3��)
	//1)ѡ�������
	//2)�����
	//3)����ȡ�з�
	//������ͳһ�������ұߣ���ԭ������Ϥ����ʽ

	//2.��partition,С���󣬴���ң����ػ�׼ֵ�������±�
	int pivotIndex = partition3(a, left, right);
	//3.���δ�����������С����
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
		int low = s.top(); s.pop();//��ջ����ÿһ���������Ӵ�����βԪ���±�
		if (low >= high)
		{
			continue;
		}
		int pivotIndex = partition1(a, low, high);//��׼ֵ�±�
		s.push(low);//��׼ֵ��ߵ�С����
		s.push(pivotIndex - 1);

		s.push(pivotIndex + 1);//��׼ֵ�ұߵ�С����
		s.push(high);
	}

}