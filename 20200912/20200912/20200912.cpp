#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//二叉树的层平均值

//1.BFS
class Solution1 {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		auto average = vector<double>();
		auto q = queue<TreeNode*>();
		q.push(root);
		while (!q.empty()) {
			double sum = 0;
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				auto node = q.front();
				q.pop();
				sum += node->val;
				auto left = node->left;
				auto right = node->right;
				if (left != nullptr)
					q.push(left);
				if (right != nullptr)
					q.push(right);
			}
			average.push_back(sum / size);
		}
		return average;
	}
};

class Solution2 {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		auto sums = vector<double>();
		auto counts = vector<int>();
		auto res = vector<double>();
		dfs(root, 0, sums, counts);
		int size = counts.size();
		for (int i = 0; i < size; ++i) {
			res.push_back(sums[i] / counts[i]);
		}
		return res;
	}
	void dfs(TreeNode* root, int levels, vector<double>&sums, vector<int>&counts) {
		if (root == nullptr)
			return;
		if (levels < sums.size()) {
			sums[levels] += root->val;
			counts[levels]++;
		}
		else {
				sums.push_back(root->val);
				counts.push_back(1);
		}
		if(root->left!=nullptr)
		dfs(root->left, levels + 1, sums, counts);
		if(root->right!=nullptr)
		dfs(root->right, levels + 1, sums, counts);
	}
};

TreeNode* test()
{
	TreeNode* n1 = new TreeNode(3);

	TreeNode* n2 = new TreeNode(9);

	TreeNode* n3 = new TreeNode(20);

	TreeNode* n4 = new TreeNode(15);

	TreeNode* n5 = new TreeNode(7);

	n1->left = n2;
	n1->right = n3;
	n3->left = n4;
	n3->right = n5;
	
	return n1;
}
int main()
{
	Solution2 s;
	vector<double> res = s.averageOfLevels(test());

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}