#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
};

typedef struct ListNode Node;

class Solution
{
public:
	vector<int> printListFromTailToHead(Node* head)
	{
		//初始化三个指针prev为NULL，cur为head，next为NULL
		Node* prev = NULL;
		Node* cur = head;
		Node* nextt = NULL;
		Node* nhead = NULL;

		while (cur != NULL)
		{
			nextt = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nextt;
		}
		nhead = prev;

		vector<int> v;
		while (nhead != NULL)
		{
			v.push_back(nhead->val);
			nhead = nhead->next;
		}
		return v;
	}

	void PrintVector(vector<int> x)
	{
		for (int i = 0; i < x.size(); ++i)
		{
			cout << x.at(i)<<" ";
		}
		cout << endl;
	}

};

void Test()
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

	Solution s;
	vector<int> x=s.printListFromTailToHead(n1);
	s.PrintVector(x);
}

int main()
{
	Test();

	system("pause");
	return 0;
}