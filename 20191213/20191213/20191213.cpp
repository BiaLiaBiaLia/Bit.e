#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x),
		left(NULL),
		right(NULL) {
	}
};

class Solution {
public:
	bool HasSubtree(TreeNode* pRootA, TreeNode* pRootB)
	{
		if (pRootA == NULL || pRootB == NULL)
			return false;
		return
			isSubtree(pRootA, pRootB) ||
			HasSubtree(pRootA->left, pRootB) ||
			HasSubtree(pRootA->right, pRootB);
	}

	bool isSubtree(TreeNode* pRootA, TreeNode* pRootB) {
		if (pRootB == NULL)
			return true;
		if (pRootA == NULL)
			return false;
		if (pRootB->val == pRootA->val) {
			return
				isSubtree(pRootA->left, pRootB->left) &&
				isSubtree(pRootA->right, pRootB->right);
		}
		else
			return false;
	}
};

int main()
{
	Solution s;
	system("pause");
	return 0;
}