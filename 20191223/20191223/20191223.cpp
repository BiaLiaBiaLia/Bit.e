#include <iostream>
#include <algorithm>
using namespace std;

//二叉树的深度
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
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return 0;
		return max(1 + TreeDepth(pRoot->left), 1 + TreeDepth(pRoot->right));
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
	n1->left = n2, n1->right = n3;
	n2->left = n4, n2->right = n5;
	n3->left = n6, n3->right = n7;

	return n1;
}

int main()
{
	Solution s;
	TreeNode* root = TestTree();
	cout << s.TreeDepth(root) << endl;

	system("pause");
	return 0;
}