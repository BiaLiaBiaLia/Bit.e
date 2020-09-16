#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

//数独问题
#if 0
class Solution {
public:
	//统计一个格子所有能填的数字
	bitset<9> getPossibleStatus(int x, int y) {

	}
	//统计哪个格子能填的数最少，容错率就最大
	vector<int> getNext(vector<vector<char>>& board) {

	}
	//fillnum函数就是更新rows[i],cols[j],cells[i/3][j/3]的状态信息，使之与board[i][j]的状态相对应
};
#endif

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):
		val(x),left(NULL),right(NULL){}
};


class Solution {
public:
	TreeNode* creatTree() {
		TreeNode* n1 = new TreeNode(4);
		TreeNode* n2 = new TreeNode(2);
		TreeNode* n3 = new TreeNode(7);
		TreeNode* n4 = new TreeNode(1);
		TreeNode* n5 = new TreeNode(3);
		TreeNode* n6 = new TreeNode(6);
		TreeNode* n7 = new TreeNode(9);

		n1->left = n2;
		n1->right = n3;
		n2->left = n4;
		n2->right = n5;
		n3->left = n6;
		n3->right = n7;

		return n1;
	}
	//先序(自顶向下)
	TreeNode* inverTree1(TreeNode* root) {
		if (root == NULL)
			return NULL;
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;

		inverTree1(root->left);
		inverTree1(root->right);

		return root;
	}

	//中序
	TreeNode* inverTree2(TreeNode* root) {
		if (root == NULL)
			return NULL;
		inverTree2(root->left);
		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		inverTree2(root->right);

		return root;
	}

	//后序
	TreeNode* inverTree3(TreeNode* root) {
		if (root == NULL)
			return NULL;
		inverTree3(root->left);
		inverTree3(root->right);

		TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;

		return root;
	}
};

int main()
{
	Solution s;
	TreeNode* root = s.creatTree();
	s.inverTree1(root);
	s.inverTree2(root);
	s.inverTree3(root);

	system("pause");
	return 0;
}