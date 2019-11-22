#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

//查找输入二进制整数中1的个数
//1.经典位操作
#if 0
int main()
{
	int n,count;
	while (cin >> n) {
		count = 0;
		if (0 == n) {
			cout << 0 << endl;
			break;
		}
		while (n) {
			n &= n - 1;
			++count;
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}
#endif

//2.位图
#if 0
class Solution
{
public:
	static int findNumberOf1(int num) {
		bitset<32> bs(num);
		return bs.count();
	}
};

int main()
{
	int n;
	while (cin >> n) {
		Solution s;
		cout << s.findNumberOf1(n) << endl;
	}

	system("pause");
	return 0;
}
#endif

//手套(类似抽屉原理)
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
	int n = 4;
	vector<int> v1 = { 0,7,1,6 };
	vector<int> v2 = { 1,5,0,6 };

	Gloves g;
	cout << g.findMinimum(n, v1, v2) << endl;

	system("pause");
	return 0;
}