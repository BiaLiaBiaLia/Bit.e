#include <iostream>
#include <vector>
using namespace std;

//有序数组中的单一数字
//二分查找
class Solution {
public:
	/*int singleNonDuplicate(vector<int>& nums) {
		int lo = 0;
		int hi = nums.size() - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			bool halvesAreEven = (hi - mid) % 2 == 0;
			if (nums[mid + 1] == nums[mid]) {
				if (halvesAreEven) {
					lo = mid + 2;
				}
				else {
					hi = mid - 1;
				}
			}
			else if (nums[mid - 1] == nums[mid]) {
				if (halvesAreEven) {
					hi = mid - 2;
				}
				else {
					lo = mid + 1;
				}
			}
			else {
				return nums[mid];
			}
		}
		return nums[hi];
	}
	*/


	int singleNonDuplicate(vector<int>& nums) {
		int lo = 0;
		int hi = nums.size() - 1;
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			if (mid % 2 == 1) mid--;
			if (nums[mid] == nums[mid + 1]) {
				lo = mid + 2;
			}
			else {
				hi = mid;
			}
		}
		return nums[lo];
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 1,1,2,2,3,4,4,5,5 };
	cout << s.singleNonDuplicate(nums) << endl;

	system("pause");
	return 0;
}