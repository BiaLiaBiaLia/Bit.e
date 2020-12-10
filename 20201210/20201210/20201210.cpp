#include <bitset>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//��������������������һ�ĸ���
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
			if (left[i] * right[i] == 0) {//�κ���ɫֻҪ��һ��Ϊ0������Ҫ��ͬ����ɫ��ȫ����
				sum += left[i] + right[i];
			}
			else
			{
				//ͳ��������ĳ��ɫ�������ٵ����׸����Լ��������ߵ�����
				left_min = min(left[i], left_min);
				right_min = min(right[i], right_min);

				left_sum += left[i];
				right_sum += right[i];
			}
		}
		//�Ƚ���������(left,right)_sum��ֵ��ȡ��С��һ��+1����֤�ܸ������е���ɫ������һ������ȡһ���������ж�Ӧ��ɫ������
		//��Ҫ���˼���sum
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