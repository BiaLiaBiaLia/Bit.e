#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;
typedef struct SqeList {
	int *array;     //记录数据存放位置
	int capcity;    //记录总容量
	int size;       //记录已有数据个数
}SeqList;

//初始化
void SeqListInit(SeqList *seq);

//销毁
void SeqListDestroy(SeqList *seq);

//头插
void SeqListPushFront(SeqList *seq, DataType val);

//尾插
void SeqListPushBack(SeqList *seq, DataType val);

//根据下标做插入
void SeqListInsert(SeqList *seq, int index, DataType val);

//头删
void SeqListPopFront(SeqList *seq);

//尾删
void SeqListPopBack(SeqList *seq);

//根据下标做删除
void SeqListErase(SeqList *seq, int index);

// 检测data是否在顺序表中
int SeqListFind(SeqList *seq, DataType val);

// 移除顺序表中第一个值为val的元素 
void SeqListRemove(SeqList *seq, DataType val);


// 移除顺序表中所有值为val的元素 
void SeqListRemoveAll(SeqList *seq, DataType val);

// 获取顺序表有效元素个数 
int SeqListSize(SeqList *seq);

// 获取顺序表的容量 
int SeqListCapacity(SeqList *seq);

// 检测顺序表是否为空 
int SeqListEmpty(SeqList *seq);

// 获取顺序表中第一个元素 
DataType SeqListFront(SeqList *seq);

// 获取顺序表中最后一个元素 
DataType SeqListBack(SeqList *seq);

//打印
void SeqListPrint(SeqList *seq);