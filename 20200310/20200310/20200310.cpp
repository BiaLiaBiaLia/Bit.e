#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> GetList(string& str) {
	vector<int> res;
	int num = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == ',') {
			res.push_back(num);
			num = 0;
		}
		else
			num = num * 10 + (str[i] - '0');
	}
	res.push_back(num);
	return res;
}
int main() {
	string str;
	cin >> str;
	vector<int> nums = GetList(str);
	vector<int> res(nums.size(), 1);
	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i] > nums[i - 1])
			res[i] = res[i - 1] + 1;
	}
	for (int i = nums.size() - 2; i >= 0; i--) {
		if (nums[i] > nums[i + 1])
			res[i] = max(res[i], res[i + 1] + 1);
	}
	int cnt = 0;
	for (int i = 0; i < res.size(); ++i)
		cnt += res[i];
	cout << cnt << endl;

	system("pause");
	return 0;
}