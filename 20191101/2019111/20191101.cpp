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

		vector<int> left_pre, right_pre, left_in, right_in;//����ǰ������������������������

		TreeNode* head = new TreeNode(pre[0]);//ǰ������ĵ�һ��Ϊ���ڵ�
		int temp = 0;
		for (int i = 0; i < prelen; ++i)//�ҵ����ڵ�����������е�λ�ã��ڸ��ڵ���ߵļ�Ϊ��������������Ϊ������
		{
			if (pre[0] == in[i])
			{
				temp = i;
				break;
			}
		}

		for (int i = 0; i < temp; ++i)//�����ֺõ���������ǰ�������vector�У��ȴ��ݹ�
		{
			left_in.push_back(in[i]);
			left_pre.push_back(pre[i + 1]);
		}

		for (int i = temp + 1; i < prelen; ++i)//�����ֺõ���������ǰ�������vector�У��ȴ��ݹ�
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