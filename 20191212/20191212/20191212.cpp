#include <iostream>
using namespace std;

//反转链表
#if 0
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		if (pHead == nullptr)
			return nullptr;
		ListNode* pre = nullptr;
		ListNode* next = nullptr;
		ListNode* node = pHead;
		while (node != nullptr) {
			next = node->next;
			node->next = pre;
			pre = node;
			node = next;
		}
		return pre;
	}
};

void Test()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	ListNode* cur = n1;
	while (cur != nullptr) {
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;

	Solution s;
	ListNode* p = s.ReverseList(n1);

	while (p != nullptr) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	Test();

	system("pause");
	return 0;
}
#endif


//合并两个排序的链表
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		if (pHead2 == nullptr)
			return pHead1;

		ListNode* cur = new ListNode(-1);
		cur->next = nullptr;
		ListNode* result = cur;
		while (pHead1 != nullptr && pHead2 != nullptr) {
			if (pHead1->val < pHead2->val) {
				cur->next = pHead1;
				cur = pHead1;
				pHead1 = pHead1->next;
			}
			else {
				cur->next = pHead2;
				cur = pHead2;
				pHead2 = pHead2->next;
			}
		}
		if (pHead1 == nullptr)
			cur->next = pHead2;
		else
			cur->next = pHead1;

		return result->next;
	}
};

void Test()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);
	ListNode* n6 = new ListNode(6);
	n1->next = n3;
	n3->next = n5;

	n2->next = n4;
	n4->next = n6;

	ListNode* cur1 = n1;
	while (cur1 != nullptr) {
		cout << cur1->val << " ";
		cur1 = cur1->next;
	}
	cout << endl;
	ListNode* cur2 = n2;
	while (cur2 != nullptr) {
		cout << cur2->val << " ";
		cur2 = cur2->next;
	}
	cout << endl;

	Solution s;
	ListNode* p = s.Merge(n1, n2);

	while (p != nullptr) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
	Test();

	system("pause");
	return 0;
}