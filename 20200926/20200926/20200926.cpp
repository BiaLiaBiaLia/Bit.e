#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
//����һ������������������������������
//������� inorder = [9,3,15,20,7]
//������� postorder = [9, 15, 7, 20, 3]
class Solution {
	int post_idx;                     //����������±�
	unordered_map<int, int> idx_map;  //�������Ԫ��ֵ�����±�
public:
	TreeNode* helper(int in_left,int in_right,vector<int>& inorder,vector<int>& postorder) {
		//û�нڵ㹹�������ʱ�ͽ���
		if (in_left > in_right)
			return nullptr;

		//ѡ��post_idxλ�õ�Ԫ����Ϊ��ǰ�����ĸ�
		int root_val = postorder[post_idx];
		TreeNode* root = new TreeNode(root_val);

		//�������������Ѱ��ǰ�����±겢�ֳ���������
		int index = idx_map[root_val];

		//��������ı���±�-1
		--post_idx;

		//����������
		root->right=helper(index + 1, in_right, inorder, postorder);
		//����������
		root->left=helper(in_left , index - 1, inorder, postorder);

		return root;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		//�Ӻ�����������һ��Ԫ�ؿ�ʼ
		post_idx = postorder.size() - 1;
		//������Ԫ�ش����ϣ����
		int idx = 0;
		for (auto& val : inorder) {
			idx_map[val] = idx++;
		}
		return helper(0, post_idx, inorder, postorder);
	}
};

int main()
{
	vector<int> inorder = { 9, 3, 15, 20, 7 };
	vector<int> postorder = { 9, 15, 7, 20, 3 };
	Solution s;
	s.buildTree(inorder, postorder);

	system("pause");
	return 0;
}