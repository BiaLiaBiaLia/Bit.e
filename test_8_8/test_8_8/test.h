#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct SqeList {
	int *array;     //��¼���ݴ��λ��
	int capcity;    //��¼������
	int size;       //��¼�������ݸ���
}SeqList;

//��ʼ��
void SeqListInit(SeqList *seq);

//����
void SeqListDestroy(SeqList *seq);

//ͷ��
void SeqListPushFront(SeqList *seq, DataType val);

//β��
void SeqListPushBack(SeqList *seq, DataType val);

//�����±�������
void SeqListInsert(SeqList *seq, int index, DataType val);

//ͷɾ
void SeqListPopFront(SeqList *seq);

//βɾ
void SeqListPopBack(SeqList *seq);

//�����±���ɾ��
void SeqListErase(SeqList *seq, int index);

// ���data�Ƿ���˳�����
int SeqListFind(SeqList *seq, DataType val);

// �Ƴ�˳����е�һ��ֵΪval��Ԫ�� 
void SeqListRemove(SeqList *seq, DataType val);


// �Ƴ�˳���������ֵΪval��Ԫ�� 
void SeqListRemoveAll(SeqList *seq, DataType val);

// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListSize(SeqList *seq);

// ��ȡ˳�������� 
int SeqListCapacity(SeqList *seq);

// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(SeqList *seq);

// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListFront(SeqList *seq);

// ��ȡ˳��������һ��Ԫ�� 
DataType SeqListBack(SeqList *seq);

//��ӡ
void SeqListPrint(SeqList *seq);