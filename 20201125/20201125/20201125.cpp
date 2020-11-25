#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//字符串中找出连续最长的数字串
#if 0
int main()
{
	string str;
	string res;
	int i = 0;
	getline(cin, str);
	while (i < str.size()) {
		string tmp;
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
			while (i < str.size() && str[i] - '0' >= 0 && str[i] - '0' <= 9) {
				tmp += str[i];
				++i;
			}
			if (tmp.size() > res.size())
				res = tmp;
		}
		else
			++i;
	}
	cout << res << endl;

	system("pause");
	return 0;
}
#endif


//数组中超过一半的数字
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (0 == numbers.size())
			return 0;
		unordered_map<int, int> map;
		for (int i = 0; i < numbers.size(); ++i) {
			map[numbers[i]]++;
		}
		int mid = numbers.size() / 2;
		for (auto it = map.begin(); it != map.end();++it) {
			if (it->second > mid)
				return it->first;
		}
		return 0;
	}
};

int main()
{
	vector<int> nums = { 1,2,3,2,4,2,5,3,2 };
	Solution s;
	cout << s.MoreThanHalfNum_Solution(nums) << endl;

	system("pause");
	return 0;
}