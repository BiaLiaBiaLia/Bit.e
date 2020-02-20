#include<iostream>
using namespace std;
const int N = 6;
typedef int DataType;//类型定义

typedef struct node { //单链表
	DataType data;
	struct node* next;
}LinkedNode, *LinkList;

LinkList CreateList(DataType a[N])
{
	LinkedNode* ListHead = new LinkedNode();
	ListHead->data = a[0];
	ListHead->next = NULL;
	for (int i = N - 1; i >= 1; i--)
	{
		LinkedNode* p = new LinkedNode();
		p->data = a[i];
		p->next = ListHead->next;
		ListHead->next = p;
	}
	return ListHead;
}

/****输出单链表****/
void PrintList(LinkList ListHead)
{
	if (NULL == ListHead)cout << "The List is empty!" << endl;
	else
	{
		LinkedNode* p = ListHead;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

void ReverseList(LinkedNode* pCur, LinkList& ListHead)
{
	if ((NULL == pCur) || (NULL == pCur->next))
	{
		ListHead = pCur;
	}
	else
	{
		LinkedNode* pNext = pCur->next;
		ReverseList(pNext, ListHead); //递归逆置后继结点
		pNext->next = pCur;            //将后继结点指向当前结点。
		pCur->next = NULL;
	}
}

int main()
{
	int a[N] = { 1,2,3,4,5,6 };
	LinkedNode* list = CreateList(a);
	PrintList(list);
	LinkedNode*pTemp = list;
	ReverseList(pTemp, list);
	PrintList(list);

	system("pause");
	return 0;
}