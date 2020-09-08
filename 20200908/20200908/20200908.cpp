#include <iostream>
#include <vector>
using namespace std;

//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合
class Solution {
public:
	vector<int> temp;
	vector<vector<int>> ans;

	void dfs(int cur, int n, int k) {
		// 剪枝：temp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 temp
		if (temp.size() + (n - cur + 1) < k) {
			return;
		}
		// 记录合法的答案
		if (temp.size() == k) {
			ans.push_back(temp);
			return;
		}
		// 考虑选择当前位置
		temp.push_back(cur);
		dfs(cur + 1, n, k);
		temp.pop_back();
		// 考虑不选择当前位置
		dfs(cur + 1, n, k);
	}

	vector<vector<int>> combine(int n, int k) {
		dfs(1, n, k);
		return ans;
	}
};

int main() {
	Solution s;
	vector<vector<int>> res = s.combine(4, 2);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}