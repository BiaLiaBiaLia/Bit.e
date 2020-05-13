#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> v;
		int len = array.size();

		if (len < 2)
			return v;
		int left = 0, right = len - 1;

		while (left < right) {
			int acc = array[left] + array[right];

			if (acc == sum) {
				v.push_back(array[left]);
				v.push_back(array[right]);
				return v;
			}
			else {
				if (acc < sum)
					left++;
				else
					right--;
			}
		}
		return v;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21 };
	vector<int> res = s.FindNumbersWithSum(v, 30);
	for (auto& e : res) {
		cout << e << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}