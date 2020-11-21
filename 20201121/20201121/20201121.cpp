#include <iostream>
using namespace std;


//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;
		ListNode* newhead = new ListNode(0);  //新建一个节点指向排序好的头节点
		newhead->next = head;
		ListNode* last_sort = head;  //指向排好序的最后一个节点
		ListNode* cur = head->next;  //待排序节点

		while (cur != nullptr) {
			if (last_sort->val <= cur->val)
				last_sort = last_sort->next;  //不需要排序
			else {
				ListNode* p = newhead;  //创建新节点遍历已经有序的链表
				while (p->next->val <= cur->val)
					p = p->next;
				//开始插入节点，插入cur后cur->next会发生改变，所以先更新last_sort
				last_sort->next = cur->next;
				cur->next = p->next;
				p->next = cur;
			}
			cur = last_sort->next;  //更新待排序节点
		}
		return newhead->next;
	}

	void printf_List(ListNode* head) {
		ListNode* cur = head;
		while (cur != nullptr) {
			cout << cur->val << "->";
			cur = cur->next;
		}
		cout << "NULL" << endl;
	}
};

ListNode* creat_List() {
	ListNode* n1 = new ListNode(-1);
	ListNode* n2 = new ListNode(5);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(0);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	return n1;
}

int main()
{
	Solution s;
	ListNode* node = creat_List();

	s.printf_List(s.insertionSortList(node));

	system("pause");
	return 0;
}