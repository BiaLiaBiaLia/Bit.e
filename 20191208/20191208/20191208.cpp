#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#if 0
class Solution {
public:
	/**
	 *	正数数组中的最小不可组成和
	 *	输入：正数数组arr
	 *	返回：正数数组中的最小不可组成和
	 */
	int getFirstUnFormedNum(vector<int> arr, int len) {
		vector<int> v;
		v.push_back(arr[0]);

		for (int i = 1; i < len; ++i) {
			int n = v.size();
			for (int j = 0; j < n; ++j) {
				v.push_back(v[j] + arr[i]);
			}
			v.push_back(arr[i]);
		}

		sort(v.begin(), v.end());
		if (1 == v.size())
			return v[0] + 1;
		for (int i = 1; i < v.size(); ++i) {
			if (v[i - 1] != v[i] && v[i - 1] + 1 != v[i])  //子集中有最小不可组成和
				return v[i - 1] + 1;
		}
		return v[v.size() - 1] + 1;  ///子集最大值+1
	}
};

int main()
{
	Solution s;
	vector<int> arr{ 3,2,4 };
	cout << s.getFirstUnFormedNum(arr, arr.size()) << endl;

	system("pause");
	return 0;
}
#endif

//找假币
int main()
{
	int n;
	while (cin >> n && n != 0) {
		int count = 1;
		if (1 == n)
			count = 0;
		else if (n == 2 || n == 3)
			count = 1;
		while (n > 3) {
			if (n % 3 == 0)
			{
				n /= 3;
			}
			else
			{
				n = n / 3 + 1;
			}
			++count;
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}