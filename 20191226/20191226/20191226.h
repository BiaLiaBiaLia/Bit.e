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

void heapify1(DataType a[], int size, int index);//�����:����
void heapify2(DataType a[], int size, int index);//��С�ѣ�topk����

// ������ 
void CreatHeap(int a[], int size);

// ����в���ֵΪdata��Ԫ�� 
void InsertHeap(Heap* hp, DataType data);

// ɾ���Ѷ�Ԫ�� 
void EraseHeap(Heap* hp);

// ��ȡ������ЧԪ�ظ��� 
int SizeHeap(Heap* hp);

// �����Ƿ�Ϊ�� 
int EmptyHeap(Heap* hp);

// ��ȡ�Ѷ�Ԫ�� 
DataType TopHeap(Heap* hp);

// ���ٶ� 
void DestroyHeap(Heap* hp);
//4. �ú���ָ��Զѽ�����չ��ʹ�û�������Ҫȥ������ѻ���С��
//5