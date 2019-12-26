#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct Heap
{
	DataType* _array;
	int _capacity;
	int _size;
}Heap;

void heapify1(DataType a[], int size, int index);//建大堆:堆排
void heapify2(DataType a[], int size, int index);//建小堆：topk问题

// 创建堆 
void CreatHeap(int a[], int size);

// 向堆中插入值为data的元素 
void InsertHeap(Heap* hp, DataType data);

// 删除堆顶元素 
void EraseHeap(Heap* hp);

// 获取堆中有效元素个数 
int SizeHeap(Heap* hp);

// 检测堆是否为空 
int EmptyHeap(Heap* hp);

// 获取堆顶元素 
DataType TopHeap(Heap* hp);

// 销毁堆 
void DestroyHeap(Heap* hp);
//4. 用函数指针对堆进行扩展，使用户根据需要去创建大堆还是小堆
//5