#include "20200103.h"

// 初始化栈 
void StackInit(Stack* ps)
{
	ps->_array = (SDataType*)malloc(sizeof(SDataType)*Stack_Szie);
	ps->_top = 0;
}

// 入栈 
void StackPush(Stack* ps, SDataType data)
{
	ps->_array[ps->_top++] = data;
}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps->_top > 0);
	ps->_array[--ps->_top];
}

// 获取栈顶元素 
SDataType StackTop(Stack* ps)
{
	assert(ps->_top > 0);
	return ps->_array[ps->_top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	return ps->_top == 0 ? 1 : 0;
}

// 销毁栈 
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