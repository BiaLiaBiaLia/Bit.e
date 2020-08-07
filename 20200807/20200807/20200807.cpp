#include <iostream>
#include <vector>
using namespace std;

//连续子数组的最大和
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int size = array.size();
		int sum = array[0];
		int cursum = 0;
		for (int i = 0; i < size; ++i)
		{
			cursum += array[i];
			if (cursum > sum)
				sum = cursum;
			if (cursum < 0)
				cursum = 0;

		}
		return sum;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 6,-3,-2,7,-15,1,2,2 };
	cout << s.FindGreatestSumOfSubArray(v) << endl;

	system("pause");
	return 0;
}