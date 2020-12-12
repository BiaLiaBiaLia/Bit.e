#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//拿手套
class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int sum = 0;  //只要有一方颜色为0，将另只手该颜色全拿，sum也就表示的必拿手套数量
		int sum_left = 0, sum_right = 0, left_min = 27, right_min = 27;
		//左右手除0之外所有手套合   &&  左右手除0之外颜色最少的手套数量
		for (int i = 0; i < n; ++i) {
			if (0 == left[i] || 0 == right[i])
				sum += left[i] + right[i];
			else {
				sum_left += left[i];
				left_min = min(left_min, left[i]);
				sum_right += right[i];
				right_min = min(right_min, right[i]);
			}
		}

		//2指的是在左右手各拿一只
		int res = (sum_left - left_min) < (sum_right - right_min) ? (sum_left - left_min) : (sum_right - right_min);
		return res + 2 + sum;
	}
};

int main()
{
	Gloves g;
	vector<int> l = { 0,7,1,6 };
	vector<int> r = { 1,5,0,6 };
	cout << g.findMinimum(4, l, r) << endl;

	system("pause");
	return 0;
}