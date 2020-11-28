#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//不要二
#if 0
int main()
{
	int H, W;
	while (cin >> W >> H) {
		vector<vector<int>> nums(H + 4, vector<int>(W + 4, 0));  //初始化二维数组，元素置0
		int count = 0;
		for (int i = 2; i < (H + 2); ++i) {
			for (int j = 2; j < (W + 2); ++j) {
				if (nums[i - 2][j] == 0
					&& nums[i + 2][j] == 0
					&& nums[i][j - 2] == 0
					&& nums[i][j + 2] == 0) {
					nums[i][j] = 1;
				    ++count;
				}

			}
		}
		cout << count << endl;
	}

	system("pause");
	return 0;
}
#endif


//将字符串转换为整数
class Solution {
public:
	int StrToInt(string str) {
		if (str.empty())
			return 0;
		int i = 0;
		int size = str.size();
		int flag = 1;
		int res = 0;
		while (i < size && str[i] == ' ')
			++i;
		if (i >= size)
			return 0;
		if (str[i] == '-') {
			flag = -1;
			++i;
		}
		if (str[i] == '+') {
			if (flag == -1)
				return 0;
			else
				++i;
		}
		for (int j = i; j < size; ++j) {
			if (str[j] >= '0' && str[j] <= '9')
				res = res * 10 + str[j] - '0';
			else
				return 0;
			}
		return flag * res;
	}
};

int main()
{
	Solution s;
	string str;
	while (getline(cin, str))
		cout << s.StrToInt(str) << endl;

	system("pause");
	return 0;
}