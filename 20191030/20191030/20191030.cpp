#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode
{
	struct ListNode* next;
	int val;
};

typedef struct ListNode Node;

class Solution
{
public:
	vector<int>printListFromTailToHead(Node* head)
	{
		vector<int> result;
		stack<int> arr;	
		Node* cur = head;

		while (cur != NULL)
		{
			arr.push(cur->val);
			cur = cur->next;
		}

		while (!arr.empty())
		{
			result.push_back(arr.top());
			arr.pop();
		}
		return result;
	}
};


Node* CreatNode()
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

	return n1;
}

void TestSolution()
{
	Solution s;
	vector<int> x=s.printListFromTailToHead(CreatNode());
	for (int i = 0; i < x.size(); ++i)
		cout << x.at(i) << " " ;
}

int main()
{
	TestSolution();
	cout << endl;

	system("pause");
	return 0;
}