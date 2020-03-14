#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string change(string number) {
		// write code here
		int l = 0, r = number.size() - 1;
		while (l < r) {
			while (l < r) {
				int num = number[l] - '0';
				if (num % 2 == 0)
					break;
				l++;
			}
			while (l < r) {
				int num = number[r] - '0';
				if (num % 2 == 0)
					break;
				r--;
			}
			if (l != r) {
				char tmp = number[l];
				number[l] = number[r];
				number[r] = tmp;
				l++;
				r--;
			}
		}
		return number;
	}
};

int main()
{
	Solution s;
	string str = "123456";
	string res=s.change(str);
	cout << res << endl;

	system("pause");
	return 0;
}