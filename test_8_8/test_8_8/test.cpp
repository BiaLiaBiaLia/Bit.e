#include "test.h"

#define DEFAULT_CAPACITY (16)

static void ensureCapcity(SeqList *seq)
{
	if (seq->size < seq->capcity)
		return;//��������
	else {//����������
		//1.���·���
		int newCapcity = 2 * seq->capcity;
		int *newArray = (int *)malloc(sizeof(int)*newCapcity);
		//2.ȫ�Ұ��ȥ
		for (int i = 0; i < seq->size; i++)
		{
			newArray[i] = seq->array[i];
		}
		//3.�˵�����Ȧ
		free(seq->array);
		//4.������Ȧ
		seq->array = newArray;
	}
}
//��ʼ��
void SeqListInit(SeqList *seq)
{
	// ��������Ҳ���¼
	seq->array = (int *)malloc(sizeof(int)*DEFAULT_CAPACITY);
	// ��¼���ҵ�����
	seq->capcity = DEFAULT_CAPACITY;
	// size = 0
	seq->size = 0;
}

//����
void SeqListDestroy(SeqList *seq)
{
	assert(seq);
	free(seq->array);
	seq->capcity = 0;
	seq->size = 0;
}

//ͷ��
void SeqListPushFront(SeqList *seq, DataType val)
{
	for (int i = seq->size - 1; i >= 0; i--)
	{
		seq->array[i + 1] = seq->array[i];
	}
	seq->array[0] = val;
	seq->size++;
}

//β��
void SeqListPushBack(SeqList *seq, DataType val)
{
	//�����ǷŲ��µ�����
	seq->array[seq->size] = val;
	seq->size++;
}

//�����±�������
void SeqListInsert(SeqList *seq, int index, DataType val)
{
	if (index<0 || index>seq->size)
	{
		printf("�±겻�Ϸ�");
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

//ͷɾ
void SeqListPopFront(SeqList *seq)
{
	assert(seq->size > 0);
	for (int i = 0; i < seq->size - 1; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}

//βɾ
void SeqListPopBack(SeqList *seq)
{
	assert(seq->size > 0);
	seq->size--;
}

//�����±���ɾ��
void SeqListErase(SeqList *seq, int index)
{
	assert(seq->size > 0);
	for (int i = index; i < seq->size - 1; i++)
	{
		seq->array[i] = seq->array[i + 1];
	}
	seq->size--;
}

// ���val�Ƿ���˳�����
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

// �Ƴ�˳����е�һ��ֵΪval��Ԫ�� 
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

// �Ƴ�˳���������ֵΪval��Ԫ�� 
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

// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListSize(SeqList *seq)
{
	int size = seq->size;
	return size;
}

// ��ȡ˳�������� 
int SeqListCapacity(SeqList *seq)
{
	int capacity = seq->capcity;
	return capacity;
}

// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(SeqList *seq)
{
	if (seq == NULL)
		return 1;
	return 0;
}

// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListFront(SeqList *seq)
{
	assert(seq->size > 0);
	DataType a = seq->array[0];
	return a;
}

// ��ȡ˳��������һ��Ԫ�� 
DataType SeqListBack(SeqList *seq)
{
	assert(seq->size > 0);
	DataType a = seq->array[seq->size - 1];
	return a;
}

//��ӡ
void SeqListPrint(SeqList *seq)
{
	for (int i = 0; i < seq->size; i++)
	{
		printf("%d ", seq->array[i]);
	}
	printf("\n");
}


void testSeqList() {
	//��ʼ��
	//����
	//��/ɾ/��/��

	SeqList seqList;	// û�г�ʼ��
	// SeqListInit(seqList); ������
	SeqListInit(&seqList);
	// 1. ��ʼ��һ������������ֵ��ֵ����û����
	// 2. ָ��Ƚṹ���СҪС

	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 4);//β��1 2 3 4

	SeqListPrint(&seqList);	// 1, 2, 3, 4

	SeqListPushFront(&seqList, 10);
	SeqListPushFront(&seqList, 20);
	SeqListPushFront(&seqList, 30);//ͷ��10 20 30

	SeqListPrint(&seqList);	// 30, 20, 10, 1, 2, 3, 4

	SeqListInsert(&seqList, 3, 100);
	SeqListInsert(&seqList, 2, 200);//ָ���±����

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

	// ��ȡ˳��������һ��Ԫ�� 
	int size1 = SeqListBack(&seqList);
	printf("%d\n", size1);//2

	SeqListDestroy(&seqList);
}

int main() {
	testSeqList();

	system("pause");
	return 0;
}