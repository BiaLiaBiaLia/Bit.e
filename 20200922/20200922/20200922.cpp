#include <iostream>
#include <vector>
#include <string>
using namespace std;

//有序数组中出现次数超过25%的元素
#if 0
class Solution {
public:
	int findSpecialInteger(vector<int>& arr) {
		int count = 1;
		int res = arr[0];
		int standard = arr.size() / 4;
		for (int i = 0; i < arr.size() - 1; ++i) {
			if (arr[i] != arr[i + 1]) {
				if (count > standard) {
					res = arr[i];
					break;
				}
				count = 1;
			}
			else {
				++count;
				res = arr[i];
			}
		}
		return res;
	}
};

int main()
{
	vector<int> arr = { 1,2,3,3 };
	Solution s;
	cout << s.findSpecialInteger(arr) << endl;

	system("pause");
	return 0;
}
#endif

#if 0
//最后一个单词的长度
class Solution {
public:
	int lengthOfLastWord(string s) {
		reverse(s.begin(), s.end());
		int res = 0;
		string::iterator it = s.begin();
		while (*it == ' ' && it != s.end())
			++it;
		while (*it != ' ' && it != s.end()) {
			++it;
			++res;
		}

		return res;
	}
};

int main()
{
	Solution s;
	string str = "Hello World";
	cout << s.lengthOfLastWord(str)<<endl;

	system("pause");
	return 0;
}
#endif


//求大于输入数的最小质数
class Solution {
public:
	bool isPrimeNumber(int& num) {
		if (num == 2 || num == 3)
			return true;
		//不在6倍数两侧的一定不是素数
		if (num % 6 != 1 && num % 6 != 5)
			return false;
		int temp = (int)sqrt(num);
		//在6的倍数的两侧的也不一定是质数
		for (int i = 5; i <= temp; i += 6) {
			if (num%i == 0 || num % (i + 2) == 0)
				return false;
		}
		return true;
	}

	int min_PrimeNumber(int& num) {
		while (!isPrimeNumber(num))
			++num;
		return num;
	}
};
int main()
{
	Solution s;
	int n;

	while (cin >> n) {
		int cur = n + 1;
		cout << s.min_PrimeNumber(cur) << endl;
}

	system("pause");
	return 0;
}