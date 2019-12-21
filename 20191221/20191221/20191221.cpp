#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//从上往下打印二叉树，层序遍历
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;  //引入数组，把每层节点的值放入
		if (root == nullptr)
			return res;
		queue<TreeNode*> q;  //引入队列，把每层节点依次加入
		q.push(root);  
		while (!q.empty()) {
			res.push_back(q.front()->val);
			if (q.front()->left != nullptr)
				q.push(q.front()->left);
			if (q.front()->right != nullptr)
				q.push(q.front()->right);
			q.pop();
		}
		return res;
	}
};

TreeNode* TestTree()
{
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);
	n1->left = n2,n1->right = n3;
	n2->left = n4, n2->right = n5;
	n3->left = n6, n3->right = n7;

	return n1;
}

int main()
{
	TreeNode* root=TestTree();
	Solution s;
	vector<int> v = s.PrintFromTopToBottom(root);
	for (auto &e : v) {
		cout << e << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}