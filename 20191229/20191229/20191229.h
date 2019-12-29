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
//ֱ��ѡ������
// ͨ�������������䣬�ҵ�������������������±�
// ���� �������������� �� ������������һ����
// �ȶ��ԣ����ȶ�
// ʱ�临�Ӷ�	O(n^2)	���ݲ�����
// �ռ临�Ӷ�	O(1)
void selectSort(int a[], int size)
{
	//��������[size-i��size)
	//��������[0,size-i)
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
//˫��
//1)ѡ���ķ������
//2)ѡ��С�ķ�����ǰ
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

//2.������
void heapify1(int a[], int size, int index)//�����
{
	int left = 2 * index + 1;//�����±�
	int right = 2 * index + 2;//�Һ����±�

	//���ж�index�ǲ���Ҷ�ӽڵ�
	//���ж�index��û�к���
	//index��û������
	//index�����±��Ƿ�Խ��
	if (left >= size)
	{
		return;
	}

	//�����Һ����нϴ�ĺ��ӵ��±�
	//�ȼ���ϴ�ĺ���������
	//�Ƚ������ӵĴ�С
	int max = left;
	if (right < size&&a[left] < a[right])
	{
		max = right;
	}

	//�ȽϽϴ��Ӻ�index��ֵ
	if (a[index] >= a[max])
	{
		//����ֵ������ӵ�ֵ�����Ѿ�����ѵ�����
		//���Խ�������
		return;
	}
	//��������Ӻ͸���ֵ
	int t = a[max];
	a[max] = a[index];
	a[index] = t;

	//��������max��λ��
	heapify1(a, size, max);
}

void heapify2(int a[], int size, int index)//��С��
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

//ʱ�临�Ӷ�O(n*log(n))
void CreatHeap(int a[], int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)//���һ����Ҷ�ӽڵ�
	{
		heapify1(a, size, i);
	}
}

// �ȶ��ԣ����ȶ�
// ʱ�临�Ӷ�	O(n * log(n))	���ݲ�����
// �ռ临�Ӷ�	O(1)
void heapSort(int a[], int size)
{
	//1.����
	CreatHeap(a, size);

	//2.��Ҫ size ��
	for (int i = 0; i < size; i++)
	{
		//��������[0,size-i)
		//��������[size-i.size)
		int tmp = a[0];
		a[0] = a[size - i - 1];//����������ţ�����ǰ
		a[size - i - 1] = tmp;
		heapify1(a, size - i - 1, 0);
	}

}