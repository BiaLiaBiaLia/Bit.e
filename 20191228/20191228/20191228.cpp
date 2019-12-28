#include "20191228.h"

// ��ʼ������ 
void QueueInit(Queue* q)
{
	q->_front = q->_rear = (QNode *)malloc(sizeof(QNode));
	q->_front = NULL;
}

// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	QNode * node = (QNode *)malloc(sizeof(QNode));
	node->_data = data;
	node->_pNext = NULL;

	if (q->_front == NULL)
	{
		q->_front = node;
	}
	else
	{
		q->_rear->_pNext = node;
	}
	q->_rear = node;
}

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q->_front != NULL);

	QNode *Second = q->_front->_pNext;
	free(q->_front);
	q->_front = Second;

	if (q->_front == NULL)
	{
		q->_rear = NULL;
	}
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q->_front != NULL);
	return q->_front->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q->_front != NULL);
	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q->_front != NULL);
	int count = 0;
	QNode *node = (QNode *)malloc(sizeof(QNode));
	node = q->_front;
	while (node != NULL)
	{
		count++;
		node = node->_pNext;
	}
	return count;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	return NULL == q->_front;
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	while (q->_front != NULL)
	{
		q->_rear = q->_front->_pNext;
		free(q->_front);
		q->_front = q->_rear;
	}
}

void test()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	QueuePop(&q);
	QueuePop(&q);

	printf("%d\n", QueueFront(&q));

	printf("%d\n", QueueBack(&q));

	printf("%d\n", QueueSize(&q));

	printf("%d\n", QueueEmpty(&q));

	QueueDestroy(&q);

}

int main()
{
	test();
	system("pause");
	return 0;
}