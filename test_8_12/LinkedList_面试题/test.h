#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode
{
	int val;
	struct ListNode *next;
}Node;

void PrintList(Node *head)
{
	Node *cur = head;
	while (cur != NULL)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

// 反转链表
Node * reverseList1(Node *head)//遍历，需两个链表
{
	Node *rhead = NULL;
	Node *cur = head;
	while (cur != NULL)
	{
		Node *next = cur->next;
		cur->next = rhead;
		rhead = cur;
		cur = next;
	}
	return rhead;
}
Node * reverseList2(Node *head)//迭代，只需一个链表
{
	Node *pre = NULL;
	Node *next = NULL;
	Node *rhead = head;
	while (rhead != NULL)
	{
		next = rhead->next;
		rhead->next = pre;
		pre = rhead;
		rhead = next;
	}
	return pre;
}

Node *createTestList1()
{
	Node *n1 = (Node *)malloc(sizeof(Node));
	n1->val = 1;
	Node *n2 = (Node *)malloc(sizeof(Node));
	n2->val = 2;
	Node *n3 = (Node *)malloc(sizeof(Node));
	n3->val = 3;
	Node *n4 = (Node *)malloc(sizeof(Node));
	n4->val = 4;
	Node *n5 = (Node *)malloc(sizeof(Node));
	n5->val = 5;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;

	return n1;//1 2 3 4 5
}

Node *createTestList2()
{
	Node *n1 = (Node *)malloc(sizeof(Node));
	n1->val = 1;
	Node *n2 = (Node *)malloc(sizeof(Node));
	n2->val = 3;
	Node *n3 = (Node *)malloc(sizeof(Node));
	n3->val = 2;
	Node *n4 = (Node *)malloc(sizeof(Node));
	n4->val = 1;
	Node *n5 = (Node *)malloc(sizeof(Node));
	n5->val = 4;
	Node *n6= (Node *)malloc(sizeof(Node));
	n6->val = 3;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;

	return n1;//1 3 2 1 4 3
}
Node *createTestList3()
{
	Node *n1 = (Node *)malloc(sizeof(Node));
	n1->val = 1;
	Node *n2 = (Node *)malloc(sizeof(Node));
	n2->val = 1;
	Node *n3 = (Node *)malloc(sizeof(Node));
	n3->val = 3;
	Node *n4 = (Node *)malloc(sizeof(Node));
	n4->val = 5;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	return n1;//1 1 3 5
}

void test_reverseList()
{
	Node *head=createTestList1();
	PrintList(head);

	Node *result1 = reverseList1(head);
	PrintList(result1);
	Node *result2 = reverseList2(result1);
	PrintList(result2);
}

// 删除链表中所有的 val
//1.空间换时间
//准备一个空链表
//如果不是要删除的节点就尾插
Node * removeElements(Node *head, int val)
{
	Node *rhead = NULL;
	Node *cur = head;
	Node *last = NULL;
	while (cur != NULL)
	{
		Node *next = cur->next;
		if (cur->val != val)//尾插到新链表中
		{
			if (rhead == NULL)
			{
				cur->next = NULL;
				rhead = cur;
			}
			else
			{
				cur->next = NULL;
				last->next = cur;
			}
			last = cur;
		}
		cur = next;
	}
	return rhead;
}

//2.双指针
Node *removeElements2(Node *head, int val)
{
	if (head == NULL)
		return NULL;
	Node *prev = head;
	Node *cur = head->next;
	while (cur != NULL)
	{
		if (cur->val == val)

			prev->next = cur->next;
		else
			prev = cur;
		cur = cur->next;
	}
	if (head->val == val)
		return head->next;
	else
		return head;
}

void testRemoveAll()
{
	Node *head = createTestList2();
	Node *result = removeElements(head, 3);
	Node *result1 = removeElements2(head, 3);
	PrintList(result);//1 2 1 4
	PrintList(result1);//1 2 1 4
}

// 合并有序链表
Node * mergeTwoLists(Node* l1, Node* l2)
{
	//定义一个新链表
	Node *rhead = NULL;
	Node *last = NULL;
	Node *c1 = l1;
	Node *c2 = l2;
	//比较两个有序链表中的值，并尾插到新链表中
	while (c1 != NULL && c2 != NULL)
	{
		if (c1->val <= c2->val)
		{
			Node *next = c1->next;
			c1->next = NULL;
			if (rhead == NULL)
			{
				rhead = c1;
			}
			else
			{
				last->next = c1;
			}
			last = c1;
			c1 = next;
		}
		else
		{
			Node *next = c2->next;
			c2->next = NULL;
			if (rhead == NULL)
			{
				rhead = c2;
			}
			else
			{
				last->next = c2;
			}
			last = c2;
			c2 = next;
		}
	}
	if (c1 != NULL)
		last->next = c1;
	else
		last->next = c2;
	return rhead;
}

void testmergeTwoLists()
{
	Node *c1 = createTestList1();
	Node *c2 = createTestList3();
	Node *head = mergeTwoLists(c1,c2);
	PrintList(head);//111233455
}