#include <iostream>
#include <vector>
using namespace std;

//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
class Solution {
public:
	void moveZeroes1(vector<int>& nums) {
		int i = 0, j = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != 0)
				nums[j++] = nums[i];
		}
		while (j < nums.size())
			nums[j++] = 0;
	}

	void moveZeroes2(vector<int>& nums) { //双指针，i指向非0，j指向0
		int i = 0, j = 0;
		int n = nums.size();
		while (j < n) {
			if (nums[j] != 0) {
				swap(nums[i], nums[j]);
				++i;
			}
			++j;
		}
	}
};

int main()
{
	vector<int> nums1 = { 0,1,0,3,12 };
	vector<int> nums2 = { 0,1,2,0,3 };
	Solution s;
	s.moveZeroes1(nums1);
	s.moveZeroes2(nums2);

	system("pause");
	return 0;
}