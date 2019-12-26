#include "20191226.h"

//ʱ�临�Ӷ�O(log(n))
void heapify1(DataType a[], int size, int index)//�����
{
	DataType left = 2 * index + 1;//�����±�
	DataType right = 2 * index + 2;//�Һ����±�

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

void heapify2(DataType a[], int size, int index)//��С��
{
	DataType left = 2 * index + 1;
	DataType right = 2 * index + 2;

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

//ʱ�临�Ӷ�O(n*log(n)]])
void CreatHeap(int a[], int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		heapify1(a, size, i);
	}
}

void heapSort(int a[], int size)
{
	// 1. ����
	CreatHeap(a, size);

	// 2. ��Ҫ size ��
	for (int i = 0; i < size; i++)
	{
		// �������� [0,size - i)
		// �������� [size - i,size)

		int t = a[0];
		a[0] = a[size - i - 1];
		a[size - i - 1] = t;

		heapify1(a, size - i - 1, 0);
	}
}
void adjustUp(int a[], int index)
{
	while (index > 0)
	{
		if (index == 0)
		{
			return;
		}

		int parent = (index - 1) / 2;
		if (a[parent] <= a[index])
		{
			return;
		}

		int t = a[parent];
		a[parent] = a[index];
		a[index] = t;

		index = parent;
	}
}

void InsertHeap(Heap* hp, DataType data)
{
	hp->_array[hp->_size++] = data;
	adjustUp(hp->_array, hp->_size - 1);
}

void EraseHeap(Heap* hp)
{
	assert(hp->_size > 0);
	hp->_array[0] = hp->_array[hp->_size - 1];
	hp->_size--;

	heapify1(hp->_array, hp->_size, 0);
}

int SizeHeap(Heap* hp)
{
	return hp->_size;
}

int EmptyHeap(Heap* hp)
{
	return(0 == hp->_size) ? 1 : 0;
}

DataType TopHeap(Heap* hp)
{
	assert(hp->_size > 0);
	return hp->_array[0];
}

void DestroyHeap(Heap* hp)
{
	hp->_size = 0;
	hp->_capacity = NULL;
	return;
}
int main()
{
	int a[] = { 5, 3, 2, 9, 1, 4, 8, 7, 3, 9, 6 };
	int size = sizeof(a) / sizeof(int);

	system("pause");
	return 0;
}