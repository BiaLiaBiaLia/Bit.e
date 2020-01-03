#include "20200103.h"

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	ps->_array = (SDataType*)malloc(sizeof(SDataType)*Stack_Szie);
	ps->_top = 0;
}

// ��ջ 
void StackPush(Stack* ps, SDataType data)
{
	ps->_array[ps->_top++] = data;
}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps->_top > 0);
	ps->_array[--ps->_top];
}

// ��ȡջ��Ԫ�� 
SDataType StackTop(Stack* ps)
{
	assert(ps->_top > 0);
	return ps->_array[ps->_top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	return ps->_top == 0 ? 1 : 0;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	free(ps);
	ps->_array = NULL;
	ps->_top = NULL;
	ps->_top = 0;
}

void test()
{
	Stack ps;
	StackInit(&ps);

	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);

	StackPop(&ps);
	StackPop(&ps);

	int n = StackTop(&ps);
	printf("%d\n", n);//2

	int m = StackSize(&ps);
	printf("%d\n", m);//2

	int z = StackEmpty(&ps);
	printf("%d\n", z);//0
}

int main()
{
	test();

	system("pause");
	return 0;
}