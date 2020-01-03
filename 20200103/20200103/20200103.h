#pragma once
#include <assert.h>
#include <iostream>
using namespace std;

#define Stack_Szie 10
typedef int SDataType;
typedef struct Stack
{
	SDataType* _array;
	int _capacity;
	int _top; // 标记栈顶位置 
}Stack;


// 初始化栈 
void StackInit(Stack* ps);

// 入栈 
void StackPush(Stack* ps, SDataType data);

// 出栈 
void StackPop(Stack* ps);

// 获取栈顶元素 
SDataType StackTop(Stack* ps);

// 获取栈中有效元素个数 
int StackSize(Stack* ps);

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps);

// 销毁栈 
void StackDestroy(Stack* ps);