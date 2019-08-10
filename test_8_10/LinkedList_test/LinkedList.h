#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct Node {
	int val;
	struct Node* next;
}Node;

//1.头插
Node * ListPushFront(Node* head, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = head;
	return node;
}

//2.尾插
Node * ListPushBack(Node* head, int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	if (head == NULL)
		return node;
	Node *cur = head;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = node;
	return head;
}

//3.打印链表
void ListPrint(Node* head)
{
	Node *cur = head;
	while (cur != NULL)
	{
		printf("%d-->", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

//4.头删
Node * ListPopFront(Node* head)
{
	assert(head != NULL);
	Node *next = head->next;
	free(head);
	return next;
}

//5.尾删
Node * ListPopBack(Node* head)
{
	assert(head != NULL);
	if (head->next == NULL)
	{
		free(head);
		head = NULL;
	}

	else
	{
		Node *cur = head;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
	return head;
}

Test()
{
	Node *head = NULL;	// 链表的初始化

    ListPrint(head);
	head = ListPushFront(head,1);
	ListPrint(head);
	head = ListPushFront(head,2);
	ListPrint(head);
	head = ListPushFront(head,3);
	ListPrint(head);
	head = ListPushFront(head,4);
	ListPrint(head);
	head = ListPushBack(head, 10);
	head = ListPushBack(head, 20);
	head = ListPushBack(head, 30);
	ListPrint(head);


	head = ListPopFront(head);
	head = ListPopFront(head);
	head = ListPopFront(head);
	ListPrint(head);
	head = ListPopBack(head);
	head = ListPopBack(head);
	head = ListPopBack(head);
	head = ListPopBack(head);
	ListPrint(head);

	// 之前的结点内存泄漏了，没有释放
	head = NULL;
	head = ListPushBack(head, 10);
	head = ListPushBack(head, 20);
	ListPrint(head);
    //head 不应该是 NULL 了
	printf("你好世界\n");
}