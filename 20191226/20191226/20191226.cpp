#include "20191226.h"

//时间复杂度O(log(n))
void heapify1(DataType a[], int size, int index)//建大堆
{
	DataType left = 2 * index + 1;//左孩子下标
	DataType right = 2 * index + 2;//右孩子下标

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

void heapify2(DataType a[], int size, int index)//建小堆
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

//时间复杂度O(n*log(n)]])
void CreatHeap(int a[], int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		heapify1(a, size, i);
	}
}

void heapSort(int a[], int size)
{
	// 1. 建堆
	CreatHeap(a, size);

	// 2. 需要 size 次
	for (int i = 0; i < size; i++)
	{
		// 无序区间 [0,size - i)
		// 有序区间 [size - i,size)

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