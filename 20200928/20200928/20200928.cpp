#include <iostream>
#include <vector>
using namespace std;

#if 0
int main()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	vector<int>::iterator it = v.begin();
	v.insert(it, 100);



	/*std::vector<int> myvector(3, 100);
	myvector.push_back(222);
	cout << myvector.capacity() << endl;
	cout << myvector.size() << endl;
	std::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert(it+1, 200);

	cout << myvector.capacity() << endl;
	cout << myvector.size() << endl;*/

	for (auto& e : v)
		cout << e << " ";
	cout << endl;

	system("pause");
	return 0;
}
#endif

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

TreeNode* creatTree() {
	TreeNode* n1 = new TreeNode(5);
	TreeNode* n2 = new TreeNode(4);
	TreeNode* n3 = new TreeNode(8);
	TreeNode* n4 = new TreeNode(11);
	TreeNode* n5 = new TreeNode(13);
	TreeNode* n6 = new TreeNode(4);
	TreeNode* n7 = new TreeNode(7);
	TreeNode* n8 = new TreeNode(2);
	TreeNode* n9 = new TreeNode(5);
	TreeNode* n10 = new TreeNode(1);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n3->left = n5;
	n3->right = n6;
	n4->left = n7;
	n4->right = n8;
	n6->left = n9;
	n6->right = n10;

	return n1;
}
class Solution {
public:
	vector<vector<int>> res;
	vector<int> cur;
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		dfs(root, sum);
		return res;
	}
	void dfs(TreeNode* root, int sum) {
		if (!root)
			return;
		cur.push_back(root->val);
		if (root->val == sum && (root->left == nullptr&&root->right == nullptr)) {
			res.push_back(cur);
		}
		sum -= root->val;
		dfs(root->left, sum);
		dfs(root->right, sum);
		cur.pop_back();
	}

	void printVector(vector<vector<int>> res) {
		for (int i = 0; i < res.size(); ++i) {
			for (int j = 0; j < res[i].size(); ++j) {
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	Solution s;
	TreeNode* root = creatTree();
	s.printVector(s.pathSum(root, 22));

	system("pause");
	return 0;
}