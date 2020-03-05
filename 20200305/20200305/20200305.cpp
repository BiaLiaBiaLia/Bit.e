#include <iostream>
#include <vector>
using namespace std;

//和为s的连续正数序列
class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) {
		vector<vector<int>> vec;
		int l, n;
		if (sum < 3) return vec;
		else {
			n = sqrt(2.0*sum);
			for (int k = n; k >= 2; k--) {
				if (2 * sum%k == 0) {
					l = 2 * sum / k;
					if (k % 2 != 0 && l % 2 == 0 || k % 2 == 0 && l % 2 != 0) {
						int an = (k + l - 1) / 2;
						int a1 = (l - k + 1) / 2;
						vector<int>temp;
						for (int a = a1; a <= an; a++) {
							temp.push_back(a);
						}
						vec.push_back(temp);
					}
				}
			}
		}
		return vec;
	}
};

int main()
{
	Solution s;
	s.FindContinuousSequence(100);

	system("pause");
	return 0;
}