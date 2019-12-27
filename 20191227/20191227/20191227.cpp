#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//最小的k个值
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		if (input.empty() || k > input.size())
			return res;
		sort(input.begin(), input.end());
		for (int i = 0; i < k; ++i) {
			res.push_back(input[i]);
		}
		return res;
	}
};

int main()
{
	vector<int> v{ 4,5,1,6,2,7,3,8 };
	Solution s;
	vector<int> vs = s.GetLeastNumbers_Solution(v, 4);
	for (auto &e : vs)
		cout << e << " ";
	cout << endl;

	system("pause");
	return 0;
}