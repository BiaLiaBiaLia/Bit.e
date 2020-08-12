#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//ÆË¿ËÅÆË³×Ó
class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.empty())
			return false;
		sort(numbers.begin(), numbers.end());
		int length = numbers.size();
		int count = 0;
		for (int i = 0; i < length; i++) {
			if (numbers[i] == 0) {
				count++;
				continue;
			}
			if (i + 1 < length && numbers[i] == numbers[i + 1])
				return false;
		}
		return numbers.back() - numbers[count] < 5;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1,2,3,5,4 };
	cout << s.IsContinuous(v) << endl;

	system("pause");
	return 0;
}