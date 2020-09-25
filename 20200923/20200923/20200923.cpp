#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

//ºÏ²¢¶þ²æÊ÷
class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr)
			return t2;
		if (t2 == nullptr)
			return t1;
		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);

		return t1;
	}

	TreeNode* creatTree1() {

		TreeNode* n1 = new TreeNode(1);
		TreeNode* n2 = new TreeNode(3);
		TreeNode* n3 = new TreeNode(2);
		TreeNode* n4 = new TreeNode(5);

		n1->left = n2;
		n1->right = n3;
		n2->left = n4;

		return n1;
	}

	TreeNode* creatTree2() {
		
		TreeNode* m1 = new TreeNode(2);
		TreeNode* m2 = new TreeNode(1);
		TreeNode* m3 = new TreeNode(3);
		TreeNode* m4 = new TreeNode(4);
		TreeNode* m5 = new TreeNode(7);
		
		m1->left = m2;
		m1->right = m3;
		m2->right = m4;
		m3->right = m5;

		return m1;
	}
};

int main()
{
	Solution s;
	TreeNode* res=s.mergeTrees(s.creatTree1(), s.creatTree2());

	system("pause");
	return 0;
}