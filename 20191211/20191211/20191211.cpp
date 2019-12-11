#include <iostream>
using namespace std;

//链表中倒数第k个节点
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == nullptr)
			return nullptr;
		ListNode* cur1 = pListHead;
		ListNode* cur2 = pListHead;
		for (int i = 0; i < k; ++i) {
			if (!cur1)
				return nullptr;
			else
				cur1 = cur1->next;
		}
		while (cur1) {
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur2;
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

	Solution s;
	ListNode* p=s.FindKthToTail(n1, 2);
	cout << p->val << endl;
}

int main()
{
	Test();

	system("pause");
	return 0;
}