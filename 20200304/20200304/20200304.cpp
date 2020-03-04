#include <iostream>
#include <string.h>
using namespace std;

//给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。
//如果可以构成，返回 true ；否则返回 false。

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int hash[26] = { 0 };
		for (int i = 0; magazine[i]; ++i) {
			hash[magazine[i] - 'a'] += 1;
		}
		for (int i = 0; ransomNote[i]; ++i) {
			hash[ransomNote[i] - 'a'] -= 1;
			if (hash[ransomNote[i] - 'a'] < 0)
				return false;
		}
		return true;
	}
};

int main()
{
	Solution s;
	string s1 = "aa";
	string s2 = "aab";
	
	cout << s.canConstruct(s1, s2) << endl;

	system("pause");
	return 0;
}