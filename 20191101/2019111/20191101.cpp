#include <iostream>
#include <vector>
using namespace std;

//Definition for binary tree
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) 
		: val(x)
		, left(NULL)
		, right(NULL)
	{}
};

class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) 
	{
		int prelen = pre.size();
		if (0 == prelen)
			return NULL;

		vector<int> left_pre, right_pre, left_in, right_in;//创建前序左右子树，中序左右子树

		TreeNode* head = new TreeNode(pre[0]);//前序遍历的第一个为跟节点
		int temp = 0;
		for (int i = 0; i < prelen; ++i)//找到根节点在中序遍历中的位置，在根节点左边的即为根的左子树，右为右子树
		{
			if (pre[0] == in[i])
			{
				temp = i;
				break;
			}
		}

		for (int i = 0; i < temp; ++i)//将划分好的左子树的前中序插入vector中，等待递归
		{
			left_in.push_back(in[i]);
			left_pre.push_back(pre[i + 1]);
		}

		for (int i = temp + 1; i < prelen; ++i)//将划分好的右子树的前中序插入vector中，等待递归
		{
			right_in.push_back(in[i]);
			right_pre.push_back(pre[i]);
		}

		head->left = reConstructBinaryTree(left_pre, left_in);
		head->right = reConstructBinaryTree(right_pre, right_in);

		return head;
	}
};


void Test()
{
	Solution s;
	vector<int> pre{ 1,2,4,7,3,5,6,8 };
	vector<int> in{ 4,7,2,1,5,3,8,6 };

	TreeNode* result = s.reConstructBinaryTree(pre, in);
}

int main()
{
	Test();

	system("pause");
	return 0;
}