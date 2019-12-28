#include "20191228.h"

// 初始化队列 
void QueueInit(Queue* q)
{
	q->_front = q->_rear = (QNode *)malloc(sizeof(QNode));
	q->_front = NULL;
}

// 队尾入队列 
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

// 队头出队列 
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

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q->_front != NULL);
	return q->_front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q->_front != NULL);
	return q->_rear->_data;
}

// 获取队列中有效元素个数 
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

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	return NULL == q->_front;
}

// 销毁队列 
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