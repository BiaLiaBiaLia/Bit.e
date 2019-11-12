#include <iostream>
#include <vector>
#include <string>
using namespace std;

//编程练习题：不要二
#if 0
int main()
{
	int W, H;
	cin >> W >> H;

	vector<vector<int>> vv;
	vv.resize(H);
	for (auto& e : vv)
		e.resize(W, 1);

	int count = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (1 == vv[i][j]) {
				++count;
				if (i + 2 < H)
					vv[i + 2][j] = 0;
				if (j + 2 < W)
					vv[i][j + 2] = 0;
			}
		}
	}

	cout << count << endl;

	system("pause");
	return 0;
}
#endif

class Solution {
public:
	int StrToInt(string str) {
		int result = 0;
		int overvalue = 0;
		int f = 1;
		char* ret = &str[0];
		while (*ret == ' ')
			++ret;
		while (*ret != '\0') {
			if (*ret == '+' || *ret == '-') {
				if (*ret == '+') {
					f = 1;
				}
				else {
					f = -1;
				}
				++ret;
			}
			if (*ret >= '0'&&*ret <= '9') {
				//判断是否越界超出int的范围
				//正数时（f == 1），*ret-'0' > 7 越界,负数时(f == -1),*ret-'0' > 8 越界
				overvalue = result * f - INT_MAX / 10 + (((f + 1) / 2 + *ret-'0' > 8) ? 1 : 0);
				if (overvalue > 0) {
					return 0;
				}
				result = result * 10 + (*ret - '0')*f;

				++ret;
			}
			else
				return 0;
		}

		return result;
	}
};

//class Solution {
//public:
//	int StrToInt(string str) {
//		const int length = str.length();
//		int isNegtive = 1, overValue = 0;
//		int digit = 0, value = 0;
//
//		if (length == 0) return 0;
//		else {
//			int idx = 0;
//			if (str[0] == '-') { isNegtive = -1; idx = 1; }
//			else if (str[0] == '+') { idx = 1; }
//
//			for (; idx < length; idx++) {
//				digit = str[idx] - '0';
//				// overValue表示本轮循环是否会越界
//				overValue = isNegtive * value - INT_MAX / 10
//					+ (((isNegtive + 1) / 2 + digit > 8) ? 1 : 0);
//
//				if (digit < 0 || digit>9) return 0;
//				else if (overValue > 0) return 0;
//
//				value = value * 10 + isNegtive * digit;
//			}
//			return value;
//		}
//	}
//};

int main()
{
	Solution s;
	string str = "+2147483647";

	cout << s.StrToInt(str) << endl;

	system("pause");
	return 0;
}