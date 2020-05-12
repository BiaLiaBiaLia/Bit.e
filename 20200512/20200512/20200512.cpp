#include <iostream>
#include <string>
using namespace std;

//第一个出现一次的字符
class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.size() == 0)
			return -1;

		char ch[256] = { 0 };

		for (int i = 0; i < str.size(); i++)
			ch[str[i]]++;

		for (int i = 0; i < str.size(); i++) {
			if (ch[str[i]] == 1)
				return i;
		}
		return 0;
	}
};

int main()
{
	Solution s;
	string st = "1234567894123456784";

	cout << s.FirstNotRepeatingChar(st) << endl;

	system("pause");
	return 0;
}