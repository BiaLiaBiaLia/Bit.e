#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	 *
	 * @param n int整型 n个人
	 * @param a int整型vector ai代表第i个人的高度
	 * @return long长整型
	 */
	long long solve(int n, vector<int>& a) {
		// write code here
		vector<int> s(n, 0);
		long long ans = 0;
		int top = 0;
		s[0] = 0;
		for (int i = 1; i < n; i++) {
			while (top >= 0 && a[s[top]] <= a[i])
				top--;
			if (top >= 0)
				ans += s[top] + 1;
			s[++top] = i;
		}
		return ans;

	}
};

int main()
{
	Solution s;
	vector<int> v = { 1,2,3,4,5 };
	int n = v.size();
	cout << s.solve(n, v) << endl;

	system("pause");
	return 0;
}