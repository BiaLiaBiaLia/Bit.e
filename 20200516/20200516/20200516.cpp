#include <iostream>
#include <map>
#include <vector>
using namespace std;

//����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map <int, int> m;

		for (int i = 0; i < nums.size(); ++i) {
			if (m.find(target - nums[i]) != m.end())
				return { m[target - nums[i]] , i };

			m[nums[i]] = i;
		}
		return {};
	}
};

int main()
{
	Solution s;
	vector<int> v = { 2,7,11,15 };
	vector<int> res(1);
	res = s.twoSum(v, 9);
	for (auto &e : res) {
		cout << e << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
