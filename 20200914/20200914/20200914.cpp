#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	void inorder(TreeNode* root, vector<int>& res) {
		if (!root) {
			return;
		}
		inorder(root->left, res);
		res.push_back(root->val);
		inorder(root->right, res);
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inorder(root, res);
		return res;
	}
};

TreeNode* CreatTree() {
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	n1->right = n2;
	n2->left = n3;

	return n1;
}

int main()
{
	Solution s;
	vector<int> res = s.inorderTraversal(CreatTree());
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}