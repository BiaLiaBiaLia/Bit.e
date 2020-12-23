#include <iostream>
#include <vector>
using namespace std;


//插入排序
//时间复杂度O(n2)   空间复杂度O(1)    稳定
void InsertSort(vector<int>& nums) {
	
	for (size_t i = 0; i < nums.size(); ++i) {
		//保存待插入的元素
		int tmp = nums[i];
		//待插入元素前一个位置的下标
		int last = i - 1;
		while (last >= 0 && tmp < nums[last]) { //待插入元素小于last就将last+1位置的元素覆盖掉，last前移一个元素
			nums[last + 1] = nums[last];
			--last;
		}
		nums[last + 1] = tmp;
	}
}

void PrintVec(vector<int> nums) {
	for (auto e : nums)
		cout << e << " ";
	cout << endl;
}

int main()
{
	vector<int> nums = { 3,8,2,9,5,6,0,7,1,4 };
	PrintVec(nums);
	InsertSort(nums);
	PrintVec(nums);

	system("pause");
	return 0;
}
