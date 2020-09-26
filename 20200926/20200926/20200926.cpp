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
//根据一棵树的中序遍历与后序遍历构造二叉树
//中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9, 15, 7, 20, 3]
class Solution {
	int post_idx;                     //后序遍历的下标
	unordered_map<int, int> idx_map;  //存放中序元素值及其下标
public:
	TreeNode* helper(int in_left,int in_right,vector<int>& inorder,vector<int>& postorder) {
		//没有节点构造二叉树时就结束
		if (in_left > in_right)
			return nullptr;

		//选择post_idx位置的元素作为当前子树的根
		int root_val = postorder[post_idx];
		TreeNode* root = new TreeNode(root_val);

		//在中序遍历中找寻当前根的下标并分成左右子树
		int index = idx_map[root_val];

		//后序遍历的标记下标-1
		--post_idx;

		//构造右子树
		root->right=helper(index + 1, in_right, inorder, postorder);
		//构造左子树
		root->left=helper(in_left , index - 1, inorder, postorder);

		return root;
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		//从后序遍历的最后一个元素开始
		post_idx = postorder.size() - 1;
		//将中序元素存入哈希表中
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