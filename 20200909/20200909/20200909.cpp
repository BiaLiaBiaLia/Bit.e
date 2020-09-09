#include <iostream>
#include <vector>
using namespace std;

#if 0
//1.子集(数学归纳)
//subset([1,2,3])= A + [A[i].add(3) for i = 1..len(A)]
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		// base case，返回一个空集
		if (nums.empty())
			return { {} };
		// 把最后一个元素拿出来
		int n = nums.back();
		nums.pop_back();
		// 先递归算出前面元素的所有子集
		vector<vector<int>> res = subsets(nums);

		int size = res.size();
		for (int i = 0; i < size; i++) {
			// 然后在之前的结果之上追加
			res.push_back(res[i]);
			res.back().push_back(n);
		}
		return res;
	}
};
#endif

#if 0
//1.子集(回溯算法)
class Solution {
public:
	vector<vector<int>> res;

	vector<vector<int>> subsets(vector<int>& nums) {
		// 记录走过的路径
		vector<int> track;
		backtrack(nums, 0, track);
		return res;
	}

	void backtrack(vector<int>& nums, int start, vector<int>& track) {
		res.push_back(track);
		for (int i = start; i < nums.size(); i++) {
			// 做选择
			track.push_back(nums[i]);
			// 回溯
			backtrack(nums, i + 1, track);
			// 撤销选择
			track.pop_back();
		}
	}
};

int main()
{
	vector<int> n = { 1,2,3 };
	vector<vector<int>> res;
	Solution s;
	res = s.subsets(n);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}

	system("pause");
	return 0;
}
#endif