#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//ȫ����2
class Solution {
private:
	vector<vector<int>> result;
	void backtracking(vector<int>& nums, vector<int>& vec, vector<bool>& used) {
		// ��ʱ˵���ҵ���һ��
		if (vec.size() == nums.size()) {
			result.push_back(vec);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			// �������used[i - 1]�ǳ���Ҫ 
			// used[i - 1] == true��˵��ͬһ��֧nums[i - 1]ʹ�ù� 
			// used[i - 1] == false��˵��ͬһ����nums[i - 1]ʹ�ù�
			// ���ͬһ����nums[i - 1]ʹ�ù���ֱ������
			if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
				continue;
			}
			if (used[i] == false) {
				used[i] = true;
				vec.push_back(nums[i]);
				backtracking(nums, vec, used);
				vec.pop_back();
				used[i] = false;
			}
		}
	}

public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<bool> used(nums.size(), false);
		vector<int> vec;
		backtracking(nums, vec, used);
		return result;

	}
};

int main()
{
	Solution s;
	vector<int> nums = { 1,1,2 };
	vector<int> res;
	s.permuteUnique(nums);

	system("pause");
	return 0;
}