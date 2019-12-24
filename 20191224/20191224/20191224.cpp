#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string LeftRotateString1(string str, int n) {  //不管左移多少位，str都是str+str的子串
		int len = str.size();
		if (0 == len)
			return "";
		n %= len;
		str += str;
		return str.substr(n, len);
	}

	string LeftRotateString2(string str, int n) {  
		int len = str.size();
		if (0 == len)
			return "";
		string res = str.substr(n, len - n) + str.substr(0, n);
		return res;
	}

	string LeftRotateString3(string str, int n) {  //剑指offer中,反转两次字符串
		int len = str.size();
		if (0 == len)
			return "";
		reverse(str.begin(), str.end());
		reverse(str.begin(), str.begin() + str.size() - n);
		reverse(str.begin() + str.size() - n, str.end());
		return str;
	}
};

void Printstr(string str) {
	for (auto &e : str)
		cout << e << " ";
	cout << endl;
}

int main()
{
	Solution s;
	string str = "abcXYZdef";
	int n;
	while (cin >> n) {
		string ret1 = s.LeftRotateString1(str, n);
		Printstr(ret1);

		string ret2 = s.LeftRotateString2(str, n);
		Printstr(ret2);

		string ret3 = s.LeftRotateString3(str, n);
		Printstr(ret3);
	}

	system("pause");
	return 0;
}