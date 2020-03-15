#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int solve(string s) {
		// write code here
		int res = -1, tmp = 0;
		for (auto c : s) {
			if (c < 'G') {
				if (isdigit(c))
					tmp = tmp * 16 + c - '0';
				else
					tmp = tmp * 16 + c - 'A' + 10;
			}
			else {
				res = (tmp > res) ? tmp : res;
				tmp = 0;
			}
		}
		return res;
	}
};

int main()
{
	string str = "012345BZ16";
	Solution s;
	int res = s.solve(str);
	cout << res << endl;

	system("pause");
	return 0;
}