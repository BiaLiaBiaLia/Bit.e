#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	 * 返回最大山峰序列长度
	 * @param numberList int整型vector 给定的序列
	 * @return int整型
	 */
	int mountainSequence(vector<int>& numberList) {
		// write code here
		int n = numberList.size();
		if (n == 0)return 0;
		vector<int> dp1(n, 0), dp2(n, 0), dp;
		for (int i = 0; i < n; i++) {
			auto x = lower_bound(dp.begin(), dp.end(), numberList[i]);
			if (x == dp.end())dp.push_back(numberList[i]);
			else *x = numberList[i];
			dp1[i] = dp.size();
		}
		dp.clear();
		dp.resize(0);
		for (int i = n - 1; i >= 0; i--) {
			auto x = lower_bound(dp.begin(), dp.end(), numberList[i]);
			if (x == dp.end())dp.push_back(numberList[i]);
			else *x = numberList[i];
			dp2[i] = dp.size();
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			res = max(res, dp1[i] + dp2[i] - 1);
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1,2,3,6,1 };
	cout << s.mountainSequence(v) << endl;

	system("pause");
	return 0;
}