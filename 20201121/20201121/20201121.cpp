#include <iostream>
using namespace std;


//���������ͷ��� head ���뽫�䰴 ���� ���в����� ����������

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
		ListNode* newhead = new ListNode(0);  //�½�һ���ڵ�ָ������õ�ͷ�ڵ�
		newhead->next = head;
		ListNode* last_sort = head;  //ָ���ź�������һ���ڵ�
		ListNode* cur = head->next;  //������ڵ�

		while (cur != nullptr) {
			if (last_sort->val <= cur->val)
				last_sort = last_sort->next;  //����Ҫ����
			else {
				ListNode* p = newhead;  //�����½ڵ�����Ѿ����������
				while (p->next->val <= cur->val)
					p = p->next;
				//��ʼ����ڵ㣬����cur��cur->next�ᷢ���ı䣬�����ȸ���last_sort
				last_sort->next = cur->next;
				cur->next = p->next;
				p->next = cur;
			}
			cur = last_sort->next;  //���´�����ڵ�
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