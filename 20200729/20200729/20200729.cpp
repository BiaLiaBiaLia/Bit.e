#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	static bool cmp(int x, int y) {
	//要保证找到x，y构成的序列中，让小的放在前面
	string xs = to_string(x);
	string ys = to_string(y);
	string A = xs;
	A += ys;
	string B = ys;
	B += xs;
	return A < B;
	}
	string PrintMinNumber(vector<int> numbers) {
		sort(numbers.begin(), numbers.end(), cmp);
		string result = "";
		for(unsigned int i = 0;
			i < numbers.size(); i++){
			result += to_string(numbers[i]);
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 3,32,321 };
	cout << s.PrintMinNumber(v) << endl;

	system("pause");
	return 0;
}