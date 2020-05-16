#include <iostream>
#include <map>
#include <vector>
using namespace std;

//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map <int, int> m;

		for (int i = 0; i < nums.size(); ++i) {
			if (m.find(target - nums[i]) != m.end())
				return { m[target - nums[i]] , i };

			m[nums[i]] = i;
		}
		return {};
	}
};

int main()
{
	Solution s;
	vector<int> v = { 2,7,11,15 };
	vector<int> res(1);
	res = s.twoSum(v, 9);
	for (auto &e : res) {
		cout << e << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
