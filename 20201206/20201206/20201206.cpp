#include <iostream>
#include <vector>
using namespace std;

//删除排序数组中的重复项，返回数组有效元素的个数
/*
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {  //删除数组中重复元素，时间代价太高
		if (0 == nums.size())
			return 0;
		auto it = nums.begin();
		while (it != nums.end()-1) {
			if (*it == *(it + 1))
				it = nums.erase(it);
			else
				++it;
		}
		return nums.size();
	}
};
*/

#if 0
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		int i = 0;
		for (int j = 1; j < nums.size(); ++j) {
			if (nums[i] == nums[j])
				continue;
			nums[++i] = nums[j];              //不重复的元素覆盖掉前几个元素，返回++i，因为是从0开始的
		}
		return ++i;
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 1,1,2 };
	cout << s.removeDuplicates(nums)<<endl;
	system("pause");
	return 0;
}
#endif

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res(numRows);
		for (size_t i = 0; i < numRows; ++i) {
			res[i].resize(i + 1);
			res[i][0] = res[i][i] = 1;
			for (size_t j = 1; j < i; ++j)
				res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
		}

		return res;
	}
};

int main()
{
	Solution s;
	int n;
	cin >> n;
	vector<vector<int>> ret = s.generate(n);

	system("pause");
	return 0;
}