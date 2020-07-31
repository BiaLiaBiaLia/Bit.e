#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void ReverseString(string &str, int start, int end) {
		while (start < end) {
			char temp = str[start];
			str[start] = str[end];
			str[end] = temp;
			start++, end--; }
	}
	string LeftRotateString(string str, int n) {
	if (n == 0 || str.empty()) {
		return str;
	}
	n %= str.size();
	//去除重复移动
	ReverseString(str, 0, n-1);
	//前半部分逆置
	ReverseString(str, n, str.size()-1);
	//后半部分逆置
	ReverseString(str, 0, str.size() - 1);
	//整体逆置
	return str;
	}
};

int main()
{
	Solution s;
	string str = "abcXYZdef";
	cout << s.LeftRotateString(str, 3) << endl;

	system("pause");
	return 0;
}