#include <iostream>
#include <vector>
using namespace std;

//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
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

	void moveZeroes2(vector<int>& nums) { //˫ָ�룬iָ���0��jָ��0
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