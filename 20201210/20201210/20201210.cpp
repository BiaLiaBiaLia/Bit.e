#include <bitset>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//查找输入整数二进制中一的个数
#if 0
class Solution
{
public:
	static int findNumberOf1(int num);

	int findNumberof1(int num) {
		int count = 0;
		while (num) {
			++count;
			num &= num - 1;
		}
		return count;
	}
};

int Solution:: findNumberOf1(int num)
{
	bitset<32> b(num);
	return b.count();
}

int main()
{
	Solution s;
	int num;
	while (cin >> num)
		cout << s.findNumberOf1(num) << "  " << s.findNumberof1(num) << endl;

	system("pause");
	return 0;
}
#endif

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int left_min = INT_MAX, left_sum = 0;
		int right_min = INT_MAX, right_sum = 0;
		int sum = 0;

		for (int i = 0; i < n; ++i) {
			if (left[i] * right[i] == 0) {//任何颜色只要有一方为0，就需要将同种颜色的全拿走
				sum += left[i] + right[i];
			}
			else
			{
				//统计左右手某颜色数量最少的手套个数以及左右两边的数量
				left_min = min(left[i], left_min);
				right_min = min(right[i], right_min);

				left_sum += left[i];
				right_sum += right[i];
			}
		}
		//比较左右两边(left,right)_sum的值，取最小的一边+1，保证能覆盖所有的颜色，在另一半随意取一个，都能有对应颜色的手套
		//不要忘了加上sum
		return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};

int main()
{
	Gloves g;
	int nums;
	while (cin >> nums) {
		vector<int> left(nums,0), right(nums,0);
		for (int i = 0; i < nums; ++i)
			cin >> left[i];
		for (int i = 0; i < nums; ++i)
			cin >> right[i];

		cout << g.findMinimum(nums, left, right) << endl;
	}

	system("pause");
	return 0;
}