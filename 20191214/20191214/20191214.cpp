#include <iostream>
using namespace std;

//¶þ²æÊ÷µÄ¾µÏñ
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
	void Mirror(TreeNode *pRoot) {
		TreeNode* temp = nullptr;
		if (pRoot == nullptr)
			return;
		else {
			temp = pRoot->left;
			pRoot->left = pRoot->right;
			pRoot->right = temp;
			if (pRoot->left != nullptr)
				Mirror(pRoot->left);
			if (pRoot->right != nullptr)
				Mirror(pRoot->right);
		}
	}
};

int main()
{
	Solution s;
	
	system("pause");
	return 0;
}