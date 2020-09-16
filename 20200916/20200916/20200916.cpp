#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

//��������
#if 0
class Solution {
public:
	//ͳ��һ�������������������
	bitset<9> getPossibleStatus(int x, int y) {

	}
	//ͳ���ĸ���������������٣��ݴ��ʾ����
	vector<int> getNext(vector<vector<char>>& board) {

	}
	//fillnum�������Ǹ���rows[i],cols[j],cells[i/3][j/3]��״̬��Ϣ��ʹ֮��board[i][j]��״̬���Ӧ
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
	//����(�Զ�����)
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

	//����
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

	//����
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