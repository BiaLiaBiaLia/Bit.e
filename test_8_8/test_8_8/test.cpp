#include "test.h"

#define DEFAULT_CAPACITY (16)

static void ensureCapcity(SeqList *seq)
{
	if (seq->size < seq->capcity)
		return;//容量够用
	else {//容量不够用
		//1.找新房子
		int newCapcity = 2 * seq->capcity;
		int *newArray = (int *)malloc(sizeof(int)*newCapcity);
		//2.全家搬进去
		for (int i = 0; i < seq->size; i++)
		{
			newArray[i] = seq->array[i];
		}
		//3.退掉朋友圈
		free(seq->array);
		//4.发朋友圈
		seq->array = newArray;
	}
}
//初始化
void SeqListInit(SeqList *seq)
{
	// 申请个教室并记录
	seq->array = (int *)malloc(sizeof(int)*DEFAULT_CAPACITY);
	// 记录教室的容量
	seq->capcity = DEFAULT_CAPACITY;
	// size = 0
	seq->size = 0;
}

//销毁
void SeqListDestroy(SeqList *seq)
{
	assert(seq);
	free(seq->array);
	seq->capcity = 0;
	seq->size = 0;
}

//头插
void SeqListPushFront(SeqList *seq, DataType val)
{
	for (int i = seq->size - 1; i >= 0; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = val;
	seq->size++;
}

//尾插
void SeqListPushBack(SeqList *seq, DataType val)
{
	//不考虑放不下的问题
	seq->array[seq->size] = val;
	seq->size++;
}

//根据下标做插入
void SeqListInsert(SeqList *seq, int index, DataType val)
{
	if (index<0 || index>seq->size)
	{
		printf("下标不合法");
		return;
	}
	ensureCapcity(seq);

	for (int i = seq->size; i > index; i--)
	{
		seq->array[i] = seq->array[i - 1];
	}
	seq->array[index] = val;
	seq->size++;
}

//头删
void SeqListPopFront(SeqList *seq)
{
	assert(seq->size > 0);
	for (int i = 0; i < seq->size - 1; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}

//尾删
void SeqListPopBack(SeqList *seq)
{
	assert(seq->size > 0);
	seq->size--;
}

//根据下标做删除
void SeqListErase(SeqList *seq, int index)
{
	assert(seq->size > 0);
	for (int i = index; i < seq->size - 1; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}

// 检测val是否在顺序表中
int SeqListFind(SeqList *seq, DataType val)
{
	assert(seq);
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] == val)
			return i;
	}
	return -1;
}

// 移除顺序表中第一个值为val的元素 
void SeqListRemove(SeqList *seq, DataType val)
{
	assert(seq->size > 0);
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] == val)
		{
			for (int j = i + 1; j < seq->size; j++)
			{
				seq->array[j - 1] = seq->array[j];
			}
			seq->size--;
			break;
		}
	}
}

// 移除顺序表中所有值为val的元素 
void SeqListRemoveAll(SeqList *seq, DataType val)
{
	assert(seq);
	int i = 0;
	int j = 0;
	for (int i = 0; i < seq->size; i++)
	{
		if (seq->array[i] != val)
		{
			seq->array[j] = seq->array[i];
			j++;
		}
	}
	seq->size = j;
}

// 获取顺序表有效元素个数 
int SeqListSize(SeqList *seq)
{
	int size = seq->size;
	return size;
}

// 获取顺序表的容量 
int SeqListCapacity(SeqList *seq)
{
	int capacity = seq->capcity;
	return capacity;
}

// 检测顺序表是否为空 
int SeqListEmpty(SeqList *seq)
{
	if (seq == NULL)
		return 1;
	return 0;
}

// 获取顺序表中第一个元素 
DataType SeqListFront(SeqList *seq)
{
	assert(seq->size > 0);
	DataType a = seq->array[0];
	return a;
}

// 获取顺序表中最后一个元素 
DataType SeqListBack(SeqList *seq)
{
	assert(seq->size > 0);
	DataType a = seq->array[seq->size - 1];
	return a;
}

//打印
void SeqListPrint(SeqList *seq)
{
	for (int i = 0; i < seq->size; i++)
	{
		printf("%d ", seq->array[i]);
	}
	printf("\n");
}


void testSeqList() {
	//初始化
	//销毁
	//增/删/查/改

	SeqList seqList;	// 没有初始化
	// SeqListInit(seqList); 不用它
	SeqListInit(&seqList);
	// 1. 初始化一定会变更变量的值，值传递没有用
	// 2. 指针比结构体大小要小

	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 4);//尾插1 2 3 4

	SeqListPrint(&seqList);	// 1, 2, 3, 4

	SeqListPushFront(&seqList, 10);
	SeqListPushFront(&seqList, 20);
	SeqListPushFront(&seqList, 30);//头插10 20 30

	SeqListPrint(&seqList);	// 30, 20, 10, 1, 2, 3, 4

	SeqListInsert(&seqList, 3, 100);
	SeqListInsert(&seqList, 2, 200);//指定下标插入

	SeqListPrint(&seqList);	// 30, 20, 200, 10, 100, 1, 2, 3, 4

	SeqListPopFront(&seqList);
	SeqListPopFront(&seqList);

	SeqListPrint(&seqList);	// 200, 10, 100, 1, 2, 3, 4

	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);

	SeqListPrint(&seqList);	// 200, 10, 100, 1, 2

	SeqListErase(&seqList, 1);
	SeqListPrint(&seqList);	// 200, 100, 1, 2
	SeqListPushBack(&seqList, 100);
	SeqListPrint(&seqList);//200, 100, 1, 2, 100

	int x = SeqListFind(&seqList, 100);
	printf("%d\n", x);//1

	SeqListRemove(&seqList, 100);
	SeqListPrint(&seqList);//200, 1, 2, 100

	SeqListRemoveAll(&seqList, 100);
	SeqListPrint(&seqList);//200, 1, 2

	int z = SeqListSize(&seqList);
	printf("%d\n", z);//3

	int c = SeqListCapacity(&seqList);
	printf("%d\n", c);//16

	int m = SeqListEmpty(&seqList);
	printf("%d\n", m);//0

	int size = SeqListFront(&seqList);
	printf("%d\n", size);//200

	// 获取顺序表中最后一个元素 
	int size1 = SeqListBack(&seqList);
	printf("%d\n", size1);//2

	SeqListDestroy(&seqList);
}

int main() {
	testSeqList();

	system("pause");
	return 0;
}